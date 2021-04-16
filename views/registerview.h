#ifndef REGISTERVIEW_H
#define REGISTERVIEW_H

#include <QDialog>
#include <QtSql>
#include <QMessageBox>
#include "src/lib/register.h"

namespace Ui {
class registerview;
}
/**
 * @brief this class representer a RegisterView UI
 *
 */
class registerview : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Construct a new Register View object
     *
     * @param parent
     */
    explicit registerview(QWidget *parent = nullptr);
    /**
     * @brief Destroy the Register View object
     *
     */
    ~registerview();
    /**
     * @brief Get the Model object
     *
     * @return Model* the model pointer
     */
    Model* getModel() const;

    /**
     * @brief Set the Model object
     *
     */
    void setModel(Model*);

private slots:
    /**
     * @brief the button function
     *
     */
    void on_btn_cancel_clicked();

    /**
     * @brief the button function
     *
     */
    void on_btn_register_clicked();

private:
    Ui::registerview *ui;
    Model* model;
};

#endif // REGISTERVIEW_H
