#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QSpinBox>
#include <QPushButton>
#include <QProgressBar>
#include <QKeyEvent>

class main_window : public QMainWindow{
  Q_OBJECT
 public:
  main_window();
  void update();

 private:
  QSpinBox* spin_box;
  QPushButton* button;
  QProgressBar* progress_bar;
};

#endif //MAIN_WINDOW_H
