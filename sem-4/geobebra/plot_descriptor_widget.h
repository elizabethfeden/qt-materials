#pragma once

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>

class PlotDescriptorWidget : public QWidget {
  Q_OBJECT
 public:
  explicit PlotDescriptorWidget(QWidget* parent = nullptr);

  std::vector<double> GetParameters() const;
  static QString GetPolynomialString(const std::vector<double>& parameters);

  void Update(const QString& polynomial_string, const QColor& color);

 signals:
  void EnteredNewPolynomial(const std::vector<double>& parameters);
  void ColorSelected(const QColor& color);

 private:
  void ConnectWidgets();
  void PaintColorChangeButton(const QColor& color);

  QGridLayout* layout_;

  QLineEdit* line_edit_;
  QLabel* polynomial_;
  QPushButton* color_change_button_;
};


