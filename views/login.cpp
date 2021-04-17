#include "login.h"
#include "ui_login.h"

static QSqlDatabase bancoDeDados=QSqlDatabase::addDatabase("QSQLITE");

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    this->setWindowTitle("Login");

    bancoDeDados.setDatabaseName("/home/claragomes/Documentos/ufop/database/teste.db");
    if(!bancoDeDados.open()){
        ui->label->setText("Não abriu");
    }else{
        ui->label->setText("abriu");
    }
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
    this->close();
}

void login::on_btn_newClient_clicked()
{
    this->close();
    reg->exec();
}

void login::on_btn_admPage_clicked()
{
    /*login_adm_page login_adm_page;
    login_adm_page.exec();
    Fazer igual ao cadastro do cliente*/
}

