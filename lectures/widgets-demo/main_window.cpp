#include "main_window.h"

MainWindow::MainWindow() :
    QMainWindow(nullptr),
    text_(new QLabel("kek", this)),
    button_(new QPushButton("Press me!", this)),
    combo_box_(new QComboBox(this)),
    edit_(new QLineEdit(this)) {
  resize(500, 500);
  setMinimumSize(300, 300);

  for (auto name : {"Alex", "Bob", "Clark", "Derek"}) {
    combo_box_->addItem(name);
  }

//  PlaceWidgets();
//  ConnectWidgets();
}

void MainWindow::PlaceWidgets() {
  int i = 0;
  for (QWidget* widget : std::initializer_list<QWidget*>{text_, button_, combo_box_, edit_}) {
    widget->setGeometry(10, 100 * i++, 100, 50);
  }
}

void MainWindow::ConnectWidgets() {
  connect(combo_box_, &QComboBox::currentIndexChanged, this, [&] {
    text_->setText(combo_box_->currentText());
  });
  connect(button_, &QPushButton::pressed, this, [&] {
    edit_->setVisible(!edit_->isVisible());
  });
}

//void MainWindow::keyPressEvent(QKeyEvent* event) {
//  if (event->key() == Qt::Key_Escape) {
//    close();
//  } else if (event->key() == Qt::Key_F) {
//    text_->setText(text_->text() + "E");
//  } else if (event->text().toLower() == "ё") {
//    text_->setText("Ё");
//  }
//}
