#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"hanoi.h"
#include<QMainWindow>
#include<QPainter>
#include<QRect>
#include<QRandomGenerator>
#include<QTimer>
#include<QVector>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private slots:
    void Ranmove();

    void Fastmove();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Hanoi *hanoi;
    Ui::MainWindow *ui;
    QTimer tick;
    int i=0;
    QTimer Ran;
    QTimer Fast;
    QVector<QPoint> move;
    int count=0;
    void paintEvent(QPaintEvent *event)Q_DECL_OVERRIDE ;
    void HanoiMove(int number,char x,char y,char z);
};
#endif // MAINWINDOW_H
