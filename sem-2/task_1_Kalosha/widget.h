#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>

class MouseTracking : public QPushButton {
 Q_OBJECT
 public:
  explicit MouseTracking(QWidget* parent = nullptr);

  void mouseMoveEvent(QMouseEvent* e) override;

 signals:
  void Mouse_In();
};

class Widget : public QWidget {
 Q_OBJECT
 public:
  explicit Widget(QWidget* parent = nullptr);



 private:

  QPushButton* button_ = nullptr;
  int button_width_;
  int button_height_;

 private slots:
  void Mouse_Detector_In();
  void ButtonPressEvent();
};

#endif // WIDGET_H
