#include "registerview.h"
#include "ui_registerview.h"
#include <QHBoxLayout>
#include <vector>

registerview::registerview(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registerview)
{
    ui->setupUi(this);
    this->setWindowTitle("Cadastro");
}

registerview::~registerview()
{
    delete ui;
}

Model *registerview::getModel() const {
    return model;
}

void registerview::setModel(Model *value) {
    model = value;
}

void registerview::on_btn_cancel_clicked()
{
    this->close();
}

void registerview::on_btn_register_clicked()
{
    Register* reg = Register::createRegister();

    QString qname=ui->txt_name->text();
    QString qemail=ui->txt_email->text();
    QString qcpf=ui->txt_cpf->text();
    QString qpassword=ui->txt_password->text();
    QString qconfirmPassword=ui->txt_confirm_password->text();

    string name=ui->txt_name->text().toStdString();
    string email=ui->txt_email->text().toStdString();
    string cpf=ui->txt_cpf->text().toStdString();
    string password=ui->txt_password->text().toStdString();
    string confirmPassword=ui->txt_confirm_password->text().toStdString();

    QSqlQuery query;
    query.prepare("insert into tb_clients (name_client, email_client, cpf_client,password_client) values"
                  "('"+qname+"','"+qemail+"','"+qcpf+"','"+qpassword+"')");

    while (name == "" || email == "" || cpf == ""
        || password == "") {

        QMessageBox::information(
            this, tr("Cadastro"),
            tr("Preencha todos os campos!")
        );
        return;
    };

    if (!reg->ValidateEmail(email)) {
        QMessageBox::information(
            this, tr("Cadastro"),
            tr("E-mail inválido!")
        );

        return;
    }

    if(reg->search(model, email)){
        QMessageBox::information(
            this, tr("Cadastro"),
            tr("E-mail já cadastrado!")
        );

        return;
    }
    vector<bool> v = {};
    if(query.exec()){
           reg->create(model, name, email, cpf, password,v, 0);
           QMessageBox::information(this, tr("Cadastro"), tr("Cadastro Realizado!"));
           delete reg;
           ui->txt_name->clear();
           ui->txt_email->clear();
           ui->txt_cpf->clear();
           ui->txt_password->clear();
           ui->txt_confirm_password->clear();
           ui->txt_name->setFocus();
       }else{
           qDebug()<<"Erro ao inserir registro";

       }

    this->close();
}
