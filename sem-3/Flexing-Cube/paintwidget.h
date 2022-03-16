#ifndef PAINTWIDGET_H
#define PAINTWIDGET_H

#include <QGenericMatrix>
#include <QWidget>

class PaintWidget : public QWidget {
    Q_OBJECT
public:
    explicit PaintWidget(QWidget *parent = nullptr);

    void Paint(QPainter*, double angle_x, double angle_y, double angle_z);

signals:

};

#endif  // PAINTWIDGET_H
