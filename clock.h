#ifndef CLOCK_H
#define CLOCK_H

#include <QFont>
#include <QTimer>
#include <QGraphicsScene>
#include <QString>
#include <QGraphicsTextItem>
class Clock : public QGraphicsTextItem
{
public:
    Clock();
    void advance(int phase);
    int time;
};

#endif // CLOCK_H
