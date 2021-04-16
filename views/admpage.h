#ifndef ADMPAGE_H
#define ADMPAGE_H

#include <QDialog>
#include"../src/lib/model.h"

namespace Ui {
class admpage;
}

class admpage : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Construct a new Serie View object
     *
     * @param parent
     */
    explicit admpage(QWidget *parent = nullptr);

    ~admpage();

    void setTableData();
    Model *getModel() const;
    void setModel(Model *value);


private slots:
    void on_btn_search_clicked();

    void on_btn_delete_clicked();

    void on_btn_edit_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::admpage *ui;
    Model* model;
};

#endif // ADMPAGE_H
