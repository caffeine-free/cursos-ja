#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QMainWindow>
#include <QDebug>
#include <QFileInfo>
#include "login_admpage.h"
#include "registerview.h"

namespace Ui {
class login;
}
/**
 * @brief this class representer a Login UI
 *
 */
class login : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Construct a new Login object
     *
     * @param parent
     */
    explicit login(QWidget *parent = nullptr);
    /**
     * @brief Destroy the Login object
     *
     */
    ~login();
    /**
     * @brief Get the Reg object
     *
     * @return RegisterView* the registerView pointer
     */
    registerview *getReg() const;

    /**
     * @brief Set the Reg object
     *
     * @param value the registerView pointer
     */
    void setReg(registerview *value);

    Model *getModel() const;
    void setModel(Model *value);

    login_admpage* getLoginAdmPage() const;

    void setLoginAdmPage(login_admpage *value);


private slots:
    /**
     * @brief the function button
     *
     */
    void on_btn_admPage_clicked();
    /**
     * @brief the function button
     *
     */
    void on_pushButton_clicked();
    /**
     * @brief the function button
     *
     */
    void on_btn_newClient_clicked();

private:
    Ui::login *ui;
    Model* model;
    registerview* reg;

    login_admpage* l_admpage;
};

#endif // LOGIN_H
