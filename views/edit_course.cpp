#include "edit_course.h"
#include "ui_edit_course.h"

edit_course::edit_course(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::edit_course)
{
    ui->setupUi(this);
}

edit_course::~edit_course()
{
    delete ui;
}
