#ifndef CLIENTPAGE_H
#define CLIENTPAGE_H

#include <QDialog>
#include <QMessageBox>
#include <vector>

#include "editclient.h"
#include "../cursos-ja/src/lib/model.h"

namespace Ui {
class clientPage;
}

class clientPage : public QDialog
{
    Q_OBJECT

public:
    explicit clientPage(QWidget *parent = nullptr);
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

    void setTableData();

    void load_client_courses(const vector<Course*>&);

    void load_all_courses(const vector<Course*>&);

private slots:
    void buy_button_pressed();

    void on_edit_profile_btn_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_logout_btn_clicked();

    void on_tabWidget_tabBarClicked(int index);

    void on_btn_search_new_clicked();

    void on_btn_search_clicked();

private:
    Ui::clientPage *ui;
    Model* model;

    editclient* ec;
};

#endif // CLIENTPAGE_H
