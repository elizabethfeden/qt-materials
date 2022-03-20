#include "paint_widget.h"

#include <QPainterPath>

PaintWidget::PaintWidget(QWidget* parent) : QWidget(parent) {}

void PaintWidget::Paint(
    QPainter* painter,
    const QBrush& plot_brush,
    const std::vector<QPoint>& points) {
  painter->save();
  painter->setBrush(plot_brush);
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

  QBrush axis_brush;
  painter->setBrush(axis_brush);
  painter->drawPath(axis_path);

  painter->restore();
}


