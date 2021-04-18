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
    void load_all_clients();
private slots:
    void on_pushButton_clicked();

    void on_tabWidget_currentChanged(int index);


    void on_btn_clientedit_clicked();

    void on_btn_clientdelete_clicked();

    void on_btn_clientlogout_clicked();

    void on_btn_clientsearch_clicked();

private:
    Ui::ClientControl *ui;
    Model* model;
};

#endif // CLIENTCONTROL_H
