#include "login_admpage.h"
#include "ui_login_admpage.h"

login_admpage::login_admpage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login_admpage)
{
    ui->setupUi(this);
}

login_admpage::~login_admpage()
{
    delete ui;
}

void login_admpage::on_pushButton_clicked()
{
    admpage admpage;
    admpage.exec();
}
