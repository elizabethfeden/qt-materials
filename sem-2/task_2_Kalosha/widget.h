#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QLabel>
#include <vector>

class Widget : public QWidget {
 Q_OBJECT
 public:
  explicit Widget(QWidget* parent = nullptr);

  void mousePressEvent(QMouseEvent* e) override;
  void keyPressEvent(QKeyEvent* e) override;

 private:
  std::vector<QLabel*> labels_;

};

#endif // WIDGET_H
