//
// Created by adamenko on 19.03.2022.
//

#include <iostream>
#include "main_window.h"

MainWindow::MainWindow() :
    scene_(new QGraphicsScene(this)),
    view_(new QGraphicsView(this)),
    view_fox_(new QGraphicsView(this)),
    fox_left_(new QGraphicsScene(this)),
    fox_right_(new QGraphicsScene(this)),
    length_(new QSlider(Qt::Horizontal, this)),
    height_(new QSlider(Qt::Vertical, this)) {
  setFixedSize(815, 530);
  length_->setGeometry(0, 475, 760, 50);
  length_->setMaximum(100);
  length_->setMinimum(1);
  length_->setValue(50);

  height_->setGeometry(765, 0, 50, 475);
  height_->setMaximum(100);
  height_->setMinimum(1);
  height_->setValue(50);

  SetupScene();
  SetupFox();

  connect(length_, &QSlider::valueChanged, this, [&] {
    jump_length_ = length_->value() * 1.2;
  });

  connect(height_, &QSlider::valueChanged, this, [&] {
    jump_height_ = height_->value() * 2.0;
  });

  animation_timer_.start(2, this);
}

void MainWindow::SetupScene() {
  auto item = scene_->addPixmap(QPixmap(":field.jpg"));
  view_->setScene(scene_);
  view_->resize(765, 480);
}


void MainWindow::SetupFox() {
  auto item_right = fox_right_->addPixmap(QPixmap(":fox_right.png"));
  fox_width_ = static_cast<int>(item_right->boundingRect().width());
  view_fox_->setScene(fox_right_);
  view_fox_->setStyleSheet("background-color: transparent");
  view_fox_->resize(87, 151);
}

void MainWindow::timerEvent(QTimerEvent* event) {
  if (direction_ == right) {
    if (event->timerId() == animation_timer_.timerId()) {
      y_ = -abs(jump_height_ * sin(x_ / jump_length_));
      view_fox_->setGeometry(x_, 210 + y_, 87, 150);
      if (x_ + fox_width_ >= 765) {
        direction_ = left;
        auto item = fox_left_->addPixmap(QPixmap(":fox_left.png"));
        view_fox_->setScene(fox_left_);
        view_fox_->setStyleSheet("background-color: transparent");
        view_fox_->resize(87, 151);
        x_-= 0.5;
      } else {
        x_+= 0.5;
      }
      repaint();
    }
  } else {
    if (event->timerId() == animation_timer_.timerId()) {
      y_ = -abs(jump_height_ * sin(x_ / jump_length_));
      view_fox_->setGeometry(x_, 210 + y_, 87, 150);
      if (x_ <= 0) {
        direction_ = right;
        auto item = fox_right_->addPixmap(QPixmap(":fox_right.png"));
        view_fox_->setScene(fox_right_);
        view_fox_->setStyleSheet("background-color: transparent");
        view_fox_->resize(87, 151);
        x_+= 0.5;
      } else {
        x_-= 0.5;
      }
      repaint();
    }
  }
}