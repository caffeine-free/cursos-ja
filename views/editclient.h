#ifndef EDITCLIENT_H
#define EDITCLIENT_H

#include <QDialog>

namespace Ui {
class editclient;
}

class editclient : public QDialog
{
    Q_OBJECT

public:
    explicit editclient(QWidget *parent = nullptr);
    ~editclient();

private:
    Ui::editclient *ui;
};

#endif // EDITCLIENT_H
