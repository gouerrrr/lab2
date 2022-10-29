//
// Created by 余歌 on 2022/10/28.
//

#include "CityTree.h"


CityTree::CityTree(int x, int y, std::string name) {
    first=new City(x,y,name);
}

void CityTree::add(int x, int y, std::string name) {

    City*p=first;
    while (1)
    {
        if(name >p->name)
        {
            if(p->right){p=p->right; continue;}
            else{p->right=new City(x,y,name);break;}
        }
        else
        {
            if(p->left){p=p->left; continue;}
            else{p->left=new City(x,y,name);break;}
        }
    }
}

void CityTree::deleteByPos(int x, int y) {

}

void CityTree::deleteByName(std::string name) {
    City*p=first;
    if (first->name==name){ replaceRightestInLeft(first);}
    while (1)
    {
        if(name >p->name)
        {
            if(p->right->name==name)
        }
        else if(name<p->name)
        {
            p=p->left;
        }
    }
}

void CityTree::replaceRightestInLeft(City* root) {
    City* temp=root->left;
    while(temp->right->right){temp=temp->right;}
    root->name=temp->right->name;
    root->x=temp->right->x;
    root->y=temp->right->y;
    City * wangToDelete=temp->right;
    temp->right=temp->right->left;
    delete wangToDelete;

}




