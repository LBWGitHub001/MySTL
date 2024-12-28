//
// Created by lbw on 24-12-28.
//

#ifndef STL_PRIORITY_QUEUE_H
#define STL_PRIORITY_QUEUE_H

#include "vector.h"

template<class _Type>
class lessComparor {
public:
    lessComparor() = default;

    ~lessComparor() = default;

    bool smaller(const _Type &a, const _Type &b) {
        return a < b;
    }
};


template<class _Type, class _Comparor = lessComparor<_Type>>
class priority_queue {
public:
    priority_queue() : size_(0) {
    };

    ~priority_queue() = default;

    void push(const _Type &val) {
        data_.push_back(val);
        size_++;
        makeHeap();
    }

    inline _Type top() const{
        return data_[0];
    }


    void pop() {
        auto result = data_[0];
        auto temp = data_[0];
        data_[0] = data_[size_ - 1];
        data_[size_ - 1] = temp;
        size_--;
        makeHeap();
    }


    //判断队列是否为空
    [[nodiscard]] inline bool empty() const {
        return size_ == 0;
    }



private:
    _Comparor cmp_; // 优先级比较器
    vector<_Type> data_;    //数据容器
    int size_;              //队列大小

    void makeHeap() {//建立一个max-heap
        for (auto i = size_ - 1; i > 0; i /= 2) {//从最后一个节点开始向上堆化
            if (cmp_.smaller(data_[i / 2], data_[i])) {//如果父节点比子节点小，则交换
                auto temp = data_[i / 2];
                data_[i / 2] = data_[i];
                data_[i] = temp;
            }
        }
    }
};


#endif //STL_PRIORITY_QUEUE_H
