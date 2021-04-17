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
