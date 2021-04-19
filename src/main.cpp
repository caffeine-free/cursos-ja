#include  "views/login.h"
#include "views/clientpage.h"
#include "views/clientcontrol.h"

#include <iostream>

#include <QApplication>

int main(int argc, char* argv[]) {
    QApplication qapp(argc, argv);

    Model* model = Model::createModel();

    /*ClientControl* cc = new ClientControl();
    cc->setModel(model);

<<<<<<< HEAD
    login login;

    return login.exec();
    //return addcourse->exec();
=======
    login_admpage* ladm = new login_admpage();
    ladm->setModel(model);
    ladm->setClientControl(cc);

    login* l = new login();
    l->setModel(model);
    l->setLoginAdmPage(ladm);
>>>>>>> 610edd4b87bc8ac898993eafd1ccac2273574c9c

    return l->exec();

    */


    /*ClientControl* cp = new ClientControl();
    cp->setModel(model);
    cp->setTableData();
<<<<<<< HEAD
    cp->load_all_clients();
    cp->exec();*/
=======
    return cp->exec();

    /*
    clientPage* cpage = new clientPage();
    cpage->setModel(model);
    cpage->exec(); */

>>>>>>> 610edd4b87bc8ac898993eafd1ccac2273574c9c
}
