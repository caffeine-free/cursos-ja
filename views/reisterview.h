#ifndef REISTERVIEW_H
#define REISTERVIEW_H

#include <QDialog>

namespace Ui {
class reisterview;
}

class reisterview : public QDialog
{
    Q_OBJECT

public:
    explicit reisterview(QWidget *parent = nullptr);
    ~reisterview();

private:
    Ui::reisterview *ui;
};

#endif // REISTERVIEW_H
