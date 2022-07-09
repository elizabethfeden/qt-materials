#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGridLayout>
#include <QMainWindow>
#include <QProgressBar>
#include <QPushButton>
#include <QSpinBox>

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow();

private:
    void ManageLayout();
    void ConnectWidgets();

    QWidget* main_widget_;

    QGridLayout* grid_;

    QSpinBox* spin_box_;
    QPushButton* button_;
    QPushButton* reset_;
    QProgressBar* progress_bar_;

signals:

};

#endif  // MAINWINDOW_H
