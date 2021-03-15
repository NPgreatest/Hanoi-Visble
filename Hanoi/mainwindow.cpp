#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&tick,  SIGNAL(timeout()), this, SLOT(update()));
    connect(&Ran,  SIGNAL(timeout()), this, SLOT(Ranmove()));
    connect(&Fast,  SIGNAL(timeout()), this, SLOT(Fastmove()));
    tick.start(5);
}

MainWindow::~MainWindow(){
    delete ui;
    if(!hanoi) delete hanoi;
}

void MainWindow::Ranmove(){
    int target=QRandomGenerator::global()->bounded(0,count);
    int tower=QRandomGenerator::global()->bounded(1,4);
    int i,k;
   a: while(!hanoi->IsTop(target)){
        target=QRandomGenerator::global()->bounded(0,count);
    }
    while(!hanoi->move(target,tower)){
        tower=QRandomGenerator::global()->bounded(1,4);
        target=QRandomGenerator::global()->bounded(0,count);
    goto a;
    }

    for(k=0;k<count;k++)
        for(i=0;i<count;i++)
            hanoi->Drop(i);
    if(hanoi->Success())
        Ran.stop();
}

void MainWindow::Fastmove(){
    hanoi->move(move.at(i).x(),move.at(i).y());
    i++;
    if(hanoi->Success())
        Fast.stop();
}

void MainWindow::paintEvent(QPaintEvent *event){
    int i;
    QPainter painter(this);
    painter.drawLine(QPoint(250,0),QPoint(250,940));
    painter.drawLine(QPoint(750,0),QPoint(750,940));
    painter.drawLine(QPoint(1250,0),QPoint(1250,940));
    painter.drawLine(QPoint(0,940),QPoint(1500,940));
    for(i=0;i<count;i++){
        painter.drawRect(hanoi->GetRect(i));
        painter.fillRect(hanoi->GetRect(i),QBrush(Qt::SolidPattern));
    }
}

void MainWindow::HanoiMove(int number,char x,char y,char z){
    if(number==count-1){
        switch (z) {
        case 'x':move.append(QPoint(number,1));break;
        case 'y':move.append(QPoint(number,2));break;
        case 'z':move.append(QPoint(number,3));break;
        }
    }
    else{
        HanoiMove(number+1,x,z,y);
        switch (z) {
        case 'x':move.append(QPoint(number,1));break;
        case 'y':move.append(QPoint(number,2));break;
        case 'z':move.append(QPoint(number,3));break;
        }
        HanoiMove(number+1,y,x,z);
    }
}


void MainWindow::on_pushButton_clicked()
{
    count=ui->spinBox->value();
    if(!hanoi) delete hanoi;
    hanoi = new Hanoi(count);
    Ran.start(ui->spinBox_2->value());
    Fast.stop();
}


void MainWindow::on_pushButton_2_clicked()
{
    if(!hanoi) delete hanoi;
    count=ui->spinBox->value();
    hanoi = new Hanoi(count);
    HanoiMove(0,'x','y','z');
    i=0;
    move.clear();
    Fast.start(ui->spinBox_3->value());
    Ran.stop();
}
