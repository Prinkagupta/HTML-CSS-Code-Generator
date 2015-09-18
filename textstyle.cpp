#include "textstyle.h"
#include "ui_textstyle.h"
#include<QtCore/QFile>
#include<QtCore/QTextStream>

textstyle::textstyle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::textstyle)
{
    ui->setupUi(this);
    ui->cBFontColour->addItem("Aqua");
    ui->cBFontColour->addItem("Blue");
    ui->cBFontColour->addItem("Violet");
    ui->cBFontColour->addItem("Pink");
    ui->cBFontColour->addItem("Lime");
    ui->cBFontColour->addItem("Orange");
    ui->cBFontColour->addItem("Red");
    ui->cBFontColour->addItem("Turquoise");
    ui->cBFontColour->addItem("White");
    ui->cBFontColour->addItem("Yellow");
    ui->tEFontSize->setText("40");
    ui->cBFontStyle->addItem("Arial");
    ui->cBFontStyle->addItem("Sans-Serif");
    ui->cBFontStyle->addItem("Fantasy");
    ui->cBFontStyle->addItem("Monospace");
    ui->cBFontStyle->addItem("Times New Roman");
}

textstyle::~textstyle()
{
    delete ui;
}

void textstyle::on_backButton_clicked()
{
    this->close();
}

void textstyle::on_submitButton_clicked()
{
    ui->submitLabel->setText("SUBMITTED");
    storeFontcolour();
    storeFontStyle();
    storeFontSize();
}
void textstyle::storeFontcolour()
{
    QFile fontColour("font.txt");
     fontColour.open(QFile::WriteOnly|QIODevice::Text);
     QTextStream fontColourStream(&fontColour);
    QString fontColourString = ui->cBFontColour->currentText();
    if(fontColourString=="Aqua")
        fontColourStream<<"color:#00FFFF;\n";
    if(fontColourString=="Blue")
        fontColourStream<<"color:#0000FF;\n";
    if(fontColourString=="Violet")
        fontColourStream<<"color:#EE82EE;\n";
    if(fontColourString=="Pink")
        fontColourStream<<"color:#FF69B4;\n";
    if(fontColourString=="Lime")
        fontColourStream<<"color:#00FF00;\n";
    if(fontColourString=="Orange")
        fontColourStream<<"color:#FFA500;\n";
    if(fontColourString=="Red")
        fontColourStream<<"color:#FF0000;\n";
    if(fontColourString=="Turquoise")
        fontColourStream<<"color:#40E0D0;\n";
    if(fontColourString=="White")
        fontColourStream<<"color:#FFFFFF;\n";
    if(fontColourString=="Yellow")
        fontColourStream<<"color:#FFFF00;\n";
    fontColour.close();
}
void textstyle:: storeFontStyle(){

    QFile fontStyle("font.txt");
     fontStyle.open(QFile::Append|QIODevice::Text);
     QTextStream fontStyleStream(&fontStyle);
    QString fontStyleString = ui->cBFontStyle->currentText();
    if(fontStyleString=="Arial")
        fontStyleStream<<"font-family:arial;\n";
    if(fontStyleString=="Sans-Serif")
        fontStyleStream<<"font-family:sans-serif;\n";
    if(fontStyleString=="Fantasy")
        fontStyleStream<<"font-family:fantasy;\n";
    if(fontStyleString=="Monospace")
        fontStyleStream<<"font-family:monospace;\n";
    if(fontStyleString=="Times New Roman")
        fontStyleStream<<"font-family:times new roman;\n";

    fontStyle.close();
}
void textstyle::storeFontSize(){

    QFile fontSize("font.txt");
     fontSize.open(QFile::Append);
     QTextStream fontSizeStream(&fontSize);
     QString fontSizeString =ui->tEFontSize->toPlainText();
     fontSizeStream<<"font-size:"<<fontSizeString<<"px;";
     fontSize.close();
}
