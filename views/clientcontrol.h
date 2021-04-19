#ifndef CLIENTCONTROL_H
#define CLIENTCONTROL_H

#include <QDialog>
#include <QMessageBox>

#include "../cursos-ja/src/lib/model.h"

namespace Ui {
class ClientControl;
}

class ClientControl : public QDialog
{
    Q_OBJECT

public:
    explicit ClientControl(QWidget *parent = nullptr);
    ~ClientControl();

    Model* getModel() const;

    void setModel(Model *value);

    /**
     * @brief Set the Table Data object
     *
     */
    void setTableData();

    void load_course_data();

    void load_user_data();
private slots:
    void on_pushButton_clicked();

    void on_tabWidget_currentChanged(int index);

    void edit_course_button_pressed();

    void remove_course_button_pressed();

    void remove_user_pressed();

    void edit_user_pressed();

    void on_exit_adm_btn_clicked();

    void on_edit_adm_client_btn_clicked();

    void on_add_user_btn_clicked();

    void on_tabWidget_tabBarClicked(int index);

private:
    Ui::ClientControl *ui;
    Model* model;
};

#endif // CLIENTCONTROL_H
