#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPixmap>
#include <QMouseEvent>

#include "movable_item.h"

class MainWindow : public QMainWindow {
 Q_OBJECT

 public:
  MainWindow();
  void mousePressEvent(QMouseEvent *event) override;

 private:
  QGraphicsScene* scene_;
  QGraphicsView* view_;
};
