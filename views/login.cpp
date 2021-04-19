#include "login.h"
#include "ui_login.h"
#include "clientpage.h"

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    this->setWindowTitle("Login");
}

login::~login()
{
    delete ui;
}

registerview *login::getReg() const
{
    return reg;
}

void login::setReg(registerview *value)
{
    reg = value;
}

Model *login::getModel() const
{
    return model;
}

void login::setModel(Model *value)
{
    model = value;
}

login_admpage *login::getLoginAdmPage() const
{
    return l_admpage;
}

void login::setLoginAdmPage(login_admpage *value)
{
    l_admpage = value;
}

void login::on_pushButton_clicked()
{
    Register* r = Register::createRegister();
    if (!r->search(this->model, ui->username->text().toStdString())) {
        QMessageBox::information(
            this,
            tr("Login"),
            tr("Usuário não encontrado!")
        );

        return;
    }

    User* user = r->consult(this->model, ui->username->text().toStdString());
    if (user->getPassword() != ui->password->text().toStdString()) {
        QMessageBox::information(
            this,
            tr("Login"),
            tr("Senha incorreta!")
        );

        return;
    }

    model->setUser(user);

    clientPage* cp = new clientPage();
    cp->setModel(model);
    cp->exec();
    this->close();
}

void login::on_btn_newClient_clicked()
{   /*reg->exec();
    this->close();*/
    registerview* rv = new registerview();
    rv->setModel(model);
    rv->exec();
}

void login::on_btn_admPage_clicked()
{
    login_admpage* l_adm = new login_admpage();
    l_adm->setModel(model);
    l_adm->exec();
}



