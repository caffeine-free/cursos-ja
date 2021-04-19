#include "login_admpage.h"
#include "ui_login_admpage.h"

login_admpage::login_admpage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login_admpage)
{
    ui->setupUi(this);
}

Model *login_admpage::getModel() const
{
    return model;
}

void login_admpage::setModel(Model *value)
{
    model = value;
}

ClientControl *login_admpage::getClientControl() const
{
    return admpage;
}

void login_admpage::setClientControl(ClientControl *value)
{
    admpage = value;
}

login_admpage::~login_admpage()
{
    delete ui;
}

void login_admpage::on_pushButton_clicked()
{
    admpage->exec();
}
