#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>
#include <QLineEdit>
#include <QKeyEvent>
#include <QGridLayout>

class MainWindow : public QMainWindow {
  Q_OBJECT
 public:
  MainWindow();
  void resizeEvent(QResizeEvent* event) override;

 private:
  void ManageLayout();
  void MoveButton();

 private:
  QGridLayout* layout_;

  QWidget* widget_;

  QSlider* vertical_slider_;
  QSlider* horizontal_slider_;
  QPushButton* move_button_;
};


#endif  // MAIN_WINDOW_H