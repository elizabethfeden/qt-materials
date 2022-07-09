#pragma once

#include <QGraphicsPixmapItem>
#include <QMouseEvent>
#include <QWidget>
#include <QMimeData>
#include <QDrag>
#include <QObject>
#include <QGraphicsSceneDragDropEvent>
#include <QGraphicsScene>
#include <QMainWindow>
#include <QGraphicsView>

class MovableItem : public QGraphicsPixmapItem {
 public:
  explicit MovableItem(const QPixmap& pixmap, QGraphicsItem* parent,
                       QGraphicsView* view);
  void dragEnterEvent(QGraphicsSceneDragDropEvent* event) override;
  void dragMoveEvent(QGraphicsSceneDragDropEvent* event) override;

 private:
  QGraphicsView* view_;
  QPointF drag_pos_;
  QPointF cursor_pos_;
};