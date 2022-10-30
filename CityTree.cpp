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
    deleteByPosRecursion(x,y,first);
}



/*when we want to delete a city,
 *there are 3 situations:
 * the city has 2 sons, 1 son, or it is a leaf.
 * on the first situation, we will replace the city
 * by the rightest son in its left tree,
 * others, we can simply delete it.
*/
void CityTree::deleteByName(std::string name) {
    City*p=first;
    if (first->name==name){replaceRightestInLeft(first);}
    while (p->left->name!=name&&p->right->name!=name)
    {
        if(name >p->name){p=p->right;}
        else if(name<p->name){p=p->left;}
    }
    if(p->left->name==name)
    {
        if(p->left->right&&p->left->left){replaceRightestInLeft(p->left);}
        else if(p->left->left){
            City* wantToDelete=p->left;
            p->left=p->left->left;
            delete wantToDelete;
        }
        else if(p->left->right){
            City* wantToDelete=p->left;
            p->left=p->left->right;
            delete wantToDelete;
        }
        else{delete p->left;p->left=NULL;}
    }
    else if(p->right->name==name)
    {
        if(p->right->right&&p->right->left){replaceRightestInLeft(p->right);}
        else if(p->right->left){
            City* wantToDelete=p->right;
            p->right=p->right->left;
            delete wantToDelete;
        }
        else if(p->right->right){
            City* wantToDelete=p->right;
            p->right=p->right->right;
            delete wantToDelete;
        }
        else{delete p->right;p->right=NULL;}
    }

}

void CityTree::replaceRightestInLeft(City* root) {
    City* temp=root->left;
    while(temp->right->right){temp=temp->right;}
    root->name=temp->right->name;
    root->x=temp->right->x;
    root->y=temp->right->y;
    City * wantToDelete=temp->right;
    temp->right=temp->right->left;
    delete wantToDelete;
}

void CityTree::printByDepth(int depth) {
    printRecursion(depth,first);
}

void CityTree::printRecursion(int depth, City *root) {
    if (depth > 0) {
        std::cout << "city name:" << root->name << " " << "city position:(" << root->x << "," << root->y << ")"
                  << std::endl;
        if(root->left) { printRecursion(depth - 1, root->left); }
        if(root->right){ printRecursion(depth-1,root->right);}

    }
}

void CityTree::findByName(std::string name) {
    findByNameRecursion(name,first);
}

void CityTree::findByNameRecursion(std::string name, City *root) {
    if(root->name==name){
        std::cout<<"city name:"<<name<<" city position:("<<root->x<<","<<root->y<<")"<<std::endl;
        return;
    }
    if(name>root->name){ findByNameRecursion(name,root->right);}
    else if(name<root->name){ findByNameRecursion(name,root->left);}


}

void CityTree::findByPos(int x, int y) {
    findByPosRecursion(x,y,first);
}

void CityTree::findByPosRecursion(int x, int y, City *root) {
    if(root->x==x&&root->y==y){
        std::cout<<"city name:"<<root->name<<" city position:("<<x<<","<<y<<")"<<std::endl;
        return;
    }
    if(root->left){ findByPosRecursion(x,y,root->left);}
    if(root->right){ findByPosRecursion(x,y,root->right);}
}

void CityTree::deleteByPosRecursion(int x, int y, City *root) {
    if(root->right){
        if(root->right->x==x&&root->right->y==y){
            if(root->right->right&&root->right->left){replaceRightestInLeft(root->right);}
            else if(root->right->left){
                City* wantToDelete=root->right;
                root->right=root->right->left;
                delete wantToDelete;
            }
            else if(root->right->right){
                City* wantToDelete=root->right;
                root->right=root->right->right;
                delete wantToDelete;
            }
            else{delete root->right;root->right=NULL;}
        }
        else{
            deleteByPosRecursion(x,y,root->right);
        }
    }
    if(root->left){
        if(root->left->x==x&&root->left->y==y){
            if(root->left->right&&root->left->left){replaceRightestInLeft(root->left);}
            else if(root->left->left){
                City* wantToDelete=root->left;
                root->left=root->left->left;
                delete wantToDelete;
            }
            else if(root->left->right){
                City* wantToDelete=root->left;
                root->left=root->left->right;
                delete wantToDelete;
            }
            else{delete root->left;root->left=NULL;}
        }
        else{
            deleteByPosRecursion(x,y,root->left);
        }

    }
}







