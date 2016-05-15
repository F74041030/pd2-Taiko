#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QLabel>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QLabel * ice1[20];
    QLabel * ice2[20];
    QLabel * popo[20];
    QLabel * good[20];
    QLabel * mouth;
    int loc1[20];
    int loc2[20];
    int locpopo[20];
    int locgood[20];
    int locmouth;
    int score=0;
    float count ;
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

private slots:
    void receivelogin();
   void move();
    void timer_timeout();
    void keyPressEvent(QKeyEvent * event);
    void Score();
    void runagain();
    void closed();
signals:
    void showdig();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
