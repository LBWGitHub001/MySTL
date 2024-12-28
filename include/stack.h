//
// Created by lbw on 24-12-28.
//

#ifndef STL_STACK_H
#define STL_STACK_H

#include <cassert>
#include "list.h"

template<class _Type>
class stack {
public:
    stack() = default;

    ~stack() {
        data_.clear();
    };

    //入栈元素
    void push(const _Type &value) {
        data_.insert(0, value);
    }

    //查看栈顶元素，只读访问，不弹出
    _Type top() const {
        if (empty()) {
            assert("stack is empty");
        }
        return data_.front();
    }

    //弹出栈顶元素
    void pop() {
        if (!empty())
            data_.remove(0);
    }

    //判断栈是否为空
    [[nodiscard]] inline bool empty() const {
        return data_.empty();
    }


private:
    list<_Type> data_;
};


#endif //STL_STACK_H
