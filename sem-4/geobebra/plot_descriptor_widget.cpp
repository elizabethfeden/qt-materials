#include <cmath>
#include <QColorDialog>
#include <QPalette>
#include "plot_descriptor_widget.h"

PlotDescriptorWidget::PlotDescriptorWidget(QWidget* parent) :
    line_edit_(new QLineEdit(this)),
    polynomial_(new QLabel(this)),
    color_change_button_(new QPushButton(this)),
    layout_(new QGridLayout()) {
  color_change_button_->setText("Set color");

  QPalette palette;
  palette.setColor(QPalette::Button, Qt::black);
  color_change_button_->setPalette(palette);
  palette.setColor(QPalette::ButtonText, Qt::white);
  color_change_button_->setPalette(palette);
  layout_->addWidget(line_edit_, 0, 0);
  layout_->addWidget(color_change_button_, 0, 1);
  layout_->addWidget(polynomial_, 0, 2);
  layout_->setColumnStretch(0, 4);
  layout_->setColumnStretch(1, 1);
  layout_->setColumnStretch(2, 2);
  ConnectWidgets();
  setLayout(layout_);
}

void PlotDescriptorWidget::ConnectWidgets() {
  connect(color_change_button_,
          &QPushButton::clicked, [&]() {
        QColor color = QColorDialog::getColor(Qt::black, this);
        if (color.isValid()) {
          PaintColorChangeButton(color);
          emit ColorSelected(color);
        }
      });

  connect(line_edit_,
          &QLineEdit::editingFinished, [&]() {
        auto parameters = GetParameters();
        polynomial_->setText(GetPolynomialString(parameters));
        emit EnteredNewPolynomial(parameters);
      });
}

QString PlotDescriptorWidget::GetPolynomialString(
    const std::vector<double>& parameters) {
  QString res;
  int cur_deg = parameters.size() - 1;
  for (double parameter : parameters) {
    if (std::fabs(parameter) < 1e-5) {
      --cur_deg;
      continue;
    }
    if (!res.isEmpty() && parameter > 0) {
      res += "+";
    }
    if (std::fabs(parameter - 1) > 1e-5 || cur_deg == 0) {
      res += QString::number(parameter);
    }
    if (cur_deg > 1) {
      res += "x^" + QString::number(cur_deg);
    } else if (cur_deg == 1) {
      res += "x";
    }
    --cur_deg;
  }
  if (res.isEmpty()) {
    res = "0";
  }
  return "y = " + res;
}

std::vector<double> PlotDescriptorWidget::GetParameters() const {
  QStringList str_parameters = line_edit_->text().split(", ");
  std::vector<double> parameters;
  for (const auto& str_parameter : str_parameters) {
    parameters.push_back(str_parameter.toDouble());
  }
  return parameters;
}

void PlotDescriptorWidget::Update(
    const QString& polynomial_string,
    const QColor& color) {
  line_edit_->setText("");
  polynomial_->setText(polynomial_string);
  PaintColorChangeButton(color);
}

void PlotDescriptorWidget::PaintColorChangeButton(const QColor& color) {
  QPalette palette;
  palette.setColor(QPalette::Button, color);
  color_change_button_->setPalette(palette);
  QColor inverted_color;
  inverted_color.setRed(255 - color.red());
  inverted_color.setGreen(255 - color.green());
  inverted_color.setBlue(255 - color.blue());
  palette.setColor(QPalette::ButtonText, inverted_color);
  color_change_button_->setPalette(palette);
}
