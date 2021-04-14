#include "read_course.h"
#include "ui_read_course.h"

read_course::read_course(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::read_course)
{
    ui->setupUi(this);
}

read_course::~read_course()
{
    delete ui;
}
