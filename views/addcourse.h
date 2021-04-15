#ifndef ADDCOURSE_H
#define ADDCOURSE_H

#include <QDialog>
#include <QMessageBox>
#include "./src/lib/model.h"

namespace Ui {
class addCourse;
}

class addCourse : public QDialog
{
    Q_OBJECT

public:
    explicit addCourse(QWidget *parent = nullptr);
    ~addCourse();

    Model* getModel() const;

    void setModel(Model *model);

    void initialize();

private slots:
    void on_save_button_clicked();

private:
    Ui::addCourse *ui;
    Model* model;
};

#endif // ADDCOURSE_H


