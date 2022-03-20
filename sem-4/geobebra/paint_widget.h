#pragma once

#include <QWidget>
#include <QPainter>

class PaintWidget : public QWidget {
  Q_OBJECT
 public:
  explicit PaintWidget(QWidget* parent = nullptr);

  void Paint(
      QPainter* painter,
      const QBrush& plot_brush,
      const std::vector<QPoint>& points);
};


