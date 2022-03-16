#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    timer_(new QBasicTimer) {

    setWindowTitle("Flexing Cube");
    resize(1000, 800);
    timer_->start(15, this);

    for (int i : {0, 1, 2}) {
        auto& s = slider_[i];
        s = new QSlider(this);

        s->setRange(-100, +100);
        s->setGeometry(5, 5 + 25 * i, 200, 21);
        s->setOrientation(Qt::Orientation::Horizontal);

        connect(s, &QSlider::valueChanged, this, [&, i](int value) {
            coef_[i] = value / 100.;
        });
    }

    setStyleSheet(
        "QSlider::groove:horizontal {position: absolute; background: white; border: 1px solid darkgray}"
        "QSlider::handle:horizontal {background: #c100ff; width: 20px}"
        "QSlider::sub-page:horizontal {background: hotpink;}"
    );
}

void MainWindow::paintEvent(QPaintEvent*) {
    QPainter painter(this);
    paint_->Paint(&painter, Angle(0), Angle(1), Angle(2));
}

void MainWindow::timerEvent(QTimerEvent*) {
    constexpr double kPeriod = M_PI * 2;
    time_angle_ += .1;
    if (time_angle_ > kPeriod) {
        time_angle_ -= kPeriod;
    }
    time_sin_ = sin(time_angle_);
    repaint();
}

double MainWindow::Angle(int axis) {
    return sin(time_angle_) * coef_[axis];
}
