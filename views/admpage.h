#ifndef ADMPAGE_H
#define ADMPAGE_H

#include <QDialog>

namespace Ui {
class admpage;
}

class admpage : public QDialog
{
    Q_OBJECT

public:
    explicit admpage(QWidget *parent = nullptr);
    ~admpage();

private:
    Ui::admpage *ui;
};

#endif // ADMPAGE_H
