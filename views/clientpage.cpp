#include "clientpage.h"
#include "ui_clientpage.h"

#include "../src/classes/course_impl.h"
#include "../src/classes/user_impl.h"
#include "../views/login.h"

clientPage::clientPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::clientPage)
{
    ui->setupUi(this);
    this->setWindowTitle("Página do Cliente");

}

clientPage::~clientPage()
{
    delete ui;
}

Model *clientPage::getModel() const
{
    return model;
}

void clientPage::setModel(Model *value)
{
    model = value;
}

editclient* clientPage::getEditClient() const
{
    return ec;
}

void clientPage::setEditClient(editclient* value)
{
    ec = value;
}

void clientPage::on_edit_profile_btn_clicked()
{
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender());

    editclient* ec = new editclient();
    ec->setModel(model);
    ec->setUser(model->getUser());
    ec->exec();


}

void clientPage::load_all_courses(const vector<Course*>& courses){
    int count = 0;
    ui->table_all_courses->setSortingEnabled(false);
    for(auto it : courses){
        QString name = QString::fromStdString(it->getName());
        QTableWidgetItem *name_item = new QTableWidgetItem(name, Qt::DisplayRole);
        name_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

        QString description = QString::fromStdString(it->getDescription());
        QTableWidgetItem *description_item = new QTableWidgetItem(description, Qt::DisplayRole);
        description_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        description_item->setTextAlignment(Qt::AlignCenter);

        QString size = QString::fromStdString(it->getPrice());
        QTableWidgetItem *size_item = new QTableWidgetItem(size, Qt::DisplayRole);
        size_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        size_item->setTextAlignment(Qt::AlignCenter);

        QPushButton* comment = new QPushButton("Comprar");
        comment->setStyleSheet("QPushButton {font-weight:bold; width: 90%;}");
        connect(comment, SIGNAL(pressed()), this, SLOT(buy_button_pressed()));

        ui->table_all_courses->setItem(count, 0, name_item);
        ui->table_all_courses->setItem(count, 1, description_item);
        ui->table_all_courses->setItem(count, 2, size_item);
        ui->table_all_courses->setCellWidget(count, 3, comment);

        count++;
    }
        ui->table_all_courses->setSortingEnabled(false);
        ui->table_all_courses->setRowCount((int)courses.size());
}

void clientPage::load_client_courses(const vector<Course*>& courses){

    int count = 0;
    ui->table_client_courses->setSortingEnabled(false);
    for(auto it : courses){
        if(it->getName() == "vazio" && it->getPrice() == "vazio" && it->getDescription() == "vazio"){
            continue;
        }

        QString name = QString::fromStdString(it->getName());
        QTableWidgetItem *name_item = new QTableWidgetItem(name, Qt::DisplayRole);
        name_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

        QString size = QString::fromStdString(it->getPrice());
        QTableWidgetItem *size_item = new QTableWidgetItem(size, Qt::DisplayRole);
        size_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        size_item->setTextAlignment(Qt::AlignCenter);

        ui->table_client_courses->setItem(count, 0, name_item);
        ui->table_client_courses->setItem(count, 1, size_item);

        count++;
    }
    ui->table_client_courses->setSortingEnabled(false);
    ui->table_client_courses->setRowCount((int)courses.size());

}

void clientPage::setTableData(){
    ui->table_client_courses->clear();
    ui->table_client_courses->setColumnCount(2);
    ui->table_client_courses->verticalHeader()->hide();
    ui->table_client_courses->horizontalHeader()->hide();
    ui->table_client_courses->setShowGrid(false);
    ui->table_client_courses->setColumnWidth(0, 430);
    ui->table_client_courses->setColumnWidth(1, 50);
    ui->table_client_courses->setSelectionBehavior(QAbstractItemView::SelectRows);

    ui->table_client_courses->setSortingEnabled(false);
    ui->table_client_courses->setSortingEnabled(false);

    load_client_courses(this->model->getUser()->getCourses());

    ui->table_all_courses->clear();
    ui->table_all_courses->setColumnCount(4);
    ui->table_all_courses->setRowCount((int)model->getCourses().size());
    ui->table_all_courses->verticalHeader()->hide();
    ui->table_all_courses->horizontalHeader()->hide();
    ui->table_all_courses->setShowGrid(false);
    ui->table_all_courses->setColumnWidth(0, 230);
    ui->table_all_courses->setColumnWidth(1, 300);
    ui->table_all_courses->setColumnWidth(2, 30);
    ui->table_all_courses->setColumnWidth(3, 70);
    ui->table_all_courses->setSelectionBehavior(QAbstractItemView::SelectRows);

    ui->table_all_courses->setSortingEnabled(false);
    ui->table_all_courses->setSortingEnabled(false);

    load_all_courses(model->getCourses());

}

void clientPage::buy_button_pressed(){
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender());
    //int row = ui->table_all_courses->indexAt(buttonSender->pos()).row();
    int row=ui->table_all_courses->currentRow();

    Course* c = new CourseImpl(
                   ui->table_all_courses->item(row, 0)->text().toStdString(),
                   ui->table_all_courses->item(row, 1)->text().toStdString(),
                   ui->table_all_courses->item(row, 2)->text().toStdString()
                );
   for(auto it : this->model->getUser()->getCourses()){
       if(it->getName() == "vazio" && it->getPrice() == "vazio" && it->getDescription() == "vazio"){
           this->model->getUser()->getCourses().erase(
               remove(
                   this->model->getUser()->getCourses().begin(),
                   this->model->getUser()->getCourses().end(),
                   it
               ),
               this->model->getUser()->getCourses().end()
           );
           break;
       }
   }
    model->getUser()->getCourses().push_back(c);
    model->writeUser("../cursos-ja/database/users.csv");
    load_client_courses(this->model->getUser()->getCourses());


    QMessageBox::information(
        this, tr("Aviso"),
        tr("Você comprou o curso!")
    );
}

void clientPage::on_tabWidget_currentChanged(int index)
{
    if (index == 0) {
        this->load_client_courses(this->model->getUser()->getCourses());
    } else if (index == 1 ){
        this->load_all_courses(this->model->getCourses());
    }
}

void clientPage::on_logout_btn_clicked()
{
    model->setUser(nullptr);
    QMessageBox::information(
        this, tr("Logout"),
        tr("Você foi deslogado do sistema!")
    );
    this->close();

    login* l = new login();
    l->setModel(model);
    l->exec();

}

void clientPage::on_tabWidget_tabBarClicked(int index)
{
    setTableData();
}

void clientPage::on_btn_search_new_clicked()
{
    vector<Course*> courses;
    qDebug()<<"Banco de dados não esta aberto";
    string name = ui->txt_search_new->text().toStdString();
    for(auto it : model->getCourses())
        if(it->getName() == name){
           courses.push_back(it);
           qDebug()<<"Banco de dados não esta aberto";

        }
    qDebug()<<"Banco de dados não esta aberto";

    load_all_courses(courses);

}

void clientPage::on_btn_search_clicked()
{
    vector<Course*> courses;
    string name = ui->txt_search->text().toStdString();
    for(auto it : model->getUser()->getCourses())
        if(it->getName() == name)
           courses.push_back(it);
    load_client_courses(courses);
}
