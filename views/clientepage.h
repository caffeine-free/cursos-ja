#ifndef CLIENTEPAGE_H
#define CLIENTEPAGE_H

#include <QDialog>

namespace Ui {
class ClientePage;
}

class ClientePage : public QDialog
{
    Q_OBJECT

public:
    explicit ClientePage(QWidget *parent = nullptr);
    ~ClientePage();

private:
    Ui::ClientePage *ui;
};

#endif // CLIENTEPAGE_H
