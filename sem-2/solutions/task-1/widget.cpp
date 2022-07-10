#include "widget.h"

Widget::Widget(QWidget* parent)
    : QWidget(parent) {
  button_ = new MouseTracking(this);
  button_->setText("Press me");

  button_->setStyleSheet("background-color: red;"
                         "border-style: outset;"
                         "border-width: 2px;"
                         "border-radius: 10px;"
                         "border-color: beige;"
                         "font: bold 14px;"
                         "min-width: 10em;"
                         "padding: 6px;");

  button_width_ = 200;
  button_height_ = 50;
  button_->setFixedSize(button_width_, button_height_);

  resize(340, 250);

  button_->move((Widget::width() - button_width_) / 2,
                (QWidget::height() - button_height_) / 2);

  connect(button_,
          SIGNAL(Mouse_In()),
          this,
          SLOT(Mouse_Detector_In()));

  connect(button_,
          &QPushButton::pressed,
          this,
          &Widget::ButtonPressEvent);
}

void Widget::Mouse_Detector_In() {
  button_->setGeometry(rand() % (Widget::width() - button_width_),
                       rand() % (Widget::height() - button_height_),
                       100,
                       30);
  // button_->setGeometry(10, 10, 200, 30);  // If you can't catch the button.
}

void Widget::ButtonPressEvent() {
  button_->setText("Are you winning son?");
  //button_->setStyleSheet("color: blue;" "background-color: yellow;");
  button_->setStyleSheet("color: blue;"
                         "background-color: yellow;"
                         "border-style: outset;"
                         "border-width: 2px;"
                         "border-radius: 10px;"
                         "border-color: beige;"
                         "font: bold 14px;"
                         "min-width: 10em;"
                         "padding: 6px;");
}

MouseTracking::MouseTracking(QWidget* parent) : QPushButton(parent) {
  this->setMouseTracking(true);
}

void MouseTracking::mouseMoveEvent(QMouseEvent* e) {
  emit Mouse_In();
}
