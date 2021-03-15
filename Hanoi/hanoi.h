#ifndef HANOI_H
#define HANOI_H
#include"element.h"
#include<QRect>
#include<QTimer>
class Hanoi
{
private:
    int maxcount;
    Element *element[20];
private slots:

public:
    Hanoi(int maxcount);
    ~Hanoi(){;for(int i=0;i<20;i++)delete element[i];}
    bool move(int number,int tower);
    int GetLevel(int x) const {return element[x]->level;}
    QRect GetRect(int x) const {return element[x]->GetRect();}
    void Drop(int number);
    bool IsTop(int number);
    bool Success();
};

#endif // HANOI_H
