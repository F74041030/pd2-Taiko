#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include<QPixmap>
#include<QTimer>
#include<QApplication>
#include<QKeyEvent>
#include<ctime>
#include<cstdlib>
#include<QGraphicsItem>
#include<QGraphicsScene>
#include<QGraphicsView>
#include<QGraphicsRectItem>
#include<QObject>
#include"dig.h"
QTimer *timer;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QPixmap pic3(":/523px-Tongue_(Rolling_Stones).png");

    mouth=new QLabel(this);
    mouth->setPixmap(pic3);
    locmouth=200;
    mouth->setGeometry(300,0,500,1000);
    ui->setupUi(this);
    timer = new QTimer(this);
        timer->setInterval(100);
        connect(timer,SIGNAL(timeout()),this,SLOT(timer_timeout()));
        connect(timer,SIGNAL(timeout()),this,SLOT(Score()));
    int i;


    for(i=0;i<=19;i++)
    {




    QPixmap pic1(":/icec.png");
    ice1[i]=new QLabel(this);
    ice1[i]->setPixmap(pic1);
    QPixmap pic2(":/icew.png");
    ice2[i]=new QLabel(this);
    ice2[i]->setPixmap(pic2);
    QPixmap picpopo(":/276.png");
    popo[i]=new QLabel(this);
    popo[i]->setPixmap(picpopo);
    QPixmap picgood(":/113470909_5646798_0_9309d_6cb5634d_L.png");
    good[i]=new QLabel(this);
    good[i]->setPixmap(picgood);
    }
    int a;
    int j;
    srand(time(NULL));
    for(j=0;j<=19;j++)
    {

    a=rand()%4;

    loc1[j]=(220*a*(2*j-1));
    ice1[j]->setGeometry(220*a*(2*j-1),0,1000,1000);
    loc2[j]=(310*a*j);
    ice2[j]->setGeometry(310*a*j,0,1000,1000);
    locpopo[j]=(2000*j);
    popo[j]->setGeometry((2000*j),0,1000,1000);
    locgood[j]=(3000*j);
    good[j]->setGeometry((3000*j),0,1000,1000);

    }

    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start();




}


void MainWindow::timer_timeout(){
    count=count-1;
    ui->labelNumber->setText(QString("Time:00:") + QString::number(count/10));
    if(count<0)
    {
        count=0;
        emit showdig();

    }
}
void MainWindow::Score()
{
    ui->label->setText(QString("score  ") + QString::number(score));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::move()
{
int k;
for(k=0;k<=19;k++)
{ice1[k]->setGeometry(loc1[k]-20,0,1000,1000);
    loc1[k]=loc1[k]-20;
 ice2[k]->setGeometry(loc2[k]-20,0,1000,1000);
   loc2[k]=loc2[k]-20;
 popo[k]->setGeometry(locpopo[k]-20,0,1000,1000);
   locpopo[k]=locpopo[k]-20;
   good[k]->setGeometry(locgood[k]-20,0,1000,1000);
   locgood[k]=locgood[k]-20;
}
}

void MainWindow::keyPressEvent(QKeyEvent * event)
{   if(event->key() == Qt::Key_Left){
    int l;
    for(l=0;l<=19;l++)
    {
        if(loc1[l]<500&&loc1[l]>300)
        {
            QPixmap pic4(":/icecream_03.png");

            ice1[l]->setPixmap(pic4);
            score=score+1;
        }
    }}
    if(event->key() == Qt::Key_Right)
    {int l;
    for(l=0;l<=19;l++)
    {
    if(loc2[l]>300&&loc2[l]<500)
    {            QPixmap pic4(":/icecream_03.png");
        ice2[l]->setPixmap(pic4);
        score=score+1;


    }
    }
    }
    if(event->key() == Qt::Key_Down)
    {int l;
        for(l=0;l<=19;l++)
        {if(locpopo[l]>300&&locpopo[l]<500)
            {popo[l]->hide();
                score=score-1;
            }
        }
    }
    if(event->key() == Qt::Key_Up)
    {int l;
        for(l=0;l<=19;l++)
        {if(locgood[l]>300&&locgood[l]<500)
            {good[l]->hide();
                score=score+3;
            }
        }
    }
}

void MainWindow::runagain()
{
    count=300;
    score=0;
}

void MainWindow::receivelogin()
{

    this->show();//显示主窗口
}
void MainWindow::closed()
{
    this->close();
}
