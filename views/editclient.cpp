#include "editclient.h"
#include "ui_editclient.h"

#include "../cursos-ja/src/classes/user_impl.h"
#include "../cursos-ja/src/lib/model_impl.h"

editclient::editclient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editclient)
{
    ui->setupUi(this);
}

editclient::~editclient()
{
    delete ui;
}

User *editclient::getUser() const
{
    return user;
}

void editclient::setUser(User *value)
{
    user = value;

    ui->txt_name_edit_client->setText(QString::fromStdString(user->getName()));
    ui->txt_cpf_edit_client->setText(QString::fromStdString(user->getCPF()));
    ui->txt_email_edit_client->setText(QString::fromStdString(user->getEmail()));
    ui->txt_password_edit_client->setText(QString::fromStdString(user->getPassword()));
}

Model *editclient::getModel() const
{
    return model;
}

void editclient::setModel(Model *value)
{
    model = value;
}

void editclient::on_cancel_btn_edit_client_clicked()
{
    this->close();
}

void editclient::on_update_btn_clicked()
{
    string name=ui->txt_name_edit_client->text().toStdString();
    string email=ui->txt_email_edit_client->text().toStdString();
    string cpf=ui->txt_cpf_edit_client->text().toStdString();
    string password=ui->txt_password_edit_client->text().toStdString();

    model->updateUser(user, name, email, cpf, password);

    model->writeUser("../cursos-ja/database/users.csv");

    QMessageBox::information(
        this, tr("Aviso"),
        tr("Os dados do usuário foram alterados!")
    );

    this->close();
}

void editclient::on_remove_profile_btn_clicked()
{
    /*Model* model = new ModelImpl();

    vector<Course*> client_courses;
    client_courses.push_back(new CourseImpl());
    User* user = new UserImpl("maria", "maria@gmail.com", "2", "3", client_courses, 0);

    string name=ui->txt_name_edit_client->text().toStdString();
    string email=ui->txt_email_edit_client->text().toStdString();
    string cpf=ui->txt_cpf_edit_client->text().toStdString();
    string password=ui->txt_password_edit_client->text().toStdString();

    model->removeUser(user);

    delete model;
    delete user;

    model->setUser(nullptr);
    QMessageBox::information(
        this, tr("Logout"),
        tr("Você foi deslogado do sistema e sua conta será excluída!")
    );
    this->close();*/
}
