#include "controlleremulator.h"

ControllerEmulator::ControllerEmulator(QObject* parent)
    : QObject(parent),
    isOn_(false),
    goodCount_(0),
    badCount_(0),
    lastQuality_(ProductQuality::None)
{ }

void ControllerEmulator::togglePower() noexcept
{
    isOn_ = !isOn_;

    if (!isOn_) {
        goodCount_ = 0;
        badCount_ = 0;
        lastQuality_ = ProductQuality::None;

        emit countersChanged(0, 0);
        emit productDetected(lastQuality_);
    }

    emit powerChanged(isOn_);
}

void ControllerEmulator::addGoodProduct() noexcept
{
    if (!isOn_) return;

    ++goodCount_;
    lastQuality_ = ProductQuality::Good;

    emit productDetected(lastQuality_);
    emit countersChanged(goodCount_, badCount_);
}

void ControllerEmulator::addBadProduct() noexcept
{
    if (!isOn_) return;

    ++badCount_;
    lastQuality_ = ProductQuality::Bad;

    emit productDetected(lastQuality_);
    emit countersChanged(goodCount_, badCount_);
}
