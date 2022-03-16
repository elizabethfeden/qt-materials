#include "paintwidget.h"

#include <QMatrix3x3>
#include <QVector2D>
#include <QPainter>
#include <QPoint>
#include <QColor>

#include <cmath>
#include <iostream>

PaintWidget::PaintWidget(QWidget *parent)
    : QWidget{parent} {}

QVector2D Project(const QVector3D& vector);
void rotateRoundAxis(QVector<QVector3D>& points, double angle, int axis);

void PaintWidget::Paint(QPainter* painter,
                        double angle_x, double angle_y, double angle_z) {

    painter->fillRect(painter->window(), QColor(0xf1e8ff));
    painter->setPen(QColor(0xa50000));
    painter->setRenderHint(QPainter::Antialiasing);
    painter->save();
    painter->translate(500, 400);
    constexpr int L = -200, R = 200;
    QList<QVector3D> coord {
        {L, L, L},
        {R, L, L},
        {R, R, L},
        {L, R, L},
        {L, L, R},
        {R, L, R},
        {R, R, R},
        {L, R, R},
    };
    rotateRoundAxis(coord, angle_x, 0);
    rotateRoundAxis(coord, angle_y, 1);
    rotateRoundAxis(coord, angle_z, 2);
    QList<QPointF> projected;
    for (auto node : coord) {
        auto point = Project(node);
        projected.emplaceBack(point.x(), point.y());
    }
    painter->drawPolygon(projected.data(), 4);
    painter->drawPolygon(projected.data() + 4, 4);
    painter->drawLine(projected[0], projected[4]);
    painter->drawLine(projected[1], projected[5]);
    painter->drawLine(projected[2], projected[6]);
    painter->drawLine(projected[3], projected[7]);
    QVector3D x_axis{300, 0, 0};
    QVector3D y_axis{0, 300, 0};
    QVector3D z_axis{0, 0, 300};
    static QColor axes_colors[] = {
        0xff4d45,
        0x00ff8f,
        0x006cff,
    };
    int color_index = 0;
    for (auto axis : {x_axis, y_axis, z_axis}) {
        auto [x, y] = Project(axis);
        painter->setPen(axes_colors[color_index++]);
        painter->drawLine(QPoint{static_cast<int>(x), static_cast<int>(y)}, QPoint{0, 0});
    }
    painter->restore();
}

QGenericMatrix<1, 3, float> VectorToMatrix(const QVector3D &vector) {
    std::vector<float> result = {vector.x(), vector.y(), vector.z()};
    return QGenericMatrix<1, 3, float>(result.data());
}

QGenericMatrix<3, 3, float> evaluateRotationRoundAxis(double angle, int axis) {
    auto sin = [] (double x) {return float(std::sin(x));};
    auto cos = [] (double x) {return float(std::cos(x));};
    float const entries[][9] = {
        {1, 0, 0, 0, cos(angle), -sin(angle), 0, sin(angle), cos(angle)},
        {cos(angle), 0, sin(angle), 0, 1, 0, -sin(angle), 0, cos(angle)},
        {cos(angle), -sin(angle), 0, sin(angle), cos(angle), 0, 0, 0, 1},
    };
    return QGenericMatrix<3, 3, float>{entries[axis]};
}

void rotateRoundAxis(QVector<QVector3D>& points, double angle, int axis) {
    for (auto& point : points) {
//        std::cout << point.x();
        auto mat = evaluateRotationRoundAxis(angle, axis) * VectorToMatrix(point);
        point = {mat(0, 0), mat(1, 0), mat(2, 0)};
//        std::cout << ' ' << point.x() << '\n';
    }
}

QVector2D Project(const QVector3D& vector) {
    auto sqrt = [] (double x) {return float(std::sqrt(x));};
    static const std::vector<float> coordinates =
        {sqrt(3), 0, -sqrt(3), 1, 2, 1, sqrt(2), -sqrt(2), sqrt(2)};
    static const QMatrix3x3 tranform(coordinates.data());
    auto result = tranform * VectorToMatrix(vector);
    result /= sqrt(6);
    return {result(0, 0), result(1, 0)};
}
