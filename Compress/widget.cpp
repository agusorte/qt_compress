#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <iostream>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                               "~",
                               tr("ROSBAG (*.bag)"));
    std::string cmd, cmd2, fname;

    fname =  fileName.toUtf8().constData();

    cmd2 = "cp " + fname  + " " + fname +".old" ;
    cmd = "rosbag compress " + fname +" --output-dir=compressed";

    std::cout<<"debug "<<cmd2 <<std::endl;
    std::cout<<"  "<<cmd <<std::endl;


    if (!fileName.isEmpty())
    {

    }
    else{
      //exec data
      //system(cmd2.c_str());
      system(cmd.c_str());

    }
}
