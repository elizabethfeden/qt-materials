#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QContextMenuEvent>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QMessageBox>
#include <QLabel>
#include <QStatusBar>

class MainWindow : public QMainWindow {
  Q_OBJECT
 public:
  MainWindow();

#ifndef QT_NO_CONTEXTMENU
  void contextMenuEvent(QContextMenuEvent* event) override;
#endif // QT_NO_CONTEXTMENU

 private:
  void CreateMenu();
  void ShowDialog();

 private:
  bool show_context_menu_{false};

  QMenu* some_menu;

};


#endif  // MAIN_WINDOW_H
