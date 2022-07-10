#include "MainWindow.h"

MainWindow::MainWindow() :
    spin_box_(new QSpinBox(this)),
    button_(new QPushButton(this)),
    progress_bar_(new QProgressBar(this)) {

  spin_box_->setMinimum(0);
  spin_box_->setMaximum(100);
  spin_box_->resize(100, 100);

  button_->setGeometry(200, 200, 400, 400);

  progress_bar_->setGeometry(300, 0, 200, 40);
  progress_bar_->setValue(0);

  resize(1000, 1000);

  connect(button_, &QPushButton::released, this, &MainWindow::Update);
}

void MainWindow::Update() {
  spin_box_->setReadOnly(true);
  progress_bar_->setMaximum(spin_box_->value());
  int tech = progress_bar_->value() + 1;
  progress_bar_->setValue(tech);
}
