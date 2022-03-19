#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QLabel>

class MainWindow : public QMainWindow {
  // Necessary macro!!!
  // Enables Qt Meta-Object System for this class
  Q_OBJECT
 public:
  MainWindow();

 private:
  QLabel* text_;

};


#endif  // MAIN_WINDOW_H
