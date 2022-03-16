#ifndef PAINT_WIDGET_H
#define PAINT_WIDGET_H

#include <QWidget>
#include <QPainter>

class PaintWidget : public QWidget {
  Q_OBJECT
 public:
  explicit PaintWidget(QWidget* parent);
  void Paint(QPainter* painter) const;
  void Tick();

 private:
  int current_red_ = 0;
  int current_rotate_ = 0;
};


#endif //PAINT_WIDGET_H
