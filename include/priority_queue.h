//
// Created by lbw on 24-12-28.
//

#ifndef STL_PRIORITY_QUEUE_H
#define STL_PRIORITY_QUEUE_H
#define LEFT_CHILD(i) (2 * i + 1)
#define RIGHT_CHILD(i) (2 * i + 2)
#define PARENT(i) ((i - 1) / 2)

#include "vector.h"
#include <iostream>

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
        //printHeap();
    }

    inline _Type top() const {
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
        for (auto i = (size_ - 2) / 2; i >= 0; i--) {//从最后一个非叶节点开始向上堆化
            heapify(i);
        }
    }

    //调整堆节点，递归查找非法节点
    void heapify(int index) {
        int now = data_[index];
        int left = LEFT_CHILD(index);
        int right = RIGHT_CHILD(index);
        int largest = index;
        //选出最大的字节点
        if (left < size_ && cmp_.smaller(now, data_[left])) {
            largest = left;
        }
        if (right < size_ && cmp_.smaller(data_[largest], data_[right])) {
            largest = right;
        }
        //向下检查是否非法
        if (largest != index) {
            auto temp = data_[index];
            data_[index] = data_[largest];
            data_[largest] = temp;
            heapify(largest);

        }
        return;

    }

    void printHeap() {
        for (int i = 0; i < size_; i++) {
            std::cout << data_[i] << " ";
        }
        std::cout << std::endl;
    }
};


#endif //STL_PRIORITY_QUEUE_H
