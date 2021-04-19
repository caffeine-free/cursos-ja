#include "registerview.h"
#include "ui_registerview.h"
#include "../cursos-ja/src/classes/user_impl.h"
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
    //Register* reg = Register::createRegister();

    vector<Course*> v;

    string name=ui->txt_name->text().toStdString();
    string email=ui->txt_email->text().toStdString();
    string cpf=ui->txt_cpf->text().toStdString();
    string password=ui->txt_password->text().toStdString();
    string confirmPassword=ui->txt_confirm_password->text().toStdString();



    /*ui->name_test->setText(ui->txt_Name->text());
    ui->email_test->setText(ui->txt_description->text());
    ui->cpf_test->setText(ui->txt_price->text());
    ui->cpf_test->setText(ui->txt_price->text());*/

    while (name == "" || email == "" || cpf == ""
        || password == "") {

        QMessageBox::warning(
            this, tr("Cadastro"),
            tr("Preencha todos os campos!")
        );
        return;
    };

    if( password != confirmPassword){
        QMessageBox::warning(
            this, tr("Cadastro"),
            tr("Os campos de senha não coincidem!")
        );
        return;
    }

   /* if (!reg->ValidateEmail(email)) {
        QMessageBox::warning(
            this, tr("Cadastro"),
            tr("E-mail inválido!")
        );

        return;
    }*/
    User* user = new UserImpl(name, email, cpf, password, v, 0);
    this->model->addUser(user);
    this->model->writeUser("../cursos-ja/database/users.csv");
    /*if(reg->search(model, email)){
        QMessageBox::warning(
            this, tr("Cadastro"),
            tr("E-mail já cadastrado!")
        );

        return;
    }*/
    //User* user = this->model->createUser(name, email, cpf, password, v, 0);

    //reg->create(model, name, email, cpf, password,v, 0);
    ui->txt_name->clear();
    ui->txt_email->clear();
    ui->txt_cpf->clear();
    ui->txt_password->clear();
    ui->txt_confirm_password->clear();
    ui->txt_name->setFocus();
   // delete reg;
    this->close();
}
