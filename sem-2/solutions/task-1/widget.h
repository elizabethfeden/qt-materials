#ifndef WIDGET_H
#define WIDGET_H

#include <QMainWindow>
#include <QPushButton>
#include <QWidget>

class MouseTrackingButton : public QPushButton {
 Q_OBJECT
 public:
  explicit MouseTrackingButton(QWidget* parent = nullptr,
                               const QString& name = "");
  void mouseMoveEvent(QMouseEvent* event) override;

 signals:
  void MouseDetected();
};

class MainWindow : public QMainWindow {
 Q_OBJECT
 public:
  explicit MainWindow(QWidget* parent = nullptr);

 private:
  MouseTrackingButton* button_;
  int button_width_;
  int button_height_;

  void OnMouseDetected();
  void OnButtonPressed();
};

#endif // WIDGET_H
