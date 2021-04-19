#ifndef EDITCOURSE_H
#define EDITCOURSE_H

#include <QDialog>
#include "../cursos-ja/src/classes/course.h"
#include "../cursos-ja/src/lib/model.h"

namespace Ui {
class EditCourse;
}

class EditCourse : public QDialog
{
    Q_OBJECT

public:
    explicit EditCourse(QWidget *parent = nullptr);
    ~EditCourse();

    Course *getCourse() const;

    void setCourse(Course *value);

    Model *getModel() const;

    void setModel(Model *value);

private slots:
    void on_edit_btn_clicked();

    void on_CANCEL_clicked();

private:
    Ui::EditCourse *ui;
    Model* model;
    Course* course;
};

#endif // EDITCOURSE_H
