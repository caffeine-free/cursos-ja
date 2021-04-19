#include  "views/login.h"
#include "views/clientpage.h"
#include "views/clientcontrol.h"

#include <iostream>

#include <QApplication>

int main(int argc, char* argv[]) {
    QApplication qapp(argc, argv);

    Model* model = Model::createModel();

    /*ClientControl* cc = new ClientControl();
    cc->setTableData();
    cc->setModel(model);*/

    /*login_admpage* ladm = new login_admpage();
    ladm->setModel(model);
    ladm->setClientControl(cc);*/

    login* l = new login();
    l->setModel(model);
    //l->setLoginAdmPage(ladm);

    return l->exec();

  /* ClientControl* cp = new ClientControl();
    cp->setModel(model);
    cp->setTableData();
    cp->load_user_data();
    //cp->exec();
    return cp->exec();*/

    /*
    clientPage* cpage = new clientPage();
    cpage->setModel(model);
    cpage->exec(); */
}
