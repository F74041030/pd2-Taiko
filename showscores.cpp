#include "showscores.h"
#include"dig.h"
#include"mainwindow.h"
#include "ui_showscores.h"

Showscores::Showscores(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Showscores)
{
    ui->setupUi(this);
    ui->pushButton_3->setText("play again");
    ui->pushButton_4->setText("exit");
    Scores();
}

Showscores::~Showscores()
{
    delete ui;
}
void Showscores::on_pushButton_3_clicked()
{
    this ->hide();
    emit showmainwindow();

}
void Showscores::Scores()
{
    ui->score->setText(QString("score:  ") + QString::number(score));
}

void Showscores::on_pushButton_4_clicked()
{
    this ->close();
}
