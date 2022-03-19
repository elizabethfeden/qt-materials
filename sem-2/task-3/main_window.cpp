#include "main_window.h"

MainWindow::MainWindow() :
    QMainWindow(nullptr),
    layout_(new QGridLayout()),
    widget_(new QWidget(this)) {
  resize(minimal_size_);
  setMinimumSize(minimal_size_);

  CreateWidgets();

  QSizePolicy policy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  for (int i = 0; i < kSize; ++i) {
    buttons_[i]->setSizePolicy(policy);
    check_boxes_[i]->setSizePolicy(policy);
  }

  widget_->setLayout(layout_);
  setCentralWidget(widget_);
  ConnectWidgets();
}

void MainWindow::ConnectWidgets() {
  for (int i = 0; i < kSize; ++i) {
    connect(check_boxes_[i], &QCheckBox::stateChanged, this, [=] {
      buttons_[i]->setVisible(!buttons_[i]->isVisible());
    });
  }
}

void MainWindow::CreateWidgets() {
  for (int i = 0; i < kSize; ++i) {
    buttons_.push_back(new QPushButton(std::to_string(i).c_str(), widget_));
    check_boxes_.push_back(new QCheckBox(std::to_string(i).c_str(), widget_));
    layout_->addWidget(check_boxes_[i], i, 0, 1, 1);
    layout_->addWidget(buttons_[i], i, 1, 1, 1);
  }
}
