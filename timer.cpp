#include <QtWidgets>
#include "timer.h"

Timer::Timer(int s, QWidget *parent):QLCDNumber(parent),seconds(s)
{
    setSegmentStyle(Flat);
    timer = new QTimer(this);
    timer->start(1000);
    connect(timer,SIGNAL(timeout()),this,SLOT(tickTimer()));
    tickTimer();
}

void Timer::tickTimer()
{
    seconds--;
    if(seconds == 0)
    {
        timer->stop();
        emit endTime();
    }
    int minute = seconds / 60;
    int second = seconds % 60;
    QString text;
    if(minute < 10)
        text += "0";
    text += QString::number(minute);
    if(seconds % 2 == false)
        text += ":";
    else
        text += " ";
    if(second < 10)
        text += "0";
    text += QString::number(second);
    display(text);
}

void Timer::stopTimer()const
{
    timer->stop();
}

int Timer::getTime()const
{
    return seconds;
}
