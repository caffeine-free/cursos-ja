
#include  "views/addcourse.h"

#include <QApplication>

int main(int argc, char* argv[]) {
    QApplication qapp(argc, argv);

    Model* model = Model::createModel();

    addCourse* addcourse = new addCourse();
    addcourse->setModel(model);

    return addcourse->exec();

}
