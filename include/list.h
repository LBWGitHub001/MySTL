//
// Created by lbw on 24-12-28.
//

#ifndef STL_LIST_H
#define STL_LIST_H

template<class _Type>
class listNode {
public:
    bool isExist;
    _Type val;
    listNode *next;
    listNode *rarr;

    listNode() : val(), next(nullptr), rarr(nullptr), isExist(false) {}

    listNode(const _Type &val) : val(val), next(nullptr), rarr(nullptr), isExist(true) {}

    ~listNode() = default;
};


template<class _Type>
class list {
public:
    list() {
        head = new listNode<_Type>();
        head->next = nullptr;
        head->rarr = nullptr;
    }

    ~list() {
        clear();
        delete head;
    }

    //在pos的后一位插入val
    void insert(int pos, const _Type &val) {
        int i = 0;
        auto p = head;
        while ( i < pos && p->next != nullptr) {//找到pos位置的节点
            p = p->next;
            i++;
        }
        auto q = p->next;
        p->next = new listNode<_Type>(val);
        p->next->rarr = p;
        p->next->next = q;
        if(q!= nullptr)
            q->rarr = p->next;
        else
            tail = p->next;
    }

    //删除pos位置之后的元素
    void remove(int pos) {
        int i = 0;
        auto p = head;
        while ( i <= pos && p->next != nullptr) {//找到pos位置的节点
            p = p->next;
            i++;
        }
        //联通删除节点的前后节点
        auto pNode = p->rarr;
        pNode->next = p->next;
        p->isExist = false;
        if(p->next!= nullptr)
            p->next->rarr = pNode;
        delete p;
    }

    void clear() {
        auto p = head->next;
        while (p != nullptr) {//只要p不为空，就删除p
            auto q = p->next;
            delete p;
            p = q;
        }
    }

    //返回链表第一个数据节点
    inline _Type& front() const{
        return head->next->val;
    }

    //返回链表最后一个数据节点
    inline _Type& back() {
        return tail->val;
    }

    inline bool empty() const {
        return head->next == nullptr;
    }

private:
    listNode<_Type> *head;
    listNode<_Type> *tail;

};


#endif //STL_LIST_H
