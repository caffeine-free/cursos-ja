#include  "views/addcourse.h"
#include  "views/login.h"

#include <QApplication>

int main(int argc, char* argv[]) {
    QApplication qapp(argc, argv);

    Model* model = Model::createModel();

   /* addCourse* addcourse = new addCourse();
    addcourse->setModel(model);*/

    login login;

    return login.exec();
}
