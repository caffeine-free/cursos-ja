#include  "views/login.h"
#include "views/clientpage.h"
#include "views/clientcontrol.h"

#include <iostream>

#include <QApplication>

int main(int argc, char* argv[]) {
    QApplication qapp(argc, argv);

    Model* model = Model::createModel();

    ClientControl* cc = new ClientControl();
    cc->setModel(model);

    login_admpage* ladm = new login_admpage();
    ladm->setModel(model);
    ladm->setClientControl(cc);

    login* l = new login();
    l->setModel(model);
    l->setLoginAdmPage(ladm);

    return l->exec();

    /*ClientControl* cp = new ClientControl();
    cp->setModel(model);
    cp->setTableData();
    return cp->exec();*/
}
