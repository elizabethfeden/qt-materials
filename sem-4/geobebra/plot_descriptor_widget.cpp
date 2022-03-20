#include <cmath>
#include "plot_descriptor_widget.h"

PlotDescriptorWidget::PlotDescriptorWidget(QWidget* parent) :
    line_edit_(new QLineEdit(this)),
    polynomial_(new QLabel(this)),
    color_dialog_(new QColorDialog(this)),
    layout_(new QGridLayout()) {
  layout_->addWidget(line_edit_, 0, 0);
  layout_->addWidget(color_dialog_, 0, 1);
  layout_->addWidget(polynomial_, 0, 2);
  layout_->setColumnStretch(0, 4);
  layout_->setColumnStretch(1, 1);
  layout_->setColumnStretch(2, 2);
  ConnectWidgets();
}

void PlotDescriptorWidget::ConnectWidgets() {
  connect(color_dialog_,
          &QColorDialog::colorSelected, [&](const QColor& color) {
        emit ColorSelected(color);
      });

  connect(line_edit_,
          &QLineEdit::editingFinished, [&]() {
        auto parameters = GetParameters();
        UpdatePolynomial(parameters);
        emit EnteredNewPolynomial(parameters);
      });
}

void PlotDescriptorWidget::UpdatePolynomial(
    const std::vector<double>& parameters) {
  QString res;
  int cur_deg = parameters.size() - 1;
  for (double parameter : parameters) {
    if (std::fabs(parameter) < 1e-5) {
      continue;
    }
    if (parameter > 0) {
      res += "+";
    }
    res += QString::number(parameter);
    if (cur_deg != 0) {
      res += "x^" + QString::number(cur_deg);
    }
  }
  polynomial_->setText(res);
}

std::vector<double> PlotDescriptorWidget::GetParameters() const {
  QStringList str_parameters = line_edit_->text().split(", ");
  std::vector<double> parameters;
  for (const auto& str_parameter : str_parameters) {
    parameters.push_back(str_parameter.toDouble());
  }
  return parameters;
}
