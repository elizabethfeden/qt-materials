#include "widget.h"

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    button_(new MouseTrackingButton(this, "Press me")),
    button_width_(200),
    button_height_(50) {
  button_->setStyleSheet("background-color: red;"
                         "border-style: outset;"
                         "border-width: 2px;"
                         "border-radius: 10px;"
                         "border-color: beige;"
                         "font: bold 14px;"
                         "min-width: 10em;"
                         "padding: 6px;");
  button_->setFixedSize(button_width_, button_height_);
  button_->move((MainWindow::width() - button_width_) / 2,
                (QWidget::height() - button_height_) / 2);

  resize(340, 250);

  connect(button_,
          &MouseTrackingButton::MouseDetected,
          this,
          &MainWindow::OnMouseDetected);

  connect(button_,
          &QPushButton::pressed,
          this,
          &MainWindow::OnButtonPressed);
}

void MainWindow::OnMouseDetected() {
  button_->move(rand() % (MainWindow::width() - button_width_),
                rand() % (MainWindow::height() - button_height_));
  // button_->setGeometry(10, 10, 200, 30);  // If you can't catch the button.
}

void MainWindow::OnButtonPressed() {
  button_->setText("Are you winning son?");
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

MouseTrackingButton::MouseTrackingButton(QWidget* parent, const QString& name)
    : QPushButton(name, parent) {
  setMouseTracking(true);
}

void MouseTrackingButton::mouseMoveEvent(QMouseEvent* event) {
  emit MouseDetected();
}
