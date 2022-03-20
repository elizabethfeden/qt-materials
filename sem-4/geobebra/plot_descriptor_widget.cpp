#include <cmath>
#include <QColorDialog>
#include "plot_descriptor_widget.h"

PlotDescriptorWidget::PlotDescriptorWidget(QWidget* parent) :
    line_edit_(new QLineEdit(this)),
    polynomial_(new QLabel(this)),
    color_change_button_(new QPushButton(this)),
    layout_(new QGridLayout()) {
  color_change_button_->setText("Set color");

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
          emit ColorSelected(color);
        }
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
  polynomial_->setText("y = " + res);
}

std::vector<double> PlotDescriptorWidget::GetParameters() const {
  QStringList str_parameters = line_edit_->text().split(", ");
  std::vector<double> parameters;
  for (const auto& str_parameter : str_parameters) {
    parameters.push_back(str_parameter.toDouble());
  }
  return parameters;
}