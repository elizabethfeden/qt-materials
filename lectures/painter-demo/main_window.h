#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QBasicTimer>
#include <QTimerEvent>
#include <QScrollBar>
#include <QGraphicsPixmapItem>

#include "paint_widget.h"

class MainWindow : public QMainWindow {
  Q_OBJECT
 public:
  MainWindow();
  void timerEvent(QTimerEvent* event) override;
  void paintEvent(QPaintEvent*) override;

 private:
  void SetupScene();

 private:
  PaintWidget* widget_;

  QGraphicsScene* scene_;
  QGraphicsView* view_;
  int view_position_ = 0;
  int image_width_;

  QBasicTimer animation_timer_;

};


#endif  // MAIN_WINDOW_H
