#include "registerview.h"
#include "ui_registerview.h"
#include "../cursos-ja/src/classes/user_impl.h"
#include <QHBoxLayout>
#include <vector>
#include "editcourse.h"
#include <regex>

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
    string name=ui->txt_name->text().toStdString();
    string email=ui->txt_email->text().toStdString();
    string cpf=ui->txt_cpf->text().toStdString();
    string password=ui->txt_password->text().toStdString();
    string confirmPassword=ui->txt_confirm_password->text().toStdString();

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

    if (!regex_match(email, regex("([a-z]+)([_.a-z0-9]*)([a-z0-9]+)(@)([a-z]+)([.a-z]+)([a-z]+)"))){
        QMessageBox::warning(
            this, tr("Cadastro"),
            tr("Informe um email válido")
        );
        return;
    }

    Course* course_1;
    Course* course_2;
    Course* course_3;
    Course* course_4;
    Course* course_5;

    string  course_name, course_description, course_price;
    course_name = "vazio";
    course_description = "vazio";
    course_price = "vazio";

    course_1 = model->createCourse(course_name, course_description, course_price);
    course_2 = model->createCourse(course_name, course_description, course_price);
    course_3 = model->createCourse(course_name, course_description, course_price);
    course_4 = model->createCourse(course_name, course_description, course_price);
    course_5 = model->createCourse(course_name, course_description, course_price);

    vector<Course*> courses;
    courses.push_back(course_1);
    courses.push_back(course_2);
    courses.push_back(course_3);
    courses.push_back(course_4);
    courses.push_back(course_5);

    User* user = new UserImpl(name, email, cpf, password, courses, 0);
    this->model->addUser(user);
    this->model->writeUser("../cursos-ja/database/users.csv");

    ui->txt_name->clear();
    ui->txt_email->clear();
    ui->txt_cpf->clear();
    ui->txt_password->clear();
    ui->txt_confirm_password->clear();
    ui->txt_name->setFocus();
    this->close();
}
