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

Model *ClientControl::getModel() const
{
    return model;
}

void ClientControl::setModel(Model *value)
{
    model = value;
}

void ClientControl::load_all_clients(){
    ui->tw_allclients->clear();
    ui->tw_allclients->setColumnCount(4);
    ui->tw_allclients->setRowCount((int)model->getUserList().size());
    //ui->tw_allclients->verticalHeader()->hide();
    //ui->tw_allclients->horizontalHeader()->hide();
    ui->tw_allclients->setShowGrid(false);
    ui->tw_allclients->setColumnWidth(0, 140);
    ui->tw_allclients->setColumnWidth(1, 150);
    ui->tw_allclients->setColumnWidth(2, 150);
    ui->tw_allclients->setColumnWidth(3, 130);

    //Cabeçalho
    QStringList header={"Name","Email","CPF","Password"};
    ui->tw_allclients->setHorizontalHeaderLabels(header);
    ui->tw_allclients->setEditTriggers(QAbstractItemView::NoEditTriggers);//Componente não editável
    ui->tw_allclients->setSelectionBehavior(QAbstractItemView::SelectRows);//Selecionar a linha inteira
    ui->tw_allclients->verticalHeader()->setVisible(false);//Desabilitar números das linhas
    ui->tw_allclients->setStyleSheet("QTableView {selection-background-color:blue}");//cor da seleção

    int count = 0;
    ui->tw_allclients->setSortingEnabled(false);
    for(auto it : this->model->getUserList()){
        QString name = QString::fromStdString(it->getName());
        QTableWidgetItem *name_item = new QTableWidgetItem(name, Qt::DisplayRole);
        name_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

        QString email = QString::fromStdString(it->getEmail());
        QTableWidgetItem *email_item = new QTableWidgetItem(email, Qt::DisplayRole);
        email_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        email_item->setTextAlignment(Qt::AlignCenter);

        QString cpf = QString::fromStdString(it->getCPF());
        QTableWidgetItem *cpf_item = new QTableWidgetItem(cpf, Qt::DisplayRole);
        cpf_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        cpf_item->setTextAlignment(Qt::AlignCenter);

        QString password = QString::fromStdString(it->getPassword());
        QTableWidgetItem *password_item = new QTableWidgetItem(password, Qt::DisplayRole);
        password_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        password_item->setTextAlignment(Qt::AlignCenter);



        ui->tw_allclients->setItem(count, 0, name_item);
        ui->tw_allclients->setItem(count, 1, email_item);
        ui->tw_allclients->setItem(count, 2, cpf_item);
        ui->tw_allclients->setItem(count, 3, password_item);

        count++;
    }
    ui->tw_allclients->setSortingEnabled(true);
}



void ClientControl::setTableData(){
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setRowCount((int)model->getCourses().size());
    ui->tableWidget->verticalHeader()->hide();
    ui->tableWidget->horizontalHeader()->hide();
    ui->tableWidget->setShowGrid(false);
    ui->tableWidget->setColumnWidth(0, 230);
    ui->tableWidget->setColumnWidth(1, 50);

    int count = 0;
    ui->tableWidget->setSortingEnabled(false);
    for(auto it : this->model->getCourses()){
        QString name = QString::fromStdString(it->getName());
        QTableWidgetItem *name_item = new QTableWidgetItem(name, Qt::DisplayRole);
        name_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

        QString size = QString::fromStdString(it->getPrice());
        QTableWidgetItem *size_item = new QTableWidgetItem(size, Qt::DisplayRole);
        size_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        size_item->setTextAlignment(Qt::AlignCenter);

        ui->tableWidget->setItem(count, 0, name_item);
        ui->tableWidget->setItem(count, 1, size_item);

        count++;
    }
    ui->tableWidget->setSortingEnabled(true);

}

void ClientControl::on_pushButton_clicked()
{
    Course* c = new CourseImpl(
                ui->txt_Name->text().toStdString(),
                ui->txt_description->text().toStdString(),
                ui->txt_price->text().toStdString());

    ui->name_test->setText(ui->txt_Name->text());
    ui->description_test->setText(ui->txt_description->text());
    ui->price_test->setText(ui->txt_price->text());

    ui->txt_Name->clear();
    ui->txt_description->clear();
    ui->txt_price->clear();

    this->model->add(c);
    this->model->writeCourse("courses.csv");

    QMessageBox::information(this, "GRAVADO", "Produto inserido com sucesso!");
}

void ClientControl::on_tabWidget_currentChanged(int index)
{
    if ( index > -1 ) {
        int count = 0;
        for(auto it : this->model->getCourses()){
            QString name = QString::fromStdString(it->getName());
            QTableWidgetItem *name_item = new QTableWidgetItem(name, Qt::DisplayRole);
            name_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

            ui->tableWidget->setItem(count, 0, name_item);

            ui->tableWidget->showColumn(2);
            QPushButton* buy = new QPushButton("Comentar");
            buy->setStyleSheet("QPushButton {color: #43BCFE;}");
            ui->tableWidget->setCellWidget(count, 2, buy);
            count++;
         }
         ui->tableWidget->setSortingEnabled(true);
    }
}


void ClientControl::on_btn_clientedit_clicked()
{

}

void ClientControl::on_btn_clientdelete_clicked()
{

}

void ClientControl::on_btn_clientlogout_clicked()
{

}

void ClientControl::on_btn_clientsearch_clicked()
{

}
