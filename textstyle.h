#ifndef TEXTSTYLE_H
#define TEXTSTYLE_H

#include <QDialog>

namespace Ui {
class textstyle;
}

class textstyle : public QDialog
{
    Q_OBJECT
    
public:
    explicit textstyle(QWidget *parent = 0);
    ~textstyle();
    
private slots:
    void on_backButton_clicked();

    void on_submitButton_clicked();

private:
    Ui::textstyle *ui;
    void storeFontcolour();
    void storeFontStyle();
    void storeFontSize();
};

#endif // TEXTSTYLE_H
