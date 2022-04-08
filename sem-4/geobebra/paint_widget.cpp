#include "paint_widget.h"

#include <QPainterPath>

PaintWidget::PaintWidget(QWidget* parent) : QWidget(parent) {}

void PaintWidget::Paint(
    QPainter* painter,
    const QColor& plot_color,
    const std::vector<QPoint>& points) {
  painter->save();

  painter->setBrush(Qt::white);
  painter->drawRect(geometry());
  painter->setBrush(Qt::NoBrush);

  QPoint new_center = QPoint(QWidget::width() / 2 , QWidget::height() / 2) +
      pos();
  painter->translate(new_center);

  QPainterPath axis_path;
  axis_path.moveTo(0, -QWidget::height() / 2);
  axis_path.lineTo(0, QWidget::height() / 2);
  axis_path.moveTo(-QWidget::width() / 2, 0);
  axis_path.lineTo(QWidget::width() / 2, 0);

  QColor axis_color;
  painter->setPen(axis_color);
  painter->drawPath(axis_path);

  double plot_thickness = 2;
  painter->setPen({plot_color, plot_thickness});
  QPainterPath path;
  path.moveTo(points.front());
  for (const auto& point : points) {
    path.lineTo(point);
  }
  painter->drawPath(path);

  painter->translate(-new_center);
  painter->setPen({axis_color, 2 * plot_thickness});
  painter->drawRect(geometry());

  painter->restore();
}


