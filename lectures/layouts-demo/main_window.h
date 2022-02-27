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

 private:
  void ManageLayout();

 private:
  QGridLayout* layout_;

  QWidget* widget_;

  QPushButton* hello_button_;
  QPushButton* bye_button_;
  QLabel* main_text_;

  QHBoxLayout* points_box_;
  QLabel* points_;
  QLabel* points_text_;

};


#endif  // MAIN_WINDOW_H
