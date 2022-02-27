#include "main_window.h"

MainWindow::MainWindow() :
    QMainWindow(nullptr),
    layout_(new QGridLayout()),
    widget_(new QWidget(this)),
    hello_button_(new QPushButton("Hi", widget_)),
    bye_button_(new QPushButton("Bye", widget_)),
    main_text_(new QLabel("I am main text.", widget_)),
    points_box_(new QHBoxLayout()),
    points_(new QLabel("0", widget_)),
    points_text_(new QLabel(" points", widget_)) {

  resize(400, 400);

  // Error: Attempting to set QLayout "" on MainWindow "", which already has a layout
  // setLayout(layout_);

  ManageLayout();
}

void MainWindow::ManageLayout() {
  // Adding two widgets to QHBoxLayout
  points_box_->addWidget(points_text_);
  points_box_->addWidget(points_);

  // Adding widgets and layouts to QGridLayout
  layout_->addWidget(main_text_, 0, 1, Qt::AlignCenter);
  layout_->addLayout(points_box_, 0, 2, Qt::AlignTop | Qt::AlignRight);
  // ! Note: Adding alignment breaks size policies :(
  layout_->addWidget(hello_button_, 1, 1 /*, Qt::AlignRight */);
  layout_->addWidget(bye_button_, 2, 1);

  // Make buttons take up all available space in a cell
  QSizePolicy policy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  hello_button_->setSizePolicy(policy);
  bye_button_->setSizePolicy(policy);

  // Define proportion of widget that each row/column takes up
  // proportion = column_stretch / sum(column_stretch for all columns) * 100%
  layout_->setColumnStretch(0, 1);
  layout_->setColumnStretch(1, 2);
  layout_->setColumnStretch(2, 1);

  layout_->setRowStretch(0, 2);
  layout_->setRowStretch(1, 1);
  layout_->setRowStretch(2, 1);

  widget_->setLayout(layout_);
  setCentralWidget(widget_);
}