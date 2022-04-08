#pragma once

#include <QWidget>
#include <QPainter>

class PaintWidget : public QWidget {
  Q_OBJECT
 public:
  explicit PaintWidget(QWidget* parent = nullptr);

  void DrawBackground(QPainter* painter);
  void DrawPlot(
      QPainter* painter,
      const QColor& plot_color,
      const std::vector<QPoint>& points);
};


