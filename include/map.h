//
// Created by lbw on 24-12-28.
//

#ifndef STL_MAP_H
#define STL_MAP_H

#include <iostream>
#include "vector.h"

template<class _Key>
class lessCoder {//编码器，将字符转换为整数，用于计算哈希值（或者自定义转换方式）
public:
    lessCoder() = default;

    ~lessCoder() = default;

    inline int coder(const _Key &key) {
        union hash_t {//使用union类型，将_Key转换为整数，用于计算哈希值
            _Key key;
            long value;
        };
        hash_t hash_value;
        hash_value.key = key;
        return hash_value.value;
    }

};

template<class _Key, class _Value>
struct pair {
    pair(){
        isExist = false;
    }
    _Key first;
    _Value second;
    bool isExist;
};

template<class _Key, class _Value, class _Coder=lessCoder<_Key>>
class map {
public:
    map() : size_(13) {
        data_ = new pair<_Key, _Value>[size_];
        steps_ = new int[MAX_STEPS];
        for (int i = 0; i < MAX_STEPS; i++) {//计算步幅
            if (i == 0) //第一次步幅为1
                steps_[i] = 1;
            else if (i > 0)//正数步幅的下一个为负数步幅
                steps_[i] = -steps_[i - 1];
            else if (i < 0)//负数步幅的下一个为正数步幅+1
                steps_[i] = -steps_[i - 1] + 1;
        }
    };

    ~map() {
        delete[] steps_;
    };


    _Value& operator[](const _Key &key) {
        int index = hash(key);
        for(int i = 0; i < MAX_STEPS; i++){//线性探测
            if(data_[index].first == key){//找到了一样的键值对，返回引用
                return data_[index].second;
            }
            if(!data_[index].isExist){//找到一个空位，插入键值对
                break;
            }
            index = (index + steps_[i]) % size_;
        }
        if(data_[index].isExist){//没找到，并且当前位置已经被占用（哈希冲突）
            rehash();
            return operator[](key);
        }
        else{//找到一个空位，插入键值对
            data_[index].first = key;
            data_[index].isExist = true;
            return data_[index].second;
        }
    }

private:
    _Coder coder_;//编码器，将字符转换为整数，用于计算哈希值（或者自定义转换方式）

    pair<_Key, _Value>* data_;//数据结构，保存键值对

    int size_;//哈希表大小

    int hash(_Key key) {//计算哈希值
        auto hash_value = abs(coder_.coder(key));
        int index = hash_value % size_;
        return index;
    }

    void rehash() {//再散列
        auto old_size_ = size_;
        size_ *= 2;
        pair<_Key, _Value>* new_data = new pair<_Key, _Value>[size_];
        for(auto i = 0; i < old_size_; i++){
            if(data_[i].isExist){//复制旧数据，检测存在
                auto index = hash(data_[i].first);
                auto oldData = data_[i];
                for(int j = 0; j < MAX_STEPS; j++){//线性探测
                    if(!new_data[index].isExist){//找到了空位
                        new_data[index].first = oldData.first;
                        new_data[index].second = oldData.second;
                        new_data[index].isExist=true;
                        break;
                    }
                    index = (index + steps_[i]) % size_;
                }
            }
        }
        delete[] data_;
        data_ = new_data;



        //print();测试用

    }

    void print() {
        for(int i=0; i<size_; i++){
            if(data_[i].isExist){
                std::cout << data_[i].first << " " << data_[i].second << std::endl;
            }
        }
        std::cout << "-------end-------" << std::endl;
    }

    static constexpr int MAX_STEPS = 3;//线性探测的最大步数
    int *steps_;
};


#endif //STL_MAP_H
