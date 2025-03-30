#include "mainwindow.h"
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(std::make_unique<Ui::MainWindow>())
{
    ui->setupUi(this);

    connect(&controller_, &ControllerEmulator::powerChanged, this, &MainWindow::updatePowerIndicator);
    connect(&controller_, &ControllerEmulator::productDetected, this, &MainWindow::updateSensorIndicator);
    connect(&controller_, &ControllerEmulator::countersChanged, this, &MainWindow::updateCounters);

    updatePowerIndicator(controller_.isOn());
    updateSensorIndicator(ProductQuality::None);
    updateCounters(0, 0);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_Q:
        controller_.togglePower();
        break;
    case Qt::Key_W:
        controller_.addGoodProduct();
        break;
    case Qt::Key_E:
        controller_.addBadProduct();
        break;
    }
}

void MainWindow::updatePowerIndicator(bool isOn)
{
    ui->controllerCircle->setColor(isOn ? Qt::green : Qt::gray);
    ui->controllerStatusLabel->setText(isOn ? tr("Turned on") : tr("Turned off"));
}

void MainWindow::updateSensorIndicator(ProductQuality quality)
{
    QColor color = Qt::gray;
    switch (quality)
    {
    case ProductQuality::Good:
        color = Qt::green;
        break;
    case ProductQuality::Bad:
        color = Qt::red;
        break;
    default:
        color = Qt::gray;
        break;
    }
    ui->sensorCircle->setColor(color);
}

void MainWindow::updateCounters(int good, int bad)
{
    ui->countsLabel->setText(tr("Good Items: %1\nBad Items: %2").arg(good).arg(bad));
}
