#ifndef READ_COURSE_H
#define READ_COURSE_H

#include <QWidget>

namespace Ui {
class read_course;
}

class read_course : public QWidget
{
    Q_OBJECT

public:
    explicit read_course(QWidget *parent = nullptr);
    ~read_course();

private:
    Ui::read_course *ui;
};

#endif // READ_COURSE_H
