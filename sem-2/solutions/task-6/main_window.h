#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>
#include <QLineEdit>
#include <QKeyEvent>

class MainWindow : public QMainWindow {
 Q_OBJECT
 public:
  MainWindow();

  void resizeEvent(QResizeEvent* event) override;

 private:
  void PlaceWidgets(const QSize& window_size);
  void PlaceButton();
  void ConnectWidgets();

 private:
  static const int kSliderThickness;
  static const int kButtonHeight;
  static const int kButtonWidth;
  static const QSize kDefaultWindowSize;
  QPushButton* button_;
  QSlider* vertical_slider;
  QSlider* horizontal_slider;
};


#endif  // MAIN_WINDOW_H
