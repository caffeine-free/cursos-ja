#ifndef CLIENTCONTROL_H
#define CLIENTCONTROL_H

#include <QDialog>
#include <QMessageBox>

#include "../cursos-ja/src/lib/model.h"

namespace Ui {
class ClientControl;
}

/**
 * @brief this class represents the Adm Page
 * 
 */
class ClientControl : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Construct a new Client Control object
     * 
     * @param parent 
     */
    explicit ClientControl(QWidget *parent = nullptr);

    /**
     * @brief Destroy the Client Control object
     * 
     */
    ~ClientControl();

    /**
     * @brief Get the Model object
     * 
     * @return Model* the page's model
     */
    Model* getModel() const;

    /**
     * @brief Set the Model object
     * 
     * @param value the new page's model
     */
    void setModel(Model *value);

    /**
     * @brief Set the Table Data object
     *
     */
    void setTableData();

    /**
     * @brief Load the courses to Table Widget
     * 
     */
    void load_course_data();

    /**
     * @brief Load the users to Table Widget
     * 
     */
    void load_user_data();
private slots:
    /**
     * @brief function to edit course
     * 
     */
    void on_pushButton_clicked();

    /**
     * @brief function to load table's data
     * 
     * @param index the aba index 
     */
    void on_tabWidget_currentChanged(int index);

    /**
     * @brief function to edit course
     * 
     */
    void edit_course_button_pressed();

    /**
     * @brief function to remove course
     * 
     */
    void remove_course_button_pressed();

    /**
     * @brief function to remove user
     * 
     */
    void remove_user_pressed();

    /**
     * @brief function to edit user
     * 
     */
    void edit_user_pressed();

    /**
     * @brief function to logout
     * 
     */
    void on_exit_adm_btn_clicked();

    /**
     * @brief function to user insertion
     * 
     */
    void on_add_user_btn_clicked();

    /**
     * @brief load the Table Widget data
     * 
     * @param index 
     */
    void on_tabWidget_tabBarClicked(int index);

    /**
     * @brief Cancel user insertion
     * 
     */
    void on_cancel_client_btn_clicked();

    /**
     * @brief Cancel course insertion
     * 
     */
    void on_cancel_course_btn_clicked();

private:
    Ui::ClientControl *ui; // the page's ui
    Model* model; // the page's model
};

#endif // CLIENTCONTROL_H
