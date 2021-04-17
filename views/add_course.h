#ifndef ADD_COURSE_H
#define ADD_COURSE_H

#include <QWidget>

namespace Ui {
class add_course;
}

class add_course : public QWidget
{
    Q_OBJECT

public:
    explicit add_course(QWidget *parent = nullptr);
    ~add_course();

private:
    Ui::add_course *ui;
};

#endif // ADD_COURSE_H
