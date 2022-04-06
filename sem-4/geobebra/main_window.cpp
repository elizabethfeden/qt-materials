#include <iostream>
#include "main_window.h"

MainWindow::MainWindow()
    : widget_(new QWidget(this)),
      layout_(new QGridLayout()),
      paint_widget_(new PaintWidget(widget_)),
      plot_descriptor_(new PlotDescriptorWidget(widget_)),
      add_plot_button_(new QPushButton(widget_)),
      list_widget_(new QListWidget(widget_)) {
  resize(minimal_size_);
  setMinimumSize(minimal_size_);

  add_plot_button_->setText("Add new plot");

  ConnectWidgets();

  layout_->setRowStretch(0, 10);
  layout_->setRowStretch(1, 1);

  layout_->setColumnStretch(0, 3);
  layout_->setColumnStretch(1, 10);

  layout_->addWidget(list_widget_, 0, 0);
  layout_->addWidget(add_plot_button_, 1, 0);
  layout_->addWidget(paint_widget_, 0, 1);
  layout_->addWidget(plot_descriptor_, 1, 1);

  widget_->setLayout(layout_);

  setCentralWidget(widget_);
}

void MainWindow::paintEvent(QPaintEvent* event) {
  QWidget::paintEvent(event);
  QPainter painter(this);

  if (plots_.empty()) {
    AddDefaultPlot();
  }

  for (const auto& plot : plots_) {
    paint_widget_->Paint(&painter, plot.color, plot.points);
  }
}

void MainWindow::ConnectWidgets() {
  connect(plot_descriptor_,
          &PlotDescriptorWidget::ColorSelected, [&](const QColor& color) {
        plots_[list_widget_->currentRow()].color = color;
        repaint();
      });

  connect(plot_descriptor_,
          &PlotDescriptorWidget::EnteredNewPolynomial,
          [&](const std::vector<double>& parameters) {
            auto polynomial_string =
                PlotDescriptorWidget::GetPolynomialString(parameters);
            list_widget_->currentItem()->setText(polynomial_string);
            UpdateChosenPlot(parameters);
            repaint();
          });

  connect(add_plot_button_,
          &QPushButton::clicked,
          [&]() {
            AddDefaultPlot();
          });

  connect(list_widget_,
          &QListWidget::itemClicked, [&](QListWidgetItem*) {
        ChooseNewItem(list_widget_->currentRow());
      });
}

void MainWindow::UpdateChosenPlot(
    const std::vector<double>& parameters) {
  int width = paint_widget_->width();
  int height = paint_widget_->height();

  auto& cur_plot = plots_[list_widget_->currentRow()].points;

  cur_plot.clear();
  cur_plot.reserve(width);

  const double kStep = 0.01;
  for (double x = -width / 2; x < width / 2; x += kStep) {
    double y = 0;
    for (double cur_parameter : parameters) {
      y *= x;
      y += cur_parameter;
    }
    if (y > -height / 2 && y < height / 2) {
      cur_plot.emplace_back(x, -y);
    }
  }
}

void MainWindow::AddDefaultPlot() {
  static std::vector<double> default_parameters = {0};
  list_widget_->addItem(
      PlotDescriptorWidget::GetPolynomialString(default_parameters));
  list_widget_->setCurrentRow(plots_.size());
  plots_.push_back({});
  UpdateChosenPlot(default_parameters);
  ChooseNewItem(list_widget_->currentRow());
}

void MainWindow::ChooseNewItem(int item_index) {
  plot_descriptor_->Update(list_widget_->currentItem()->text(),
                           plots_[item_index].color);
}
