#include "editclient.h"
#include "ui_editclient.h"

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

void editclient::on_pushButton_clicked()//cancelar
{

}

void editclient::on_pushButton_2_clicked()//gravar
{

}
