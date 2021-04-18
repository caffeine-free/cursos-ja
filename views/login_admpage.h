#ifndef LOGIN_ADMPAGE_H
#define LOGIN_ADMPAGE_H

#include <QDialog>
#include <QMessageBox>
#include "admpage.h"
#include "clientcontrol.h"

namespace Ui {
class login_admpage;
}

class login_admpage : public QDialog
{
    Q_OBJECT

public:
    explicit login_admpage(QWidget *parent = nullptr);
    ~login_admpage();

    Model* getModel() const;

    void setModel(Model *value);

    ClientControl* getClientControl() const;

    void setClientControl(ClientControl *value);

private slots:
    void on_pushButton_clicked();

private:
    Ui::login_admpage *ui;
    Model* model;
    ClientControl* admpage;
};

#endif // LOGIN_ADMPAGE_H
