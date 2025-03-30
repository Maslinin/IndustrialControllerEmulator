#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>
#include "ui_mainWindow.h"
#include "../Core/controlleremulator.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override = default;

protected:
    void keyPressEvent(QKeyEvent *event) override;

private:
    std::unique_ptr<Ui::MainWindow> ui;
    ControllerEmulator controller_;

    void updatePowerIndicator(bool isOn);
    void updateSensorIndicator(ProductQuality quality);
    void updateCounters(int good, int bad);
};

#endif // MAINWINDOW_H
