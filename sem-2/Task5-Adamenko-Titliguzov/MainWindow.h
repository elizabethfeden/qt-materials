#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSpinBox>
#include <QPushButton>
#include <QProgressBar>
#include <QKeyEvent>

class MainWindow : public QMainWindow {
 Q_OBJECT
 public:
  MainWindow();
  void Update();

 private:
  QSpinBox* spin_box_;
  QPushButton* button_;
  QProgressBar* progress_bar_;
};

#endif //MAINWINDOW_H
