#include "clientcontrol.h"
#include "ui_clientcontrol.h"

#include "../cursos-ja/src/classes/course_impl.h"

ClientControl::ClientControl(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClientControl)
{
    ui->setupUi(this);
}

ClientControl::~ClientControl()
{
    delete ui;
}

void ClientControl::on_pushButton_clicked()
{
    Course* c = new CourseImpl(
                ui->txt_Name->text().toStdString(),
                ui->txt_description->text().toStdString(),
                ui->txt_price->text().toStdString());

    QMessageBox::information(this, "GRAVADO", "Produto inserido com sucesso!");

    ui->name_test->setText(ui->txt_Name->text());
    ui->description_test->setText(ui->txt_description->text());
    ui->price_test->setText(ui->txt_price->text());

    ui->txt_Name->clear();
    ui->txt_description->clear();
    ui->txt_price->clear();

    delete c;
}

void ClientControl::on_tabWidget_currentChanged(int index)
{

}
