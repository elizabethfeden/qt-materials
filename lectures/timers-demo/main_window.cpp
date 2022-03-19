#include "main_window.h"

MainWindow::MainWindow() :
    QMainWindow(nullptr),
    layout_(new QGridLayout()),
    widget_(new QWidget(this)),
    timer1_(new QTimer(this)) {
  for (int i = 0; i < 3; i++) {
    timer_buttons_.push_back(
        new QPushButton("Start/Stop Timer " + QString::number(i + 1), widget_));
    timer_labels_.push_back(new QLabel("0", widget_));
    layout_->addWidget(timer_buttons_[i], 0, i);
    layout_->addWidget(timer_labels_[i], 1, i, Qt::AlignCenter);
    timer_buttons_[i]->setSizePolicy(QSizePolicy::Expanding,
                                     QSizePolicy::Expanding);
  }
  layout_->setRowStretch(0, 1);
  layout_->setRowStretch(1, 1);

  resize(600, 400);
  widget_->setLayout(layout_);
  setCentralWidget(widget_);

  ConnectTimers();
}

void MainWindow::IncrementTimer(int timer_index) {
  ++counters_[timer_index];
  timer_labels_[timer_index]->setText(QString::number(counters_[timer_index]));
}

void MainWindow::ConnectTimers() {
  // Timer 1
  connect(timer_buttons_[0], &QPushButton::clicked, this, [&] {
    if (timer1_->isActive()) {
      timer1_->stop();
    } else {
      timer1_->start(1000);
    }
  });
  // Timer 1's timeout is also a signal
  connect(timer1_, &QTimer::timeout, this, [&] {
    IncrementTimer(0);
  });

  // Timer 2
  connect(timer_buttons_[1], &QPushButton::clicked, this, [&] {
    if (is_timer2_active_) {
      killTimer(timer2_);
      is_timer2_active_ = false;
    } else {
      timer2_ = startTimer(1000);
      is_timer2_active_ = true;
    }
  });

  // Timer 3
  connect(timer_buttons_[2], &QPushButton::clicked, this, [&] {
    if (timer3_.isActive()) {
      timer3_.stop();
    } else {
      // Passing object whose timerEvent
      // should handle the timeout to the constructor
      timer3_.start(1000, this);
    }
  });
}

void MainWindow::timerEvent(QTimerEvent* event) {
  if (event->timerId() == timer2_) {
    IncrementTimer(1);
  } else if (event->timerId() == timer3_.timerId()) {
    IncrementTimer(2);
  }
}
