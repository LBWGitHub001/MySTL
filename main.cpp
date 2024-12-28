#include<iostream>
#include"list.h"
#include"vector.h"
#include"queue.h"
#include"stack.h"
#include"priority_queue.h"
#include "map.h"

int main(){
map<char*,int> mymap;
mymap["apple"] = 10;
mymap["banana"] = 20;
mymap["orange"] = 30;
mymap["grape"] = 40;
mymap["pear"] = 50;
mymap["mango"] = 60;
mymap["pineapple"] = 70;
mymap["watermelon"] = 80;
mymap["kiwi"] = 90;
mymap["strawberry"] = 100;
mymap["blueberry"] = 110;
mymap["raspberry"] = 120;
mymap["cherry"] = 130;
mymap["lemon"] = 140;
mymap["lime"] = 150;
mymap["grapefruit"] = 160;
mymap["peach"] = 170;
mymap["apricot"] = 180;
mymap["nectarine"] = 190;
mymap["plum"] = 200;

std::cout << mymap["apple"] << std::endl;
std::cout << mymap["banana"] << std::endl;
std::cout << mymap["orange"] << std::endl;
std::cout << mymap["grape"] << std::endl;
std::cout << mymap["pear"] << std::endl;
std::cout << mymap["mango"] << std::endl;
std::cout << mymap["pineapple"] << std::endl;
std::cout << mymap["watermelon"] << std::endl;
std::cout << mymap["kiwi"] << std::endl;
std::cout << mymap["strawberry"] << std::endl;
std::cout << mymap["blueberry"] << std::endl;
std::cout << mymap["raspberry"] << std::endl;
std::cout << mymap["cherry"] << std::endl;
std::cout << mymap["lemon"] << std::endl;
std::cout << mymap["lime"] << std::endl;
std::cout << mymap["grapefruit"] << std::endl;
std::cout << mymap["peach"] << std::endl;
std::cout << mymap["apricot"] << std::endl;
std::cout << mymap["nectarine"] << std::endl;
std::cout << mymap["plum"] << std::endl;
    return 0;
}