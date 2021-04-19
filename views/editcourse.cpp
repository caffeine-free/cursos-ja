#include "editcourse.h"
#include "ui_editcourse.h"

#include <QMessageBox>

EditCourse::EditCourse(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditCourse)
{
    ui->setupUi(this);
}

EditCourse::~EditCourse()
{
    delete ui;
}

Course *EditCourse::getCourse() const
{
    return course;
}

void EditCourse::setCourse(Course *value)
{
    course = value;

    ui->txt_name->setText(QString::fromStdString(course->getName()));
    ui->txt_price->setText(QString::fromStdString(course->getPrice()));
    ui->txt_description->setText(QString::fromStdString(course->getDescription()));
}

Model *EditCourse::getModel() const
{
    return model;
}

void EditCourse::setModel(Model *value)
{
    model = value;
}

void EditCourse::on_edit_btn_clicked()
{
    string name = ui->txt_name->text().toStdString();
    string price = ui->txt_price->text().toStdString();
    string description = ui->txt_description->text().toStdString();

    model->updateCourse(course, name, description, price);
    model->writeCourse("../cursos-ja/database/courses.csv");

    QMessageBox::information(
        this, tr("Aviso"),
        tr("O curso foi alterado!")
    );


    this->close();
}

void EditCourse::on_CANCEL_clicked()
{
    this->close();
}
