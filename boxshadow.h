#ifndef BOXSHADOW_H
#define BOXSHADOW_H

#include <QDialog>

namespace Ui {
class boxShadow;
}

class boxShadow : public QDialog
{
    Q_OBJECT
    
public:
    explicit boxShadow(QWidget *parent = 0);
    ~boxShadow();
    
private slots:
    void on_backButton_clicked();

private:
    Ui::boxShadow *ui;
};

#endif // BOXSHADOW_H
