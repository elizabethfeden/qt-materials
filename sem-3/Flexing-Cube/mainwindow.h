#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QBasicTimer>
#include <QMainWindow>
#include <QPainter>
#include <QSlider>
#include "paintwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent*) override;

    void timerEvent(QTimerEvent*) override;

private:
    double Angle(int axis);

    PaintWidget *paint_;
    QBasicTimer* timer_;
    QSlider* slider_[3];

    double time_angle_{};
    double time_sin_{};
    double coef_[3];
};

#endif  // MAINWINDOW_H
