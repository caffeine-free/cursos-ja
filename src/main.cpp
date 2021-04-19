#include  "views/login.h"
#include "views/clientpage.h"
#include "views/clientcontrol.h"

#include <iostream>

#include <QApplication>

int main(int argc, char* argv[]) {
    QApplication qapp(argc, argv);

    Model* model = Model::createModel();

    login* l = new login();
    l->setModel(model);

    return l->exec();
}
