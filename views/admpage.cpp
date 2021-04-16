#include "admpage.h"
#include "ui_admpage.h"

admpage::admpage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admpage)
{
    ui->setupUi(this);
}

admpage::~admpage()
{
    delete ui;
}
