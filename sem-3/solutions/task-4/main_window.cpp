#include <iostream>
#include <QDrag>
#include "main_window.h"
#include "constants.cpp"

int z_value;

MainWindow::MainWindow() :
    scene_(new QGraphicsScene(this)),
    view_(new QGraphicsView(this)) {
  view_->setScene(scene_);
  view_->setGeometry(0, 0, kDefaultWindowWidth, kDefaultWindowHeight);
  setGeometry(100, 100, kDefaultWindowWidth, kDefaultWindowHeight);
  auto item = scene_->addPixmap(QPixmap(":garderob.jpg"));
  item->setZValue(z_value++);
  QGraphicsItem* hero_item = nullptr;
  auto hero_ = new MovableItem(QPixmap(":mujik.png"), hero_item, view_);
  scene_->addItem(hero_);
  hero_->setZValue(z_value++);
  hero_->setPos(200, 70);
  hero_->setAcceptDrops(true);

  auto shoes1 = new MovableItem(QPixmap(":shoes1.png"), hero_item, view_);
  scene_->addItem(shoes1);
  shoes1->setZValue(z_value++);
  shoes1->setPos(500, 550);
  shoes1->setAcceptDrops(true);

  auto shoes2 = new MovableItem(QPixmap(":shoes2.png"), hero_item, view_);
  scene_->addItem(shoes2);
  shoes2->setZValue(z_value++);
  shoes2->setPos(600, 650);
  shoes2->setAcceptDrops(true);

  auto sweater1 = new MovableItem(QPixmap(":sweater1.png"), hero_item, view_);
  scene_->addItem(sweater1);
  sweater1->setZValue(z_value++);
  sweater1->setPos(600, 100);
  sweater1->setAcceptDrops(true);

  auto sweater2 = new MovableItem(QPixmap(":sweater2.png"), hero_item, view_);
  scene_->addItem(sweater2);
  sweater2->setZValue(z_value++);
  sweater2->setPos(680, 100);
  sweater2->setAcceptDrops(true);

  auto sweater3 = new MovableItem(QPixmap(":sweater3.png"), hero_item, view_);
  scene_->addItem(sweater3);
  sweater3->setZValue(z_value++);
  sweater3->setPos(760, 100);
  sweater3->setAcceptDrops(true);

  auto sweater4 = new MovableItem(QPixmap(":sweater4.png"), hero_item, view_);
  scene_->addItem(sweater4);
  sweater4->setZValue(z_value++);
  sweater4->setPos(840, 100);
  sweater4->setAcceptDrops(true);

  auto sweater5 = new MovableItem(QPixmap(":sweater5.png"), hero_item, view_);
  scene_->addItem(sweater5);
  sweater5->setZValue(z_value++);
  sweater5->setPos(600, 300);
  sweater5->setAcceptDrops(true);

  auto sweater6 = new MovableItem(QPixmap(":sweater6.png"), hero_item, view_);
  scene_->addItem(sweater6);
  sweater6->setZValue(z_value++);
  sweater6->setPos(680, 300);
  sweater6->setAcceptDrops(true);

  auto sweater7 = new MovableItem(QPixmap(":sweater7.png"), hero_item, view_);
  scene_->addItem(sweater7);
  sweater7->setZValue(z_value++);
  sweater7->setPos(760, 300);
  sweater7->setAcceptDrops(true);

  auto sweater8 = new MovableItem(QPixmap(":sweater8.png"), hero_item, view_);
  scene_->addItem(sweater8);
  sweater8->setZValue(z_value++);
  sweater8->setPos(840, 100);
  sweater8->setAcceptDrops(true);

  auto sweater9 = new MovableItem(QPixmap(":sweater9.png"), hero_item, view_);
  scene_->addItem(sweater9);
  sweater9->setZValue(z_value++);
  sweater9->setPos(860, 200);
  sweater9->setAcceptDrops(true);

  auto pants1 = new MovableItem(QPixmap(":pants1.png"), hero_item, view_);
  scene_->addItem(pants1);
  pants1->setZValue(z_value++);
  pants1->setPos(600, 370);
  pants1->setAcceptDrops(true);

  auto pants2 = new MovableItem(QPixmap(":pants2.png"), hero_item, view_);
  scene_->addItem(pants2);
  pants2->setZValue(z_value++);
  pants2->setPos(800, 370);
  pants2->setAcceptDrops(true);

  auto watches1 = new MovableItem(QPixmap(":watches1.png"), hero_item, view_);
  scene_->addItem(watches1);
  watches1->setZValue(z_value++);
  watches1->setPos(400, 50);
  watches1->setAcceptDrops(true);

  auto watches2 = new MovableItem(QPixmap(":watches2.png"), hero_item, view_);
  scene_->addItem(watches2);
  watches2->setZValue(z_value++);
  watches2->setPos(420, 50);
  watches2->setAcceptDrops(true);

  auto watches3 = new MovableItem(QPixmap(":watches3.png"), hero_item, view_);
  scene_->addItem(watches3);
  watches3->setZValue(z_value++);
  watches3->setPos(440, 50);
  watches3->setAcceptDrops(true);

  auto watches4 = new MovableItem(QPixmap(":watches4.png"), hero_item, view_);
  scene_->addItem(watches4);
  watches4->setZValue(z_value++);
  watches4->setPos(460, 50);
  watches4->setAcceptDrops(true);

  auto watches5 = new MovableItem(QPixmap(":watches5.png"), hero_item, view_);
  scene_->addItem(watches5);
  watches5->setZValue(z_value++);
  watches5->setPos(480, 50);
  watches5->setAcceptDrops(true);
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
  if (event->button() == Qt::LeftButton) {

    QDrag* drag = new QDrag(this);
    QMimeData* mimeData = new QMimeData;

    mimeData->setText("clothes");
    drag->setMimeData(mimeData);

    Qt::DropAction dropAction = drag->exec();
  }
}