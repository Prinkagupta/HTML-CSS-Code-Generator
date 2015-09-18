#include "textshadow.h"
#include "ui_textshadow.h"
#include<QtCore/QFile>
#include<QtCore/QTextStream>

textShadow::textShadow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::textShadow)
{
    ui->setupUi(this);
    ui->cBShadowColour->addItem("Aqua");
    ui->cBShadowColour->addItem("Blue");
    ui->cBShadowColour->addItem("Violet");
    ui->cBShadowColour->addItem("Pink");
    ui->cBShadowColour->addItem("Lime");
    ui->cBShadowColour->addItem("Orange");
    ui->cBShadowColour->addItem("Red");
    ui->cBShadowColour->addItem("Turquoise");
    ui->cBShadowColour->addItem("White");
    ui->cBShadowColour->addItem("Yellow");
    ui->tEHorzLength->setText("20");
    ui->tEVertLength->setText("20");
}

textShadow::~textShadow()
{
    delete ui;
}

void textShadow::on_backButton_clicked()
{
    this->close();
}

void textShadow::on_submitButton_clicked()
{
    ui->submitLabel->setText("SUBMITTED");

    storeHorizontal();
    storeVertical();
    storeColour();
}
void textShadow::storeHorizontal(){

    QFile textShadow("textShadow.txt");
     textShadow.open(QFile::WriteOnly);
     QTextStream textShadowStream(&textShadow);
     QString textShadowHorizntLengthString =ui->tEHorzLength->toPlainText();
     textShadowStream<<"text-shadow:"<<textShadowHorizntLengthString<<"px ";
     textShadow.close();
}
void textShadow::storeVertical(){
    QFile textShadow("textShadow.txt");
     textShadow.open(QFile::Append);
     QTextStream textShadowStream(&textShadow);
     QString textShadowVerticalLengthString =ui->tEVertLength->toPlainText();
     textShadowStream<<textShadowVerticalLengthString<<"px ";
     textShadow.close();
}
void textShadow::storeColour(){

    QFile textShadow("textShadow.txt");
     textShadow.open(QFile::Append);
     QTextStream textShadowStream(&textShadow);
    QString textShadowColour = ui->cBShadowColour->currentText();
    if(textShadowColour=="Aqua")
        textShadowStream<<"#00FFFF;";
    if(textShadowColour=="Blue")
        textShadowStream<<"0000FF;";
    if(textShadowColour=="Violet")
        textShadowStream<<"#EE82EE;";
    if(textShadowColour=="Pink")
        textShadowStream<<"#FF69B4;";
    if(textShadowColour=="Lime")
        textShadowStream<<"#00FF00;";
    if(textShadowColour=="Orange")
        textShadowStream<<"#FFA500;";
    if(textShadowColour=="Red")
        textShadowStream<<"#FF0000;";
    if(textShadowColour=="Turquoise")
        textShadowStream<<"#40E0D0;";
    if(textShadowColour=="White")
        textShadowStream<<"#FFFFFF;";
    if(textShadowColour=="Yellow")
        textShadowStream<<"#FFFF00;";
    textShadow.close();

}
