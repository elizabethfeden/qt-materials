#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QBasicTimer>
#include <QTimerEvent>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QSlider>

enum class DirectionTypes {
  kLeft,
  kRight,
};

class MainWindow : public QMainWindow{
  Q_OBJECT
 public:
  MainWindow();
  void SetupScene();
  void SetupFox();

  void timerEvent(QTimerEvent* event) override;

 private:
  QGraphicsScene* scene_;
  QGraphicsView* view_;
  QPixmap fox_;
  QGraphicsPixmapItem* fox_item_;
  QPixmap field_;
  QSlider* length_;
  QSlider* height_;

  double jump_length_{60};
  double jump_height_{100};
  int fox_width_{0};
  double x_{0}, y_{0};
  DirectionTypes direction_{DirectionTypes::kRight};

  QBasicTimer animation_timer_;
};

#endif //MAIN_WINDOW_H