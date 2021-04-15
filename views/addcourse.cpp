#include "addcourse.h"
#include "ui_addcourse.h"

addCourse::addCourse(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addCourse)
{
    ui->setupUi(this);
}

addCourse::~addCourse()
{
    delete ui;
}
Model* addCourse::getModel() const
{
    return this->model;
}

void addCourse::setModel(Model* model)
{
    this->model = model;
}

void initialize() {}

void addCourse::on_save_button_clicked()
{
    string name = ui->add_name->text().toStdString();
    string description = ui->add_description->text().toStdString();
    string price = ui->add_price->text().toStdString();

    if(name == "" || description == "" || price == ""){
        QMessageBox::information(
            this, tr("Adicionar Curso"),
            tr("Preencha todos os campos!")
        );
        return;
    }

    Course* course = this->model->createCourse(name, description, price);
    this->model->add(course);
    this->close();
}
