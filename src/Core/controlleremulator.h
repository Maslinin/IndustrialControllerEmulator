#ifndef CONTROLLEREMULATOR_H
#define CONTROLLEREMULATOR_H

#include <QObject>

enum class ProductQuality { None, Good, Bad };

class ControllerEmulator : public QObject
{
    Q_OBJECT

public:
    explicit ControllerEmulator(QObject* parent = nullptr);

    void togglePower() noexcept;
    void addGoodProduct() noexcept;
    void addBadProduct() noexcept;

    bool isOn() const noexcept            { return isOn_; }
    int  goodCount() const noexcept       { return goodCount_; }
    int  badCount() const noexcept        { return badCount_; }
    ProductQuality lastQuality() const noexcept { return lastQuality_; }

signals:
    void powerChanged(bool isOn);
    void productDetected(ProductQuality quality);
    void countersChanged(int good, int bad);

private:
    bool isOn_;
    int  goodCount_;
    int  badCount_;
    ProductQuality lastQuality_;
};

#endif // CONTROLLEREMULATOR_H
