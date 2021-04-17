#include "clientpage.h"
#include "ui_clientpage.h"

clientPage::clientPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::clientPage)
{
    ui->setupUi(this);

    ui->table_client_courses->setColumnCount(2);
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
    ec->exec();
}

void clientPage::on_tabWidget_currentChanged(int index)
{
    if (index == 1 ){
        int contlinhas = 0;
        // remove os produtos de tw
        /*QSqlQuery query;
        query.prepare("select name, price from users where user.email = x");

        if (query.exec()){
            while ( query.next() ){
                ui->table_client_courses->insertRow(contlinhas);
                ui->table_client_courses->setItem(contlinhas, 0, new Qtable_client_coursesItem(query.value(0).toString()));
                ui->table_client_courses->setItem(contlinhas, 1, new Qtable_client_coursesItem(query.value(1).toString()));
                ui->table_client_courses->setRowHeight(contlinhas, 20);
                contlinhas++;
            }

            ui->table_client_courses->setColumnWidth(0, 150);
            ui->table_client_courses->setColumnWidth(0, 150);

            QStringList headers = {"Name", "Price"};
            ui->table_client_courses->setStyleSheet("QTable View {selection=background-color: red}");
            ui->table_client_courses->setEditTriggers(QAbstractItemView::NoEditTriggers);
            ui->table_client_courses->setSelectionBehavior(QAbstractItemView::SelectRows);
            ui->table_client_courses->verticalHeader()->setVisible(false);
        }*/

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
}
