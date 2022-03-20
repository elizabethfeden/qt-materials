#include "paint_widget.h"

#include <QPainterPath>

PaintWidget::PaintWidget(QWidget* parent) : QWidget(parent) {}

void PaintWidget::Paint(
    QPainter* painter,
    const QColor& plot_color,
    const std::vector<QPoint>& points) {
  painter->save();
  painter->setPen(plot_color);
  QPainterPath path;
  path.moveTo(points.front());
  for (const auto& point : points) {
    path.lineTo(point);
  }

  painter->translate(QWidget::width() / 2, QWidget::height() / 2);

  painter->drawPath(path);

  QPainterPath axis_path;
  axis_path.moveTo(0, -QWidget::height() / 2);
  axis_path.lineTo(0, QWidget::height() / 2);
  axis_path.moveTo(-QWidget::width() / 2, 0);
  axis_path.lineTo(QWidget::width() / 2, 0);

  QColor axis_color = Qt::black;
  painter->setPen(axis_color);
  painter->drawPath(axis_path);

  painter->restore();
}


