#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../Core/controlleremulator.h"
#include <ui_mainwindow.h>
#include <QMainWindow>
#include <memory>

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
