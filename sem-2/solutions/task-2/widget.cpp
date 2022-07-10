#include "widget.h"

Widget::Widget(QWidget* parent)
    : QWidget(parent) {
  resize(340, 250);
}

void Widget::mousePressEvent(QMouseEvent* event) {
  labels_.push_back(new QLabel("click", this));
  labels_[labels_.size() - 1]->setFixedSize(35, 15);
  labels_[labels_.size() - 1]->move(event->pos());
  labels_[labels_.size() - 1]->setVisible(true);
}

void Widget::keyPressEvent(QKeyEvent* event) {
  if (event->key() == Qt::Key::Key_Space) {
    for (int i = 0; i < labels_.size(); ++i) {
      labels_[i]->setText("oops!");
    }
  }
}
