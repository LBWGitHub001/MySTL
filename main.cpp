#include<iostream>
#include"list.h"
#include"vector.h"
#include"queue.h"
#include"stack.h"
#include"priority_queue.h"
#include "map.h"

int main() {

list<int> l;
for(int i=0;i<100;i++){
    l.insert(i,i);
}

l.clear();

    return 0;
}