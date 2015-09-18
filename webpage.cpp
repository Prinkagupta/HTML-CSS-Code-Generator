#include "webpage.h"
#include "ui_webpage.h"
#include<QtCore/QFile>
#include<QtCore/QTextStream>
#include<QDesktopServices>
#include<QUrl>
webpage::webpage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::webpage)
{
    ui->setupUi(this);
    ui->textEdit->setText("Add Text To Web Page");
     ui->textEdit_2->setText("Enter Image path");
}

webpage::~webpage()
{
    delete ui;
}

void webpage::on_backButton_clicked()
{
    this->close();
}

void webpage::on_launchButton_clicked()
{
    QString text=ui->textEdit->toPlainText();
    QString abc=ui->textEdit_2->toPlainText();
    QFile webPage("MyCode.html");
     webPage.open(QFile::WriteOnly|QIODevice::Text);
     QTextStream page(&webPage);

     QFile code("finalcode.txt");
     code.open(QFile::ReadOnly|QIODevice::Text);
      QTextStream finalcode(&code);
      QString c=finalcode.readAll();


      page<<"<html>\n<head>\n<style type=\"text/css\">\nbody {"<<c<<"}\n</style>\n</head>\n<body>\n"<<text<<"<img src=\""<<abc<<"\"/></body>\n</html>";
      code.close();
      webPage.close();
      //QString link="file:///C:/Qt/Qt5.0.2/Tools/QtCreator/bin/build-project-Desktop_Qt_5_0_2_MinGW_32bit-Debug/MyCode.html";
      QString link="file:///D:/college/my files/studies/4th sem/oops/project/build-project-Desktop_Qt_5_0_2_MinGW_32bit-Debug/MyCode.html";
      QDesktopServices::openUrl(QUrl(link));

}
