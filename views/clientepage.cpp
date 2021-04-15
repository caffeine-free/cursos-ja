#include "clientepage.h"
#include "ui_clientepage.h"

ClientePage::ClientePage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClientePage)
{
    ui->setupUi(this);
}

ClientePage::~ClientePage()
{
    delete ui;
}

void ClientePage::on_pushButton_clicked()
{
    // SAIR DA CONTA
}

void ClientePage::on_pushButton_2_clicked()
{
    // EDITAR PERFIL
}
