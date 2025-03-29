#include "circlewidget.h"
#include <QPainter>

CircleWidget::CircleWidget(QWidget *parent) : QWidget(parent), color(Qt::gray)
{ }

void CircleWidget::setColor(const QColor &c)
{
    color = c;
    update();
}

void CircleWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setBrush(color);
    painter.setPen(Qt::NoPen);
    painter.drawEllipse(rect().adjusted(1, 1, -1, -1));
}
