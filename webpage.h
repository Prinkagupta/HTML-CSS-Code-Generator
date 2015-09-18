#ifndef WEBPAGE_H
#define WEBPAGE_H

#include <QDialog>

namespace Ui {
class webpage;
}

class webpage : public QDialog
{
    Q_OBJECT
    
public:
    explicit webpage(QWidget *parent = 0);
    ~webpage();
    
private slots:
    void on_backButton_clicked();

    void on_launchButton_clicked();

private:
    Ui::webpage *ui;
};

#endif // WEBPAGE_H
