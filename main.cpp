#include <iostream>
#include "CityTree.h"
int main() {
    CityTree cityTree(112,22,"广州");
    cityTree.add(120,30,"上海");
    cityTree.add(116,39,"北京");
    cityTree.add(114,38,"石家庄");
    cityTree.add(74,40,"New York");
    cityTree.add(0,51,"London");
    cityTree.printByDepth(4);
    cityTree.deleteByName("London");
    std::cout<<"----------------------------------------------"<<std::endl;
    cityTree.printByDepth(4);
    cityTree.deleteByPos(116,39);
    std::cout<<"----------------------------------------------"<<std::endl;
    cityTree.printByDepth(4);

    return 0;
}
