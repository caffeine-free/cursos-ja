#ifndef EDITCLIENT_H
#define EDITCLIENT_H

#include <QDialog>
#include <QMessageBox>

#include "../cursos-ja/src/lib/model.h"
#include "../cursos-ja/src/classes/user.h"

namespace Ui {
class editclient;
}

class editclient : public QDialog
{
    Q_OBJECT

public:
    explicit editclient(QWidget *parent = nullptr);
    ~editclient();

    User *getUser() const;

    void setUser(User *value);

    Model *getModel() const;

    void setModel(Model *value);

private slots:
    void on_cancel_btn_edit_client_clicked();

    void on_update_btn_clicked();

    void on_remove_profile_btn_clicked();

private:
    Ui::editclient *ui;
    Model* model;
    User* user;
};

#endif // EDITCLIENT_H
