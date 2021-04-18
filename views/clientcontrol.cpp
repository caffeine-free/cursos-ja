#include "clientcontrol.h"
#include "ui_clientcontrol.h"

#include "../cursos-ja/src/classes/course_impl.h"
#include "../cursos-ja/src/classes/user_impl.h"
#include "../cursos-ja/views/login.h"
#include "../cursos-ja/views/editclient.h"

#include "editcourse.h"

ClientControl::ClientControl(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClientControl)
{
    ui->setupUi(this);
    this->setWindowTitle("Página Administrativa");

}

ClientControl::~ClientControl()
{
    delete ui;
}

Model *ClientControl::getModel() const
{
    return model;
}

void ClientControl::setModel(Model *value)
{
    model = value;
}

void ClientControl::load_course_data(){
    int count = 0;
    ui->table_adm_courses->setSortingEnabled(false);
    for(auto it : this->model->getCourses()){
        QString name = QString::fromStdString(it->getName());
        QTableWidgetItem *name_item = new QTableWidgetItem(name, Qt::DisplayRole);
        name_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

        QString size = QString::fromStdString(it->getPrice());
        QTableWidgetItem *size_item = new QTableWidgetItem(size, Qt::DisplayRole);
        size_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        size_item->setTextAlignment(Qt::AlignCenter);

        QPushButton* edit_course = new QPushButton("Editar");
        edit_course->setStyleSheet("QPushButton {font-weight:bold; width: 90%;}");
        connect(edit_course, SIGNAL(pressed()), this, SLOT(edit_course_button_pressed()));

        QPushButton* remove_course = new QPushButton("Remover");
        remove_course->setStyleSheet("QPushButton {font-weight:bold; width: 90%;}");
        connect(remove_course, SIGNAL(pressed()), this, SLOT(remove_course_button_pressed()));

        ui->table_adm_courses->setItem(count, 0, name_item);
        ui->table_adm_courses->setItem(count, 1, size_item);
        ui->table_adm_courses->setCellWidget(count, 2, edit_course);
        ui->table_adm_courses->setCellWidget(count, 3, remove_course);

        count++;
    }
}

void ClientControl::edit_course_button_pressed(){
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender());
    int row = ui->table_adm_courses->indexAt(buttonSender->pos()).row();

    EditCourse* ec = new EditCourse();
    ec->setModel(model);
    ec->setCourse(model->getCourses()[row]);
    ec->exec();

    load_course_data();
}

void ClientControl::edit_user_pressed(){
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender());
    int row = ui->table_adm_courses->indexAt(buttonSender->pos()).row();

    editclient* ec = new editclient();
    ec->setModel(model);
    ec->setUser(model->getUserList()[row]);
    ec->exec();

    load_user_data();
}

void ClientControl::remove_course_button_pressed(){
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender());
    int row = ui->table_adm_courses->indexAt(buttonSender->pos()).row();

    model->removeCourse(model->getCourses()[row]);

    QMessageBox::information(this, "GRAVADO", "O curso foi removido!");

    model->writeCourse("../cursos-ja/database/courses.csv");
    load_course_data();
}

void ClientControl::remove_user_pressed(){
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender());
    int row = ui->table_adm_courses->indexAt(buttonSender->pos()).row();

    model->removeUser(model->getUserList()[row]);

    QMessageBox::information(this, "REMOVIDO", "O usuário foi removido!");

    model->writeUser("../cursos-ja/database/users.csv");
    load_user_data();
}

