#include "mainwindow.h"

MainWindow::MainWindow()
    : QMainWindow(nullptr),
      main_widget_(new QWidget(this)),
      grid_(new QGridLayout()),
      spin_box_(new QSpinBox(main_widget_)),
      button_(new QPushButton("Clicc", main_widget_)),
      reset_(new QPushButton("Reset", main_widget_)),
      progress_bar_(new QProgressBar(main_widget_)) {
    resize(900, 700);
    setMinimumSize(200, 100);
    setWindowTitle("The Clicker we deserve!");
    spin_box_->setRange(0, 100);

    ManageLayout();
    ConnectWidgets();
}

void MainWindow::ManageLayout() {
    QSizePolicy policy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    grid_->addWidget(progress_bar_, 0, 0);
    grid_->addWidget(spin_box_, 1, 0);
    grid_->addWidget(button_, 1, 1);
    grid_->addWidget(reset_, 0, 1);
    main_widget_->setLayout(grid_);

    spin_box_->setSizePolicy(policy);
    button_->setSizePolicy(policy);

    setCentralWidget(main_widget_);
}

void MainWindow::ConnectWidgets() {
    static double current_progress = progress_bar_->minimum();
    connect(button_, &QPushButton::pressed, this, [&] {
        double to_add = progress_bar_->maximum() / (double)spin_box_->value();
        current_progress = std::min<double>(progress_bar_->maximum(), current_progress + to_add);
        progress_bar_->setValue(ceil(current_progress));

        spin_box_->setEnabled(false);
    });
    connect(reset_, &QPushButton::pressed, this, [&] {
        progress_bar_->setValue(progress_bar_->minimum());
        spin_box_->setEnabled(true);
        current_progress = progress_bar_->minimum();
    });
}
