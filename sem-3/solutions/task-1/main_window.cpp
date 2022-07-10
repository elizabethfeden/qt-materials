#include "main_window.h"

MainWindow::MainWindow() :
    scene_(new QGraphicsScene(this)),
    view_(new QGraphicsView(this)),
    field_(":field.jpg"),
    fox_(":fox.png"),
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
  scene_->addPixmap(field_);
  view_->setScene(scene_);
  view_->resize(765, 480);
}


void MainWindow::SetupFox() {
  fox_item_ = scene_->addPixmap(fox_);
  fox_item_->setPos(0, 210);
  fox_width_ = static_cast<int>(fox_item_->boundingRect().width());
}

void MainWindow::timerEvent(QTimerEvent* event) {
  if (event->timerId() == animation_timer_.timerId()) {
    y_ = -abs(jump_height_ * sin(x_ / jump_length_));
    fox_item_->setPos(x_, 210 + y_);
    if (direction_ == DirectionTypes::kRight && x_ + fox_width_ >= 760) {
      direction_ = DirectionTypes::kLeft;
      fox_item_->setPixmap(fox_.transformed(QTransform().scale(-1, 1)));
    } else if (direction_ == DirectionTypes::kLeft && x_ <= 0) {
      direction_ = DirectionTypes::kRight;
      fox_item_->setPixmap(fox_);
    }
    if (direction_ == DirectionTypes::kRight) {
      x_ += 0.5;
    } else {
      x_ -= 0.5;
    }
    repaint();
  }
}