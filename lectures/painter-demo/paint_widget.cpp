#include "paint_widget.h"

void PaintWidget::Paint(QPainter* painter) const {
  painter->save();

  QBrush brush(Qt::yellow);
  brush.setStyle(Qt::BrushStyle::CrossPattern);
  painter->setBrush(brush);
  painter->drawRect(0, 0, 500, 500);

//  painter->translate(250, 250);
//  painter->rotate(current_rotate_);

  painter->setBrush(QColor(current_red_, 0, 0));
  painter->drawEllipse(100, 125, 300, 250);
//  painter->drawEllipse(-150, -100, 300, 250);

  painter->restore();
}

PaintWidget::PaintWidget(QWidget* parent) : QWidget(parent) {}

void PaintWidget::Tick() {
  current_red_ = (current_red_ + 1) % 255;
  current_rotate_ = (current_rotate_ + 1) % 360;
}
