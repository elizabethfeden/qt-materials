#ifndef PAINTWIDGET_H
#define PAINTWIDGET_H

#include <QGenericMatrix>
#include <QWidget>

class PaintWidget : public QWidget {
    Q_OBJECT
public:
    explicit PaintWidget(QWidget *parent = nullptr);

    void Paint(QPainter*, double* angles);

signals:

};

#endif  // PAINTWIDGET_H
