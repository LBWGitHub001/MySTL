//
// Created by lbw on 24-12-28.
//

#ifndef STL_QUEUE_H
#define STL_QUEUE_H
#include "vector.h"

template<class _Type>
class queue {
public:
    queue():frontPtr_(0){};
    ~queue(){
        data_.clear();
    };

    //入队元素
    void push(const _Type& value){
        data_.push_back(value);
    }

    //判断队列是否为空
    [[nodiscard]] bool empty() const{
        return data_.size() == frontPtr_;
    }

    //出队首元素
    void pop(){
        if(!empty()){
            frontPtr_++;
        }
    }

    //返回队首元素，让用户获得读权，不获得写权
    [[nodiscard]] _Type front() const{
        return data_[frontPtr_];
    }


private:
    vector<_Type> data_;
    int frontPtr_;

};


#endif //STL_QUEUE_H
