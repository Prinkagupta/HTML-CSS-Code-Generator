#include "border.h"
#include "ui_border.h"
#include<QtCore/QFile>
#include<QtCore/QTextStream>

border::border(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::border)
{
    ui->setupUi(this);
     ui->cBBorderStyle->addItem("Solid");
    ui->cBBorderStyle->addItem("Dotted");
    ui->cBBorderStyle->addItem("Double");
    ui->cBBorderStyle->addItem("Dashed");
    ui->cBBorderColour->addItem("Aqua");
    ui->cBBorderColour->addItem("Blue");
    ui->cBBorderColour->addItem("Violet");
    ui->cBBorderColour->addItem("Pink");
    ui->cBBorderColour->addItem("Lime");
    ui->cBBorderColour->addItem("Orange");
    ui->cBBorderColour->addItem("Red");
    ui->cBBorderColour->addItem("Turquoise");
    ui->cBBorderColour->addItem("White");
    ui->cBBorderColour->addItem("Yellow");
    ui->tEBorderWidth->setText("10");
}

border::~border()
{
    delete ui;
}

void border::on_backButton_clicked()
{
     this->close();
}

void border::on_submitButton_clicked()
{
    ui->doneLabel->setText("SUBMITTED");
    storeBorderStyle();
    storeBorderColour();
    storeBorderWidth();
}
void border::storeBorderStyle(){
    QFile borderStyle("border.txt");
     borderStyle.open(QFile::WriteOnly|QIODevice::Text);
     QTextStream borderStyleStream(&borderStyle);
    QString borderStyleString = ui->cBBorderStyle->currentText();
    if(borderStyleString=="Dotted")
        borderStyleStream<<"border-style:dotted;\n";
    if(borderStyleString=="Solid")
        borderStyleStream<<"border-style:solid;\n";
    if(borderStyleString=="Double")
        borderStyleStream<<"border-style:double;\n";
    if(borderStyleString=="Dashed")
        borderStyleStream<<"border-style:dashed;\n";
    borderStyle.close();
 }
void border::storeBorderColour(){
    QFile borderColour("border.txt");
     borderColour.open(QFile::Append|QIODevice::Text);
     QTextStream borderColourStream(&borderColour);
    QString borderColourString = ui->cBBorderColour->currentText();
    if(borderColourString=="Aqua")
        borderColourStream<<"border-color:#00FFFF;\n";
    if(borderColourString=="Blue")
        borderColourStream<<"border-color:#0000FF;\n";
    if(borderColourString=="Violet")
        borderColourStream<<"border-color:#EE82EE;\n";
    if(borderColourString=="Pink")
        borderColourStream<<"border-color:#FF69B4;\n";
    if(borderColourString=="Lime")
        borderColourStream<<"border-color:#00FF00;\n";
    if(borderColourString=="Orange")
        borderColourStream<<"border-color:#FFA500;\n";
    if(borderColourString=="Red")
        borderColourStream<<"border-color:#FF0000;\n";
    if(borderColourString=="Turquoise")
        borderColourStream<<"border-color:#40E0D0;\n";
    if(borderColourString=="White")
        borderColourStream<<"border-color:#FFFFFF;\n";
    if(borderColourString=="Yellow")
        borderColourStream<<"border-color:#FFFF00;\n";
    borderColour.close();
 }
void border::storeBorderWidth(){

    QFile borderWidth("border.txt");
     borderWidth.open(QFile::Append|QIODevice::Text);
     QTextStream borderWidthStream(&borderWidth);
     QString borderWidthString =ui->tEBorderWidth->toPlainText();
     borderWidthStream<<"border-width:"<<borderWidthString<<"px;";
     borderWidth.close();
 }
