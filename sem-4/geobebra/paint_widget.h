#pragma once

#include <QWidget>
#include <QPainter>

class PaintWidget : public QWidget {
  Q_OBJECT
 public:
  explicit PaintWidget(QWidget* parent);

  void Paint(QPainter* painter, const std::vector<QPoint>& points);
};


