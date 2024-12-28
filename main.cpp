#include<iostream>
#include"list.h"
#include"vector.h"
#include"queue.h"
#include"stack.h"
#include"priority_queue.h"
#include "map.h"

int main() {
priority_queue<int> q;
for(int i=0;i<1000;i++){
    q.push(i);
}
for(int i=0;i<1000;i++){
    std::cout<<q.top()<<std::endl;
    q.pop();
}






    return 0;
}