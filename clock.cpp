#include "clock.h"

Clock::Clock()
{
    time = 6000;
    setPlainText(QString("Time:"+QString::number(time)));
    setDefaultTextColor(Qt::green);
    setFont(QFont("times",30));
    QTimer*clo = new QTimer(this);
    clo->start(10);
    connect(clo,SIGNAL(timeout()),this,SLOT(advance()));

}

void Clock::advance(int phase)
{
    if(time>0)
    {
        time--;
        setPlainText(QString("Time:"+QString::number(time)));
    }
}
