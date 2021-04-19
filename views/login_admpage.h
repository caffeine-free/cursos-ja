#ifndef LOGIN_ADMPAGE_H
#define LOGIN_ADMPAGE_H

#include <QDialog>
#include <QMessageBox>
#include "clientcontrol.h"

namespace Ui {
class login_admpage;
}

/**
 * @brief this class represents the authentication performed by the administrator before being redirected to the administrative page
 * 
 */
class login_admpage : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Construct a new login admpage object
     * 
     * @param parent 
     */
    explicit login_admpage(QWidget *parent = nullptr);

    /**
     * @brief Destroy the login admpage object
     * 
     */
    ~login_admpage();

    /**
     * @brief Get the Model object
     * 
     * @return Model* the Login's model
     */
    Model* getModel() const;

    /**
     * @brief Set the Model object
     * 
     * @param value The new model
     */
    void setModel(Model *value);

    /**
     * @brief Get the Client Control object
     * 
     * @return ClientControl* the Client Control page to be redirected
     */
    ClientControl* getClientControl() const;

    /**
     * @brief Set the Client Control object
     * 
     * @param value the new Client Control page
     */
    void setClientControl(ClientControl *value);

private slots:
    /**
     * @brief the button to validate the login
     * 
     */
    void on_pushButton_clicked();

private:
    Ui::login_admpage *ui; // The Login's ui
    Model* model; // The Login's model
    ClientControl* admpage; // The Login's adm page
};

#endif // LOGIN_ADMPAGE_H
