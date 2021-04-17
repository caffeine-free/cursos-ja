#ifndef EDITCLIENT_H
#define EDITCLIENT_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class editclient;
}

class editclient : public QDialog
{
    Q_OBJECT

public:
    explicit editclient(QWidget *parent = nullptr);
    ~editclient();

private slots:
    void on_cancel_btn_edit_client_clicked();

    void on_update_btn_clicked();

    void on_remove_profile_btn_clicked();

private:
    Ui::editclient *ui;
};

#endif // EDITCLIENT_H
