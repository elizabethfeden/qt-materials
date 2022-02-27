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

//  void keyPressEvent(QKeyEvent* event) override;

 private:
  void PlaceWidgets();
  void ConnectWidgets();

 private:
  QLabel* text_;
  QPushButton* button_;
  QComboBox* combo_box_;
  QLineEdit* edit_;

};


#endif  // MAIN_WINDOW_H
