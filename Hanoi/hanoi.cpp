#include "hanoi.h"

Hanoi::Hanoi(int maxcount):maxcount(maxcount)
{
    int i;
    for(i=0;i<maxcount;i++){
        element[i] = new Element(maxcount-i,1);
        while(element[i]->Drop()){
            if(i!=0&&element[i-1]->GetRect().intersects(element[i]->GetRect())){
                element[i]->Up();
                break;
            }
            element[i]->Drop();
        }
    }
}
bool Hanoi::move(int number, int tower){
    int i;
    for(i=0;i<maxcount;i++){
        if(element[i]->tower==tower&&IsTop(i))
            break;
        if(i==maxcount-1) goto a;
    }
    if(element[i]->level<element[number]->level)return false;

   a: element[number]->Move(tower);
    Drop(number);
    return true;
}
bool Hanoi::Success(){
    int i;
    for(i=0;i<maxcount;i++){
        if(element[i]->level!=maxcount-i)
            return false;
    }
    for(i=0;i<maxcount;i++){
    if(element[i]->tower!=3)
            return false;
    }
    return true;
}
void Hanoi::Drop(int number){
    int i;
    while(element[number]->Drop()){
        for(i=0;i<maxcount;i++){
        if(element[i]->GetRect().intersects(element[number]->GetRect())&&number!=i){
            element[number]->Up();
            return;
            }
        }
    }
}
bool Hanoi::IsTop(int number){
    int y=element[number]->GetRect().center().y();
    int i;
    while(y>0){
        y-=2;
        for(i=0;i<maxcount;i++){
            if(element[i]->GetRect().contains(QPoint(element[number]->GetRect().center().x(),y))&&i!=number){
                return false;
            }
        }
    }
    return true;
}
