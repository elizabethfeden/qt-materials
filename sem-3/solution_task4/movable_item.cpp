#include "movable_item.h"

#include <QCursor>

#include "constants.cpp"

extern int z_value;

MovableItem::MovableItem(
    const QPixmap& pixmap,
    QGraphicsItem* parent, QGraphicsView* view)
    : QGraphicsPixmapItem(pixmap, parent) ,
    view_(view) {
}

void MovableItem::dragMoveEvent(QGraphicsSceneDragDropEvent* event) {
  QPointF res = (view_->mapToScene(QCursor::pos())) -
      view_->mapToGlobal(view_->pos());
  res = drag_pos_ + (res - cursor_pos_);
  if (res.x() < 0) {
    res.setX(0);
  }
  if (res.y() < 0) {
    res.setY(0);
  }
  if (res.x() + this->pixmap().width() >= kDefaultWindowWidth - 30) {
    res.setX(kDefaultWindowWidth - this->pixmap().width() - 30);
  }
  if (res.y() + this->pixmap().height() >= kDefaultWindowHeight - 30) {
    res.setY(kDefaultWindowHeight - this->pixmap().height() - 30);
  }
  this->setPos(res.x(), res.y());
}

void MovableItem::dragEnterEvent(QGraphicsSceneDragDropEvent* event) {
  cursor_pos_ = (view_->mapToScene(QCursor::pos())) -
      view_->mapToGlobal(view_->pos());
  drag_pos_ = this->pos();
  this->setZValue(z_value++);
}


