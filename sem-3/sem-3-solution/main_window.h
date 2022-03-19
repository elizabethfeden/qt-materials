#ifndef MAIN_WINDOW_H_
#define MAIN_WINDOW_H_

#include <QMainWindow>
#include <QLabel>
#include <QPaintEvent>
#include <QPixmap>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QPushButton>
#include <vector>

#include "painters.h"

class MainWindow : public QMainWindow {
  Q_OBJECT
 public:
  MainWindow();
  void paintEvent(QPaintEvent*);

 private:
  void ConnectWidgets();
  void SetupSceneWinner();
  void SetupSceneLooser();
  void Reset();

 private:
  static std::vector<QString> difficult_words_;

 private:
  QString word_;
  PaintHuman* human_widget_;
  PaintWord* word_widget_;
  QLineEdit* letter_;
  QLabel* used_letters_;
  QLabel* left_attempts_;
  int attempts_{5};
  std::vector<QChar> entered_letters_{' '};
  int current_word_{0};

  QGraphicsScene* scene_;
  QGraphicsView* view_;
  QPushButton* try_again_;
};

#endif  // MAIN_WINDOW_H_
