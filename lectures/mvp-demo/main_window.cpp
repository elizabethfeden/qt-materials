#include "main_window.h"

MainWindow::MainWindow(AbstractController* controller) :
    QMainWindow(nullptr),
    controller_(controller),
    layout_(new QGridLayout()),
    central_widget_(new QWidget(this)),
    list_(new QListWidget(central_widget_)),
    options_(new QComboBox(central_widget_)),
    add_(new QPushButton("Add!", central_widget_)),
    remove_(new QPushButton("Remove First", central_widget_)) {
  for (auto option : {"French Fries", "Cheeseburger", "Coca Cola"}) {
    options_->addItem(option);
  }

  layout_->addWidget(list_, 0, 0, 4, 1);
  layout_->addWidget(options_, 1, 2);
  layout_->addWidget(add_, 1, 3);
  layout_->addWidget(remove_, 2, 1, 1, 2);

  central_widget_->setLayout(layout_);
  setCentralWidget(central_widget_);

  connect(add_, &QPushButton::clicked, this, [&] {
    controller_->AddItem();
  });
  connect(remove_, &QPushButton::clicked, this, [&] {
    controller_->RemoveItem();
  });
}

QListWidget* MainWindow::GetList() const {
  return list_;
}

QComboBox* MainWindow::GetOptions() const {
  return options_;
}
