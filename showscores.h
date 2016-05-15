#ifndef SHOWSCORES_H
#define SHOWSCORES_H
#include"dig.h"
#include"mainwindow.h"
#include <QWidget>

namespace Ui {
class Showscores;
}

class Showscores : public QWidget
{
    Q_OBJECT

public:
    explicit Showscores(QWidget *parent = 0);
    ~Showscores();
private slots:
    void  on_pushButton_3_clicked();
    void  on_pushButton_4_clicked();
    void  Scores();
signals:
    void showmainwindow();

private:
    Ui::Showscores *ui;
};

#endif // SHOWSCORES_H