void ClientControl::load_user_data(){
    int count = 0;
    ui->table_adm_courses->setSortingEnabled(false);
    for(auto it : this->model->getUserList()){
        QString name = QString::fromStdString(it->getName());
        QTableWidgetItem *name_item = new QTableWidgetItem(name, Qt::DisplayRole);
        name_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

        QString email = QString::fromStdString(it->getEmail());
        QTableWidgetItem *email_item = new QTableWidgetItem(email, Qt::DisplayRole);
        email_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        email_item->setTextAlignment(Qt::AlignCenter);

        QString cpf = QString::fromStdString(it->getCPF());
        QTableWidgetItem *cpf_item = new QTableWidgetItem(cpf, Qt::DisplayRole);
        cpf_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        cpf_item->setTextAlignment(Qt::AlignCenter);

        QString password = QString::fromStdString(it->getPassword());
        QTableWidgetItem *password_item = new QTableWidgetItem(password, Qt::DisplayRole);
        password_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        password_item->setTextAlignment(Qt::AlignCenter);

        ui->table_adm_user->setItem(count, 0, name_item);
        ui->table_adm_user->setItem(count, 1, email_item);
        ui->table_adm_user->setItem(count, 2, cpf_item);
        ui->table_adm_user->setItem(count, 3, password_item);

        QPushButton* edit_user = new QPushButton("Editar");
        edit_user->setStyleSheet("QPushButton {font-weight:bold; width: 90%;}");
        connect(edit_user, SIGNAL(pressed()), this, SLOT(edit_user_pressed()));

        QPushButton* remove_user = new QPushButton("Remover");
        remove_user->setStyleSheet("QPushButton {font-weight:bold; width: 90%;}");
        connect(remove_user, SIGNAL(pressed()), this, SLOT(remove_user_pressed()));

        ui->table_adm_user->setCellWidget(count, 4, edit_user);
        ui->table_adm_user->setCellWidget(count, 5, remove_user);

        count++;
    }
}

void ClientControl::setTableData(){
    ui->table_adm_courses->clear();
    ui->table_adm_courses->setColumnCount(4);
    ui->table_adm_courses->setRowCount((int)model->getCourses().size());
    ui->table_adm_courses->verticalHeader()->hide();
    ui->table_adm_courses->horizontalHeader()->hide();
    ui->table_adm_courses->setShowGrid(false);
    ui->table_adm_courses->setColumnWidth(0, 230);
    ui->table_adm_courses->setColumnWidth(1, 50);
    ui->table_adm_courses->setSortingEnabled(false);

    load_course_data();

    ui->table_adm_user->clear();
    ui->table_adm_user->setColumnCount(6);
    ui->table_adm_user->setRowCount((int)model->getUserList().size());
    ui->table_adm_user->verticalHeader()->hide();
    ui->table_adm_user->horizontalHeader()->hide();
    ui->table_adm_user->setShowGrid(false);
    ui->table_adm_user->setColumnWidth(0, 230);
    ui->table_adm_user->setColumnWidth(1, 230);
    ui->table_adm_user->setColumnWidth(2, 50);
    ui->table_adm_user->setSortingEnabled(false);

    load_user_data();

}

void ClientControl::on_pushButton_clicked()
{
    Course* c = new CourseImpl(
                ui->txt_Name->text().toStdString(),
                ui->txt_description->text().toStdString(),
                ui->txt_price->text().toStdString());

    ui->txt_Name->clear();
    ui->txt_description->clear();
    ui->txt_price->clear();

    this->model->add(c);
    this->model->writeCourse("../cursos-ja/database/courses.csv");

    QMessageBox::information(this, "GRAVADO", "Produto inserido com sucesso!");
    load_course_data();
}

void ClientControl::on_tabWidget_currentChanged(int index)
{
    if ( index == 1 ) {
        load_user_data();
    } else if ( index == 3 ){
        load_course_data();
    }
}

void ClientControl::on_exit_adm_btn_clicked()
{
    model->setUser(nullptr);
    QMessageBox::information(
        this, tr("Logout"),
        tr("Você foi deslogado do sistema!")
    );
    this->close();

    login* l = new login();
    l->setModel(model);
    l->exec();
}

void ClientControl::on_edit_adm_client_btn_clicked()
{
    editclient *ec = new editclient();
    ec->setModel(model);
    ec->setUser(model->getUser());
    ec->exec();
}

void ClientControl::on_add_user_btn_clicked()
{
    vector<Course*> c;

    if ( ui->txt_pass_user->text() == ui->txt_cpass_user->text() ){
        User* u = new UserImpl(
                    ui->txt_name_user->text().toStdString(),
                    ui->txt_email_user->text().toStdString(),
                    ui->txt_cpf_user->text().toStdString(),
                    ui->txt_pass_user->text().toStdString(),
                    c,
                    ui->txt_permission->text().toInt()
                    );

        this->model->add(u);
        this->model->writeUser("../cursos-ja/database/users.csv");

        QMessageBox::information(this, "GRAVADO", "Usuário cadastrado com sucesso!");
        load_user_data();

        ui->txt_name_user->clear();
        ui->txt_email_user->clear();
        ui->txt_cpf_user->clear();
        ui->txt_pass_user->clear();
        ui->txt_cpass_user->clear();
        ui->txt_permission->clear();
    } else {
        QMessageBox::information(this, "GRAVADO", "As senhas não são iguais!");
    }
}
