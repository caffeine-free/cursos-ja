#ifndef EDIT_COURSE_H
#define EDIT_COURSE_H

#include <QWidget>

namespace Ui {
class edit_course;
}

class edit_course : public QWidget
{
    Q_OBJECT

public:
    explicit edit_course(QWidget *parent = nullptr);
    ~edit_course();

private:
    Ui::edit_course *ui;
};

#endif // EDIT_COURSE_H
