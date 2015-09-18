#ifndef TEXTSHADOW_H
#define TEXTSHADOW_H

#include <QDialog>

namespace Ui {
class textShadow;
}

class textShadow : public QDialog
{
    Q_OBJECT
    
public:
    explicit textShadow(QWidget *parent = 0);
    ~textShadow();
    
private slots:
    void on_backButton_clicked();

    void on_submitButton_clicked();

private:
    Ui::textShadow *ui;
   void storeVertical();
   void storeHorizontal();
    void storeColour();
};

#endif // TEXTSHADOW_H
