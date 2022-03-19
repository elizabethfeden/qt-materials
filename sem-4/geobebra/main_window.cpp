#include "main_window.h"

MainWindow::MainWindow()
    : widget_(new QWidget(this)),
    layout_(new QGridLayout()),
    paint_widget_(new PaintWidget(widget_)),
    line_edit_(new QLineEdit(widget_)) {
  line_edit_->setText("1");
  RefreshCurPlot();

  ConnectWidgets();

  layout_->addWidget(paint_widget_, 0, 0);
  layout_->addWidget(line_edit_, 0, 1);

  widget_->setLayout(layout_);

  setCentralWidget(widget_);
}

void MainWindow::paintEvent(QPaintEvent* event) {
  QWidget::paintEvent(event);
  QPainter painter(this);

  paint_widget_->Paint(&painter, cur_plot_);
}

void MainWindow::ConnectWidgets() {
  connect(line_edit_,
          &QLineEdit::editingFinished, [&]() {
            RefreshCurPlot();
          });
}

void MainWindow::RefreshCurPlot() {
  QStringList str_parameters = line_edit_->text().split(", ");
  std::vector<double> parameters;
  for (const auto& str_parameter : str_parameters) {
    parameters.push_back(str_parameter.toDouble());
  }
  cur_plot_.resize(paint_widget_->width());
  for (int x = 0; x < paint_widget_->width(); ++x) {
    double y = 0;
    for (double cur_parameter : parameters) {
      y += cur_parameter;
      y *= x;
    }
    cur_plot_[x] = {x, static_cast<int>(y)};
  }
}
