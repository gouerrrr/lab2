//
// Created by 余歌 on 2022/10/28.
//

#ifndef LAB2_CITYTREE_H
#define LAB2_CITYTREE_H


#include <iostream>
struct City{
    City(int i, int i1, std::string basicString)
    {
        x=i;
        y=i1;
        name=basicString;
    }

    int x;
    int y;
    std::string name;
    City* left;
    City* right;
};

class CityTree{
private:
    City* first;
public:
    CityTree(int x,int y,std::string name);

    void add(int x,int y,std::string name);
    void deleteByPos(int x,int y);
    void deleteByName(std::string name);
    void printByDepth(int depth);
    void printRecursion(int depth,City* root);
    void findByName(std::string name);
    void findByNameRecursion(std::string name,City* root);
    void findByPos(int x,int y);
    void findByPosRecursion(int x,int y,City* root);
    void replaceRightestInLeft(City* root);
};


#endif //LAB2_CITYTREE_H
