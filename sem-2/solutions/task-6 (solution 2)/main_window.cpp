#include "main_window.h"

MainWindow::MainWindow() :
    QMainWindow(nullptr),
    layout_(new QGridLayout()),
    widget_(new QWidget(this)),
    vertical_slider_(new QSlider(Qt::Vertical, widget_)),
    horizontal_slider_(new QSlider(Qt::Horizontal, widget_)),
    move_button_(new QPushButton("Move me", widget_)) {
  resize(400, 400);
  ManageLayout();
}

void MainWindow::ManageLayout() {
  layout_->addWidget(vertical_slider_, 1, 1);
  layout_->addWidget(horizontal_slider_, 2, 2);

  layout_->addWidget(move_button_, 1, 2, Qt::AlignBottom | Qt::AlignLeft);

  connect(vertical_slider_, &QAbstractSlider::sliderMoved, move_button_, [&] {
    MoveButton();
  });
  connect(horizontal_slider_, &QAbstractSlider::sliderMoved, move_button_, [&] {
    MoveButton();
  });

  layout_->setColumnStretch(0, 1);
  layout_->setColumnStretch(1, 1);
  layout_->setColumnStretch(2, 20);
  layout_->setColumnStretch(3, 5);

  layout_->setRowStretch(0, 1);
  layout_->setRowStretch(1, 20);
  layout_->setRowStretch(2, 1);
  layout_->setRowStretch(3, 1);

  widget_->setLayout(layout_);
  setCentralWidget(widget_);
}

void MainWindow::MoveButton() {
  int new_x = horizontal_slider_->pos().x() +
              (horizontal_slider_->width() *
               (horizontal_slider_->sliderPosition()) / 100);

  int new_y = vertical_slider_->pos().y() + vertical_slider_->height() -
              (vertical_slider_->height() *
               (vertical_slider_->sliderPosition()) / 100) -
              (horizontal_slider_->height() * 12 / 10);

  move_button_->move(new_x, new_y);
}

void MainWindow::resizeEvent(QResizeEvent* event) {
  MoveButton();
}