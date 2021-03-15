#include "element.h"

Element::Element(int level,int tower):level(level),tower(tower){
    MeRect.setRect(250-level*10,0,level*20,40);
}
void Element::Move(int target){
    switch (tower) {
    case 1:MeRect.setRect((target-1)*500+MeRect.x(),0,MeRect.width(),MeRect.height());break;
    case 2:MeRect.setRect((500*target)-1000+MeRect.x(),0,MeRect.width(),MeRect.height());break;
    case 3:MeRect.setRect((500*target)-1500+MeRect.x(),0,MeRect.width(),MeRect.height());break;
    }
    this->tower=target;
    return;
}

bool Element::Drop(){
    if(MeRect.y()<900){
        MeRect.adjust(0,1,0,1);
        return true;
    }
    return false;
}

void Element::Up(){
    MeRect.adjust(0,-10,0,-10);
}
