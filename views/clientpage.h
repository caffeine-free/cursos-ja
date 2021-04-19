#ifndef CLIENTPAGE_H
#define CLIENTPAGE_H

#include <vector>

#include "editclient.h"

/**
 * @brief this class represents the client page
 * 
 */
namespace Ui {
class clientPage;
}

class clientPage : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Construct a new client Page object
     * 
     * @param parent 
     */
    explicit clientPage(QWidget *parent = nullptr);

    /**
     * @brief Destroy the client Page object
     * 
     */
    ~clientPage();

    /**
     * @brief Get the Model object
     *
     * @return Model* the model pointer
     */
    Model *getModel() const;

    /**
     * @brief Set the Model object
     *
     * @param value the model pointer
     */
    void setModel(Model *value);

    /**
     * @brief Get the Login object
     *
     * @return Login* the login pointer
     */
    editclient *getEditClient() const;

    /**
     * @brief Set the Login object
     *
     * @param value the login pointer
     */
    void setEditClient(editclient *value);

    /**
     * @brief Configure the TableWidget objects
     * 
     */
    void setTableData();

    /**
     * @brief Load the Client's courses
     * 
     */
    void load_client_courses(const vector<Course*>&);

    /**
     * @brief Load all the Model's courses
     * 
     */
    void load_all_courses(const vector<Course*>&);

private slots:
    /**
     * @brief function to buy a new course
     * 
     */
    void buy_button_pressed();

    /**
     * @brief function to edit a user
     * 
     */
    void on_edit_profile_btn_clicked();

    /**
     * @brief function to reload the table data when necesary
     * 
     * @param index 
     */
    void on_tabWidget_currentChanged(int index);

    /**
     * @brief function to logout
     * 
     */
    void on_logout_btn_clicked();

    /**
     * @brief function do load the table data
     * 
     * @param index 
     */
    void on_tabWidget_tabBarClicked(int index);

    /**
     * @brief function to search courses
     * 
     */
    void on_btn_search_new_clicked();

    /**
     * @brief function to throw the search
     * 
     */
    void on_btn_search_clicked();

private:
    Ui::clientPage *ui; // The Client Page's ui
    Model* model; // The Client Page's model

    editclient* ec; // The Client Page's edit client to be redirected
};

#endif // CLIENTPAGE_H
