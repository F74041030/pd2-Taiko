#ifndef DIG_H
#define DIG_H

#include <QWidget>

namespace Ui {
class dig;
}

class dig : public QWidget
{
    Q_OBJECT

public:
    explicit dig(QWidget *parent = 0);
    ~dig();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void receivelogout();

signals:
    void showmainwindow();

private:
    Ui::dig *ui;
};

#endif // DIG_H
