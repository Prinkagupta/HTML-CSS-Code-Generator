#ifndef MENU_H
#define MENU_H

#include <QDialog>

namespace Ui {
class menu;
}

class menu : public QDialog
{
    Q_OBJECT
    
public:
    explicit menu(QWidget *parent = 0);
    ~menu();
    
private slots:
    void on_backButton_clicked();

    void on_borderButton_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_submitButton_clicked();

    void on_launchButton_clicked();

private:
    Ui::menu *ui;
    void htmlcode();
};

#endif // MENU_H
