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

    /**
     * @brief Get the Model object
     * 
     * @return Model* the Login's model
     */
    Model *getModel() const;

    /**
     * @brief Set the Model object
     * 
     * @param value the Login's new model
     */
    void setModel(Model *value);

    /**
     * @brief Get the Login Adm Page object
     * 
     * @return login_admpage* the Login's Admpage
     */
    login_admpage* getLoginAdmPage() const;

    /**
     * @brief Set the Login Adm Page object
     * 
     * @param value the new Login's Admpage
     */
    void setLoginAdmPage(login_admpage *value);


private slots:
    /**
     * @brief the function button to redirect to the Admpage
     *
     */
    void on_btn_admPage_clicked();
    /**
     * @brief the function button
     *
     */
    void on_pushButton_clicked();
    /**
     * @brief the function button to redirect to the register user view
     *
     */
    void on_btn_newClient_clicked();

private:
    Ui::login *ui; // The Login's ui
    Model* model; // The Login's model
    registerview* reg; // The Login's register view to be redirected

    login_admpage* l_admpage; // The Login's Login Admpage's to be redirected
};

#endif // LOGIN_H