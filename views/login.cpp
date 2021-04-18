#include "login.h"
#include "ui_login.h"
#include "editclient.h"

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

void login::on_pushButton_clicked()
{
    Register* r = Register::createRegister();
    qDebug()<<"teste";
     while (ui->username->text().toStdString() == "" || ui->password->text().toStdString() == "") {
        QMessageBox::information(
            this, tr("Cadastro"),
            tr("Preencha todos os campos!")
        );
        return;
    };


    if (!r->search(this->model, ui->username->text().toStdString())) {
        qDebug()<<"teste 1";
        QMessageBox::information(
            this,
            tr("Login"),
            tr("Usuário não encontrado!")

        );
    qDebug()<<"teste";
        return;
    }else{
        qDebug()<<"aquiiiiiiiiii";
    }
 qDebug()<<"teste 3";
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
    editclient editclient; //Trocar para a página do cliente
    editclient.exec();
    this->close();
}

void login::on_btn_newClient_clicked()
{   /*reg->exec();
    this->close();*/
    registerview registerview;
    registerview.exec();

}

void login::on_btn_admPage_clicked()
{
    login_admpage login_admpage;
    login_admpage.exec();

}

