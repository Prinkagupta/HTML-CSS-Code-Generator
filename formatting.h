#ifndef FORMATTING_H
#define FORMATTING_H

#include <QDialog>

namespace Ui {
class formatting;
}

class formatting : public QDialog
{
    Q_OBJECT
    
public:
    explicit formatting(QWidget *parent = 0);
    ~formatting();
    
private slots:
    void on_pushButton_2_clicked();

    void on_backButton_clicked();

    void on_submitButton_clicked();

private:
    Ui::formatting *ui;
 void   bold();
     void italic();
     void allignment();
     void underlin();
};

#endif // FORMATTING_H
