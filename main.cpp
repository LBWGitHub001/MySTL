#include<iostream>
#include"list.h"
#include"vector.h"
#include"queue.h"
#include"stack.h"
#include"priority_queue.h"
#include "map.h"

int main() {

    stack<int> s;
for(int i=0;i<10000;i++){
    s.push(i);
}

for(int i=0;i<10000;i++){
    std::cout<<s.top()<<std::endl;
    s.pop();
}
s.pop();

    return 0;
}