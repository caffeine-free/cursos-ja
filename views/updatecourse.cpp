#include "updatecourse.h"
#include "ui_updatecourse.h"

#include "../src/classes/course_impl.h"

UpdateCourse::UpdateCourse(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UpdateCourse)
{
    ui->setupUi(this);
}

UpdateCourse::~UpdateCourse()
{
    delete ui;
}


Model *UpdateCourse::getModel() const
{
    return model;
}

void UpdateCourse::setModel(Model *value)
{
    model = value;
}


void UpdateCourse::on_updateCourse_btn_clicked()
{
    string name=ui->tname_edit_course->text().toStdString();
    string price=ui->tdescription_edit_course->text().toStdString();
    string description=ui->tprice_edit_course->text().toStdString();

    model->updateCourse(course, name, description, price);

}

void UpdateCourse::on_cancel_btn_clicked()
{
    this->close();
}
