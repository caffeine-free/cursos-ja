#ifndef DELETE_COURSE_H
#define DELETE_COURSE_H

#include <QWidget>

namespace Ui {
class delete_course;
}

class delete_course : public QWidget
{
    Q_OBJECT

public:
    explicit delete_course(QWidget *parent = nullptr);
    ~delete_course();

private:
    Ui::delete_course *ui;
};

#endif // DELETE_COURSE_H
