#ifndef EDITCLIENT_H
#define EDITCLIENT_H

#include <QDialog>
#include <QMessageBox>

#include "../cursos-ja/src/lib/model.h"
#include "../cursos-ja/src/classes/user.h"

namespace Ui {
class editclient;
}

/**
 * @brief This class represents the page to edit the user's values
 * 
 */
class editclient : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Construct a new editclient object
     * 
     * @param parent 
     */
    explicit editclient(QWidget *parent = nullptr);

    /**
     * @brief Destroy the editclient object
     * 
     */
    ~editclient();

    /**
     * @brief Get the User object
     * 
     * @return User* the User to be updated
     */
    User *getUser() const;

    /**
     * @brief Set the User object
     * 
     * @param value the User to be updated
     */
    void setUser(User *value);

    /**
     * @brief Get the Model object
     * 
     * @return Model* the Edit Client's model
     */
    Model *getModel() const;

    /**
     * @brief Set the Model object
     * 
     * @param value the new Edit Client's model
     */
    void setModel(Model *value);

private slots:
    /**
     * @brief function to cancel the update
     * 
     */
    void on_cancel_btn_edit_client_clicked();

    /**
     * @brief function to update profile
     * 
     */
    void on_update_btn_clicked();

    /**
     * @brief function to remove profile
     * 
     */
    void on_remove_profile_btn_clicked();

private:
    Ui::editclient *ui; // The Edit's ui
    Model* model; // The Edit's model
    User* user; // The Edit's user
};

#endif // EDITCLIENT_H
