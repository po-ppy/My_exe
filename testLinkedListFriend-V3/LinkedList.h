#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// 前身引用说明，说明Node是一个类
class Node; // 句柄类技术，可以更可靠的实现数据隐藏

/* 定义链表类(该类是节点类的友元，可以访问其私有成员) */
class LinkedList
{
private:
    /* 指向头节点的指针 */
    Node *pHead;
    /* 指向尾节点的指针 */
    Node *pTail;

public:
    /* 无参构造函数 */
    LinkedList();
    /* 指定节点数据域的构造函数 */
    LinkedList(int val);
    /* 析构函数 */
    ~LinkedList(void);

    /* 判断链表是否为空链表*/
    bool isEmpty();
    /* 返回链表长度*/
    int getLength();
    /* 遍历链表并输出每个节点的数据 */
    void traverseAndPrint();
    /* 指定位置插入数据，如果pos越界返回空指针*/
    Node* insertData(const int& pos, const int& nVal);
    /* 指定位置指向删除数据的指针,如果pos越界或者链表为空链表返回空指针*/
    void delData(const int& pos);//, const int& nVal);
    /* 查找数据并返回数据节点指针，否则返回空，链表为空链表时也返回空*/
    bool findData(const int& nVal);
    /* 在list尾添加元素*/
    void appAfterTail(const int& nVal);
    /* 在list首添加元素*/
    void appBeforeHead(const int& nVal);
    /* 在list尾删除元素*/
    void delFromTail();
    /* 在list首删除元素*/
    void delFromHead();
    /* 得到尾元素的引用*/
    int& getTailVal();
    /* 得到首元素的引用*/
    int& getHeadVal();
    /* 清空链表*/
    void clearLinkedList();
};


#endif // LINKEDLIST_H
