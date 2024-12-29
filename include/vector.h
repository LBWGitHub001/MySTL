//
// Created by lbw on 24-12-28.
//

#ifndef STL_VECTOR_H
#define STL_VECTOR_H

#include <cassert>

template<class _Type>
class vector {
public:
    vector() : capacity_(8),size_(0) {
        data_ = new _Type[capacity_];
    }

    ~vector() {
        delete[] data_;
    }

    //使用[]操作符访问元素,同时获得读写权限
    _Type& operator[](int index) const {
        if(index<0 || index>=size_){
            throw "out of range";
        }
        return data_[index];
    }

    //在最后位置插入元素
    void push_back(const _Type& value){
        resize();//检查是否需要扩容
        data_[size_++] = value;
    }

    //删除指定位置的元素
    void erase(int index){
        if(index<=size_ && index>=0){
            for(int i=index;i<size_-1;i++){
                data_[i] = data_[i+1];
            }
            --size_;//删除最后一个位置
        }
    }

    //返回vector的大小
    inline int size() const{
        return size_;
    }

    //清空vector
    inline void clear(){
        size_ = 0;
    }

private:
    int capacity_;
    int size_;
    _Type *data_;

    //扩容，当容量不足时，扩大容量
    void resize() {
        if(size_ >= 0.8 * capacity_){//当容量不足80%时，扩大容量
            _Type *new_data = new _Type[capacity_ * 2];
            for(int i = 0; i < size_; i++){//拷贝原来的数据
                new_data[i] = data_[i];
            }
            delete[] data_;
            data_ = new_data;
            capacity_ *= 2;
        }
    }

};


#endif //STL_VECTOR_H
