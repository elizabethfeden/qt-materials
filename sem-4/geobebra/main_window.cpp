#include <iostream>
#include "main_window.h"

MainWindow::MainWindow()
    : widget_(new QWidget(this)),
      layout_(new QGridLayout()),
      paint_widget_(new PaintWidget(widget_)),
      plot_descriptor_(new PlotDescriptorWidget(widget_)) {
  resize(minimal_size_);
  setMinimumSize(minimal_size_);

  ConnectWidgets();

  layout_->setRowStretch(0, 10);
  layout_->setRowStretch(1, 1);

  layout_->addWidget(paint_widget_, 0, 0);
  layout_->addWidget(plot_descriptor_, 1, 0);

  widget_->setLayout(layout_);

  setCentralWidget(widget_);
}

void MainWindow::paintEvent(QPaintEvent* event) {
  QWidget::paintEvent(event);
  QPainter painter(this);

  UpdatePlot(plot_descriptor_->GetParameters());
  paint_widget_->Paint(&painter, plot_.color, plot_.points);
}

void MainWindow::ConnectWidgets() {
  connect(plot_descriptor_,
          &PlotDescriptorWidget::ColorSelected, [&](const QColor& color) {
        plot_.color = color;
        repaint();
      });

  connect(plot_descriptor_,
          &PlotDescriptorWidget::EnteredNewPolynomial,
          [&](const std::vector<double>& parameters) {
            UpdatePlot(parameters);
            repaint();
          });
}

void MainWindow::UpdatePlot(
    const std::vector<double>& parameters) {
  int width = paint_widget_->width();
  int height = paint_widget_->height();

  auto& cur_plot = plot_.points;

  cur_plot.clear();
  cur_plot.reserve(width);

  for (int x = -width / 2; x < width / 2; ++x) {
    double y = 0;
    for (double cur_parameter : parameters) {
      y *= x;
      y += cur_parameter;
    }
    if (y > -height / 2 && y < height / 2) {
      cur_plot.emplace_back(x, static_cast<int>(-y));
    }
  }
}
