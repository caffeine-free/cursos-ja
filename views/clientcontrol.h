#ifndef CLIENTCONTROL_H
#define CLIENTCONTROL_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class ClientControl;
}

class ClientControl : public QDialog
{
    Q_OBJECT

public:
    explicit ClientControl(QWidget *parent = nullptr);
    ~ClientControl();

private slots:
    void on_pushButton_clicked();

    void on_tabWidget_currentChanged(int index);

private:
    Ui::ClientControl *ui;
};

#endif // CLIENTCONTROL_H
