#ifndef ELEMENT_H
#define ELEMENT_H
#include<QRect>

class Element
{
private:
    int level;
    int tower;
    QRect MeRect;
    friend class Hanoi;
public:
    QRect GetRect(){return MeRect;}
    bool Drop();
    void Up();
    Element(int level,int tower);
    void Move(int target);
};

#endif // ELEMENT_H
