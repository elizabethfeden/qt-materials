#pragma once

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QColorDialog>
#include <QGridLayout>

class PlotDescriptorWidget : public QWidget {
  Q_OBJECT
 public:
  explicit PlotDescriptorWidget(QWidget* parent = nullptr);

  std::vector<double> GetParameters() const;

 signals:
  void EnteredNewPolynomial(const std::vector<double>& parameters);
  void ColorSelected(const QColor& color);

 private:
  void ConnectWidgets();
  void UpdatePolynomial(const std::vector<double>& parameters);

  QGridLayout* layout_;

  QLineEdit* line_edit_;
  QLabel* polynomial_;
  QColorDialog* color_dialog_;
};


