
#include "main_window.h"

MainWindow::MainWindow() :
    QMainWindow(nullptr) {

  resize(400, 400);

  statusBar()->addPermanentWidget(new QLabel("Hi :)"));
  statusBar()->setVisible(false);

  CreateMenu();
}

void MainWindow::CreateMenu() {
  // Manage menuBar
  auto* menu = menuBar()->addMenu("Some Menu");
  auto* exit_action = menuBar()->addAction("Exit");

  // Manage exit action
  connect(exit_action, &QAction::triggered, this, &QMainWindow::close);
  exit_action->setShortcut(QKeySequence::Close);

  // Manage menu
  auto* show_status_bar_action = menu->addAction("Show status bar");
  show_status_bar_action->setCheckable(true);
  connect(show_status_bar_action, &QAction::triggered, this,
          [&, show_status_bar_action] {
            statusBar()->setVisible(show_status_bar_action->isChecked());
            statusBar()->showMessage("Can you see me?");
          });
  auto* show_context_menu_action = menu->addAction("Show context menu");
  show_context_menu_action->setCheckable(true);
  connect(show_context_menu_action, &QAction::triggered, this,
          [&, show_context_menu_action] {
            show_context_menu_ = show_context_menu_action->isChecked();
          });

//  menu->addSeparator();

  // Menu in menu
  some_menu = menu->addMenu("There is something here");
  auto* show_dialog_action = some_menu->addAction("Show dialog");
  connect(show_dialog_action, &QAction::triggered, this,
          &MainWindow::ShowDialog);
}

#ifndef QT_NO_CONTEXTMENU

void MainWindow::contextMenuEvent(QContextMenuEvent* event) {
  if (show_context_menu_) {
    some_menu->exec(event->globalPos());
  }
}

#endif // QT_NO_CONTEXTMENU

void MainWindow::ShowDialog() {
  auto answer = QMessageBox::question(this, "Question",
                                      "Do you like pizza with pineapples?");
  statusBar()->showMessage(answer == QMessageBox::Yes ? "Yes" : "No");
}
