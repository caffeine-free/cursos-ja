#include "admpage.h"
#include "ui_admpage.h"

admpage::admpage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admpage)
{
       /* int line=0;
        ui->tw_clients->setColumnCount(5);

        for(auto it : this->model->getUserList()){

            QString name = QString::fromStdString(it->getName());
            QString email = QString::fromStdString(it->getEmail());
            QString cpf = QString::fromStdString(it->getCPF());
            QString password = QString::fromStdString(it->getPassword());

            ui->tw_clients->insertRow(line);
            ui->tw_clients->setItem(line,0, new QTableWidgetItem(name));//(Linha, coluna, item) Definir os itens da linha
            ui->tw_clients->setItem(line,1, new QTableWidgetItem(email));// email
            ui->tw_clients->setItem(line,2, new QTableWidgetItem(cpf));// cpf
            ui->tw_clients->setItem(line,4, new QTableWidgetItem(password));// senha
            ui->tw_clients->setRowHeight(line,20);
            line++;
        }*/
        //Formatações
        //Largura colunas
       /* ui->tw_clients->setColumnWidth(0,50);
        ui->tw_clients->setColumnWidth(1,275);
        ui->tw_clients->setColumnWidth(2,150);
        ui->tw_clients->setColumnWidth(3,50);
        ui->tw_clients->setColumnWidth(4,170);

        //Cabeçalho
        QStringList header={"ID","Name","Email","CPF","Sector","Password"};
        ui->tw_clients->setHorizontalHeaderLabels(header);
        ui->tw_clients->setEditTriggers(QAbstractItemView::NoEditTriggers);//Componente não editável
        ui->tw_clients->setSelectionBehavior(QAbstractItemView::SelectRows);//Selecionar a linha inteira
        ui->tw_clients->verticalHeader()->setVisible(false);//Desabilitar números das linhas
        ui->tw_clients->setStyleSheet("QTableView {selection-background-color:blue}");//cor da seleção*/

    ui->setupUi(this);
}

admpage::~admpage()
{
    delete ui;
}

Model *admpage::getModel() const
{
    return model;
}

void admpage::setModel(Model *value)
{
    model = value;
}

void admpage::setTableData(){
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setRowCount((int)model->getUserList().size());
    ui->tableWidget->verticalHeader()->hide();
    ui->tableWidget->horizontalHeader()->hide();
    ui->tableWidget->setShowGrid(false);
    ui->tableWidget->setColumnWidth(0, 230);
    ui->tableWidget->setColumnWidth(1, 250);
    ui->tableWidget->setColumnWidth(3, 150);

    int count = 0;
    ui->tableWidget->setSortingEnabled(false);
    for(auto it : this->model->getUserList()){
        QString name = QString::fromStdString(it->getName());
        QTableWidgetItem *name_item = new QTableWidgetItem(name, Qt::DisplayRole);
        name_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);





        ui->tableWidget->setItem(count, 0, name_item);



        count++;
    }
    ui->tableWidget->setSortingEnabled(true);

}


void admpage::on_btn_search_clicked()
{

}

void admpage::on_btn_delete_clicked()
{

}

void admpage::on_btn_edit_clicked()
{

}

void admpage::on_pushButton_4_clicked()
{
    this->close();
}
