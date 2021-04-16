#include "add_course.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    add_comment w;
    w.show();
    return a.exec();
}
