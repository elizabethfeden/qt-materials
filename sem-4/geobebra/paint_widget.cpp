#include "paint_widget.h"

#include <QPainterPath>

PaintWidget::PaintWidget(QWidget* parent) : QWidget(parent) {}


void PaintWidget::Paint(QPainter* painter, const std::vector<QPoint>& points) {
  painter->save();
  QBrush brush;
  painter->setBrush(brush);
  QPainterPath path;
  path.moveTo(points.front());
  for (const auto& point : points) {
    path.lineTo(point);
  }
  painter->drawPath(path);

  painter->restore();
}


