#include "formatting.h"
#include "ui_formatting.h"
#include<QtCore/QFile>
#include<QtCore/QTextStream>
//std::endl;

formatting::formatting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::formatting)
{
    ui->setupUi(this);
    ui->cBAllignmnt->addItem("Right");
    ui->cBAllignmnt->addItem("Center");
    ui->cBAllignmnt->addItem("Justify");
    ui->cBTextDecoration->addItem("None");
    ui->cBTextDecoration->addItem("Overline");
    ui->cBTextDecoration->addItem("Line-through");
    ui->cBTextDecoration->addItem("Underline");
}

formatting::~formatting()
{
    delete ui;
}

void formatting::on_backButton_clicked()
{
   this->close();
}

void formatting::on_submitButton_clicked()
{
    ui->submitLabel->setText("SUBMITTED");
    bold();
    italic();
    allignment();
    underlin();
}
void formatting::bold(){
    QFile formatting("formatting.txt");
     formatting.open(QFile::WriteOnly|QIODevice::Text);
    if(ui->chkBold->isChecked())
    {
        QTextStream formattingStream(&formatting);
        formattingStream<<"font-weight: bold;\n";
                           formatting.close();

     }
}
void formatting::italic(){
    if(ui->chkItalic->isChecked())
    {
        QFile formatting("formatting.txt");
         formatting.open(QFile::Append|QIODevice::Text);
         QTextStream formattingStream(&formatting);

         formattingStream<<"font-style: italic;\n";
                           formatting.close();

    }
}
void formatting::allignment(){
    QFile formatting("formatting.txt");
     formatting.open(QFile::Append|QIODevice::Text);
    QTextStream formattingStream(&formatting);

    QString allign= ui->cBAllignmnt->currentText();
    if(allign=="Center")
        formattingStream<<"text-align:center;\n";
    if(allign=="Right")
        formattingStream<<"text-align:right;\n";
    if(allign=="Justify")
        formattingStream<<"text-align:justify;\n";
    formatting.close();
}
void formatting::underlin(){
    QFile formatting("formatting.txt");
     formatting.open(QFile::Append|QIODevice::Text);
    QTextStream formattingStream(&formatting);

    QString textDecor= ui->cBTextDecoration->currentText();
    if(textDecor=="Overline")
        formattingStream<<"text-decoration:overline;";
    if(textDecor=="Line-through")
        formattingStream<<"text-decoration:line-through;";
    if(textDecor=="Underline")
        formattingStream<<"text-decoration:underline;";
    if(textDecor=="None")
    {}
    formatting.close();
}
