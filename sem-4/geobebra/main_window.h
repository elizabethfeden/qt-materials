#pragma once

#include <QComboBox>
#include <QGridLayout>
#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QListWidget>

#include "paint_widget.h"
#include "plot_descriptor_widget.h"

class MainWindow : public QMainWindow {
 Q_OBJECT
 public:
  MainWindow();
  void paintEvent(QPaintEvent* event) override;

 private:
  void ConnectWidgets();
  void UpdateChosenPlot(const std::vector<double>& parameters);
  void AddDefaultPlot();
  void ChooseNewItem(int item_index);
  void RemoveItem(int item_index);

  QWidget* widget_;
  QGridLayout* layout_;

  PlotDescriptorWidget* plot_descriptor_;

  QSize minimal_size_{585, 500};

  struct PlotInfo {
    std::vector<QPoint> points;
    QColor color;
  };

  std::vector<PlotInfo> plots_;

  PaintWidget* paint_widget_;
  QListWidget* list_widget_;

  QPushButton* add_plot_button_;
};
