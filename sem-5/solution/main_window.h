#pragma once

#include <QSettings>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QAction>
#include <QMenuBar>
#include <QMainWindow>

class MainWindow : public QMainWindow {
  Q_OBJECT
 public:
  MainWindow(QSettings*);

 private:
  QVBoxLayout* layout_;
  QWidget* main_widget_;
  QPushButton* button_;
  QPushButton* button2_;
  QLabel* text_;
  QLabel* text2_;
  QAction* deutsch_lang_;
  QAction* belarusian_lang_;
  QAction* english_lang_;
  QMenuBar* menu_bar_;

  QSettings* settings_;
};
