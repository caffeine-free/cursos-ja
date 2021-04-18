#include  "views/add_course.h"
#include  "views/login.h"
#include "views/clientpage.h"
#include "views/clientcontrol.h"

#include <iostream>

#include <QApplication>

int main(int argc, char* argv[]) {
    QApplication qapp(argc, argv);

    Model* model = Model::createModel();

   /* addCourse* addcourse = new addCourse();
    addcourse->setModel(model);*/

    //login login;

    //return login.exec();
    //return addcourse->exec();

    /*editclient* ec = new editclient();

    clientPage* cp = new clientPage();
    cp->setModel(model);
    cp->setEditClient(ec);

    return cp->exec();*/

   /* clientPage* cp = new clientPage();
    cp->setModel(model);
    cp->setTableData();
    cp->exec();*/

    ClientControl* cp = new ClientControl();
    cp->setModel(model);
    cp->setTableData();
    cp->load_all_clients();
    cp->exec();
}
