#include<QtCore/QFile>
#include<QtCore/QTextStream>

#include "menu.h"
#include "ui_menu.h"
#include"border.h"
#include"textstyle.h"
#include"textshadow.h"
#include"formatting.h"
#include"webpage.h"
menu::menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);
}

menu::~menu()
{
    delete ui;
}

void menu::on_backButton_clicked()
{
    this->close();
}

void menu::on_pushButton_clicked()
{
    if(ui->bRadioButton->isChecked())
       {
        border m;
        m.setModal(true);

        m.exec();
    }
    if(ui->textStyleRadioButton->isChecked())
    {
        textstyle m;
        m.setModal(true);

        m.exec();

    }
    if(ui->textShadowRadioButton->isChecked())
    {
        textShadow m;
        m.setModal(true);

        m.exec();
    }
    if(ui->fomtgRadioButton->isChecked())
    {
        formatting m;
        m.setModal(true);

        m.exec();
    }
}



void menu::on_submitButton_clicked()
{
    htmlcode();
}
void menu::htmlcode()
{
    QFile code("finalcode.txt");

    code.open(QFile::WriteOnly|QIODevice::Text);
     QTextStream finalcode(&code);

     QFile borderr("border.txt");
    borderr.open(QFile::ReadOnly);
     QTextStream b(&borderr);
     QString part1 = b.readAll();

     QFile font("font.txt");
    font.open(QFile::ReadOnly);
     QTextStream f(&font);
     QString part2 = f.readAll();

     QFile formatting("formatting.txt");
    formatting.open(QFile::ReadOnly);
     QTextStream format(&formatting);
     QString part3 = format.readAll();

     QFile textshadow("textShadow.txt");
    textshadow.open(QFile::ReadOnly);
     QTextStream ts(&textshadow);
     QString part4 = ts.readAll();

     finalcode<<part1<<"\n"<<part2<<"\n"<<part3<<"\n"<<part4<<"\n";

    code.close();
    borderr.close();
    font.close();
    formatting.close();
    textshadow.close();


}
void menu::on_launchButton_clicked()
{   htmlcode();
    webpage m;
    m.setModal(true);

    m.exec();
}
