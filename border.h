#ifndef BORDER_H
#define BORDER_H

#include <QDialog>

namespace Ui {
class border;
}

class border : public QDialog
{
    Q_OBJECT
    
public:
    explicit border(QWidget *parent = 0);
    ~border();
    void storeBorderStyle();
    void storeBorderColour();
    void storeBorderWidth();
private slots:
    void on_backButton_clicked();

    void on_submitButton_clicked();

private:
    Ui::border *ui;
};

#endif // BORDER_H
