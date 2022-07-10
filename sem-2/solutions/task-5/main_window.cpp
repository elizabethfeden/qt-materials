#include "main_window.h"

main_window::main_window() {
  spin_box = new QSpinBox(this);
  button = new QPushButton(this);
  progress_bar = new QProgressBar(this);

  spin_box->setMinimum(0);
  spin_box->setMaximum(100);
  spin_box->show();
  spin_box->resize(100, 100);

  button->show();
  button->setGeometry(200, 200, 400, 400);

  progress_bar->setGeometry(300, 0, 200, 40);
  progress_bar->setValue(0);
  progress_bar->show();

  resize(1000, 1000);

  connect(button, &QPushButton::released, this, &main_window::update);
}

void main_window::update() {
  spin_box->setReadOnly(true);
  progress_bar->setMaximum(spin_box->value());
  int tech = progress_bar->value() + 1;
  progress_bar->setValue(tech);
}
