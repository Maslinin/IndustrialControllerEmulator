#ifndef CIRCLEWIDGET_H
#define CIRCLEWIDGET_H

#include <QWidget>
#include <QColor>

class CircleWidget : public QWidget
{
public:
    explicit CircleWidget(QWidget *parent = nullptr);
    void setColor(const QColor &c);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QColor color = Qt::gray;
};

#endif // CIRCLEWIDGET_H
