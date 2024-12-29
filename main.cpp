#include<iostream>
#include"list.h"
#include"vector.h"
#include"queue.h"
#include"stack.h"
#include"priority_queue.h"
#include "map.h"

int main() {
vector<int> v;
for(int i=0;i<1000;i++){
    v.push_back(i);
}
for(int i=0;i<1000;i++){
    std::cout<<v[0]<<std::endl;
    v.erase(0);
}
v.clear();
v.erase(0);
std::cout <<v[-1] << std::endl;



    return 0;
}