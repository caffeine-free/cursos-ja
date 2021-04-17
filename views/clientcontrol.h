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
private slots:
    void on_pushButton_clicked();

    void on_tabWidget_currentChanged(int index);

private:
    Ui::ClientControl *ui;
    Model* model;
};

#endif // CLIENTCONTROL_H
