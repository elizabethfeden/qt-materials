#include "main_window.h"

MainWindow::MainWindow() :
    // MainWindow doesn't have a parent
    QMainWindow(nullptr),
    // text_ is a child of MainWindow
    text_(new QLabel("kek", this)) {
  // Some window manipulation methods
  resize(500, 500);
//  setMinimumSize(300, 300);
//  setWindowTitle("Hi Mark");
//  text_->setGeometry(50, 50, 100, 100);
}
