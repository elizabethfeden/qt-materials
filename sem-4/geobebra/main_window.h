#pragma once

#include <QComboBox>
#include <QGridLayout>
#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>

#include "paint_widget.h"
#include "plot_descriptor_widget.h"

class MainWindow : public QMainWindow {
 Q_OBJECT
 public:
  MainWindow();
  void paintEvent(QPaintEvent* event) override;

 private:
  void ConnectWidgets();
  void UpdatePlot(const std::vector<double>& parameters);

  QWidget* widget_;
  QGridLayout* layout_;

  PlotDescriptorWidget* plot_descriptor_;

  QSize minimal_size_{500, 500};

  struct PlotInfo {
    std::vector<QPoint> points;
    QColor color;
  };

  PlotInfo plot_;

  PaintWidget* paint_widget_;
};

