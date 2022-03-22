#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <memory>

#include <QMainWindow>
#include <QComboBox>
#include <QPushButton>
#include <QListWidget>
#include <QGridLayout>

#include "abstract_controller.h"

class MainWindow : public QMainWindow {
  Q_OBJECT
 public:
  explicit MainWindow(AbstractController* controller);

 private:
 public:
  QListWidget* GetList() const;
  QComboBox* GetOptions() const;
 private:
  AbstractController* controller_;

  QGridLayout* layout_;
  QWidget* central_widget_;
  QListWidget* list_;
  QComboBox* options_;
  QPushButton* add_;
  QPushButton* remove_;


};


#endif  // MAIN_WINDOW_H
