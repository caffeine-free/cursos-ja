#ifndef UPDATECOURSE_H
#define UPDATECOURSE_H

#include <QDialog>

#include "../src/lib/model.h"

namespace Ui {
class UpdateCourse;
}

class UpdateCourse : public QDialog
{
    Q_OBJECT

public:
    explicit UpdateCourse(QWidget *parent = nullptr);
    ~UpdateCourse();

    Model *getModel() const;

    void setModel(Model *value);


private slots:
    void on_updateCourse_btn_clicked();

    void on_cancel_btn_clicked();

private:
    Ui::UpdateCourse *ui;
    Model* model;
    Course* course;
};

#endif // UPDATECOURSE_H
