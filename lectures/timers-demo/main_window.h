#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QTimer>
#include <QTimerEvent>
#include <QBasicTimer>

class MainWindow : public QMainWindow {
  Q_OBJECT
 public:
  MainWindow();

  // For timers 2 and 3
  void timerEvent(QTimerEvent* event) override;

 private:
  void ConnectTimers();
  void IncrementTimer(int timer_index);

 private:
  QGridLayout* layout_;
  QWidget* widget_;

  std::vector<QPushButton*> timer_buttons_;
  std::vector<QLabel*> timer_labels_;
  std::vector<int> counters_ = {0, 0, 0};

  QTimer* timer1_;

  int timer2_;
  bool is_timer2_active_{false};

  QBasicTimer timer3_; // <- not a pointer!

};


#endif  // MAIN_WINDOW_H
