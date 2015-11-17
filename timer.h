#ifndef TIMER_H
#define TIMER_H


#include <QLCDNumber>
class QTimer;

class Timer: public QLCDNumber
{
    Q_OBJECT
private:
    int seconds;
    QTimer *timer;
public:
    Timer(int s,QWidget *parent = 0);
    void stopTimer()const;
    int getTime()const;
private slots:
    void tickTimer();
signals:
    void endTime();
};

#endif // TIMER_H
