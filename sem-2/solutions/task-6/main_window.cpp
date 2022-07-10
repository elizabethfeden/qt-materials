#include "main_window.h"

const int MainWindow::kSliderThickness = 10;
const int MainWindow::kButtonHeight = 50;
const int MainWindow::kButtonWidth = 100;
const QSize MainWindow::kDefaultWindowSize(500, 500);

MainWindow::MainWindow() :
    QMainWindow(nullptr),
    button_(new QPushButton("Press me!", this)),
    vertical_slider(new QSlider(Qt::Vertical, this)),
    horizontal_slider(new QSlider(Qt::Horizontal, this)) {
  vertical_slider->setRange(0, QWidget::height() - kSliderThickness);
  vertical_slider->setRange(0, QWidget::width() - kSliderThickness);
  vertical_slider->setValue(vertical_slider->maximum());
  button_->resize(kButtonWidth, kButtonHeight);
  resize(kDefaultWindowSize);
  setMinimumSize(
      kSliderThickness + kButtonWidth,
      kSliderThickness + kButtonHeight);

  PlaceWidgets(size());
  ConnectWidgets();
}

void MainWindow::PlaceWidgets(const QSize& window_size) {
  PlaceButton();
  horizontal_slider->setGeometry(
      kSliderThickness, window_size.height() - kSliderThickness,
      window_size.width() - kSliderThickness, kSliderThickness);
  vertical_slider->setGeometry(
      0, 0,
      kSliderThickness, window_size.height() - kSliderThickness);
}

void MainWindow::PlaceButton() {
  int height_range = QWidget::height() - button_->height() - kSliderThickness;
  int y = height_range * (vertical_slider->maximum() - vertical_slider->value())
          / (vertical_slider->maximum() - vertical_slider->minimum());
  button_->setGeometry(button_->x(), y, button_->width(), button_->height());
  int width_range = QWidget::width() - button_->width() - kSliderThickness;
  int x = width_range * horizontal_slider->value()
          / (horizontal_slider->maximum() - horizontal_slider->minimum())
          + kSliderThickness;
  button_->setGeometry(x, y, button_->width(), button_->height());
}

void MainWindow::ConnectWidgets() {
  connect(
      vertical_slider,
      &QSlider::valueChanged,
      this,
      &MainWindow::PlaceButton);
  connect(
      horizontal_slider,
      &QSlider::valueChanged,
      this,
      &MainWindow::PlaceButton);
}

void MainWindow::resizeEvent(QResizeEvent* event) {
  PlaceWidgets(event->size());
}
