#pragma once

#include <QComboBox>
#include <QGridLayout>
#include <QMainWindow>
#include <QLineEdit>

#include "paint_widget.h"

class MainWindow : public QMainWindow {
  Q_OBJECT
 public:
  MainWindow();
  void paintEvent(QPaintEvent* event) override;

 private:
  void ConnectWidgets();
  void RefreshCurPlot();

  QWidget* widget_;
  QGridLayout* layout_;
  QLineEdit* line_edit_;

  std::vector<QPoint> cur_plot_;

  PaintWidget* paint_widget_;
};


