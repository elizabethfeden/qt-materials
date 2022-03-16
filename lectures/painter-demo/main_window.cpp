#include "main_window.h"

MainWindow::MainWindow() :
    QMainWindow(nullptr),
    widget_(new PaintWidget(this)),
    scene_(new QGraphicsScene(this)),
    view_(new QGraphicsView(this)) {
  resize(1000, 500);
  widget_->setGeometry(0, 0, 500, 500);
  view_->setGeometry(500, 0, 1000, 500);

//  SetupScene();

  animation_timer_.start(50, this);
}

void MainWindow::timerEvent(QTimerEvent* event) {
  if (event->timerId() == animation_timer_.timerId()) {
    widget_->Tick();

    // Tick GraphicsView
//    scene_->setSceneRect(view_position_, 0, 500 + view_position_, 500);
//    view_position_ = (view_position_ + 5) % image_width_;

    repaint();
  }
}

void MainWindow::paintEvent(QPaintEvent*) {
  QPainter painter(this);
  widget_->Paint(&painter);
}

void MainWindow::SetupScene() {
  auto item = scene_->addPixmap(QPixmap(":kitty.jpg"));
  image_width_ = static_cast<int>(item->boundingRect().width()) - 500;
  view_->setScene(scene_);
//  view_->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//  view_->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  view_->resize(500, 500);
}
