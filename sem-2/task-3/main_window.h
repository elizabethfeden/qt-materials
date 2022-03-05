#pragma once

#include <QCheckBox>
#include <QComboBox>
#include <QGridLayout>
#include <QKeyEvent>
#include <QLabel>
#include <QLineEdit>
#include <QMainWindow>
#include <QPushButton>
#include <vector>

class MainWindow : public QMainWindow {
  Q_OBJECT
 public:
  MainWindow();

 private:
  const int kSize = 5;

  void CreateWidgets();
  void ConnectWidgets();

  QGridLayout* layout_;

  QWidget* widget_;

  QSize minimal_size_{300, 300};

  std::vector<QPushButton*> buttons_;
  std::vector<QCheckBox*> check_boxes_;
};
