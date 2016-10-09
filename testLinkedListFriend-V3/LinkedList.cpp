/*
 一个链表是一个用指针链接在一起的一个链式结构，
 其长度是在程序运行期间是随时可变的.

 一个典型单向链表节点的定义分为两部分，
 一部分是用于保存节点中的数据的数据域，
 另一部分是用于保存指向下一个节点的指针的指针域.
 一个典型单向链表的节点如下图所示：
 +---------+
 |  Data   | -----> 数据域，用于保存节点的数据.
 +---------+
 | pointer | ----->指针域，用于保存指向下一个节点的指针.
 +---------+

 ***注意***：
 指针域保存了下一个节点的地址，而不是下一个节点中数据的地址，
 虽然有可能这个地址就是数据域数据元素的地址。
 尾节点(最后一个节点)的指针域应该为NULL.

一个典型的链表如下图所示：
 +------------+        ---> +------------+     ---> +-----------+
 |  Data    |        |      |  Data    |      |     |  Data   |
 +------------+       |      +------------+      |    +------------+
 | pointer |--------       | pointer |------      |  NULL  |
 +---------+                 +------------+           +------------+
 */

#include <iostream>
#include "LinkedList.h"

using std::cout;
using std::endl;

/* 节点类的定义 */
class Node // 句柄类技术，可以更可靠的实现数据隐藏
{
    // 将链表类定义为节点类的友元，以操作节点类中的私有成员
    friend class LinkedList;
private:
    int data;                   /* 数据域，可以是任何类型，任意多个 */
    Node * pNext;         /* 指针域，节点类类型的指针 */

public:
    /* 无参构造函数 */
    Node() : data(0), pNext(NULL) //初始化列表
    { }

    /* 用指定的数据构造节点 */
    Node(int val): data(val), pNext(NULL) //初始化列表
    { }

    /* 用指定的数据和下一个节点的指针构造节点 */
    Node(int val, Node* next) : data(val), pNext(next)
    {}

    /* Get访问器函数 */
    int getValue(void) const // 获取数据域的值
    {
        return data;
    }

    Node* getNext(void) const // 获取指针域的值
    {
        return pNext;
    }
};

/* 初始化头节点和尾节点 */
LinkedList::LinkedList() : pHead(NULL), pTail(NULL) //初始化列表
{
}

/* 用指定的数据域的值创建一个新节点，
由于只有一个节点，所以，该节点即是头节点，也是尾节点的 */
LinkedList::LinkedList(int val)
{
    pHead = new Node(val);
    pTail = pHead;
}

/* 析构函数，暂未实现，是一个问题，请大家自行研究。*/
LinkedList::~LinkedList()
{
    if (isEmpty())//针对空的情况
    {
        return;
    }
    //临时指针
    Node *p = pHead;
    //遍历释放内存
    while (p->pNext != NULL)
    {
        p = p->pNext;
        delete pHead;
        pHead = p;
    }
    delete p;
}

/* 判断链表是否为空链表*/
bool LinkedList::isEmpty()
{
    /*如果头节点为空，则是空链表，返回真，否则返回假*/
    return pHead == NULL ? true : false;
}

/*
返回链表长度
遍历链表并对节点计数统计后返回结果
*/
int LinkedList::getLength()
{
    /* 如果为空链表，返回长度0*/
    if (isEmpty())
    {
        return 0;
    }

    //临时节点型指针
    Node* p = pHead;

    //长度计数器
    int counter = 1;
    while (p != pTail) // todo: 是不是有问题呢？最后一个节点处理的合适不？
    {
        p = p->pNext;
        counter++;//递增计数器
    }

    return counter;
}

/* 遍历链表并输出节点中的数据 */
void LinkedList::traverseAndPrint() // todo：是不是可以设计为<<运算符的重载更为合理？
{

    /* 链表是否为空? */
    if (isEmpty())
    {
        cout << "链表为空！" << endl;
        return;
    }
    //

    cout << "链表： ";

    // 临时指针
    Node *p = pHead;

    /* 遍历链表常规的方法 */
    while (p != NULL) // 是不是最后一个节点 */
    {
        /* 输出节点中的数据 */
        cout << p->data;   // 私有成员，友元可以访问
        /* 指向下一个节点 */
        p = p->pNext;         // 私有成员，友元可以访问
    }
    cout << endl;
}

/* 指定位置插入数据，如果pos越界返回空指针*/
Node* LinkedList::insertData(const int& pos, const int& nVal)
{
    //临时指针
    Node *p = pHead;

    /* 遍历到pos的位置,支持越界检查*/
    for (register int i = 0; i < pos - 1; ++i) // 因为头节点保存数据，所以-1
    {
        if (p->pNext != pTail->pNext)
        {
            p = p->pNext;
        }
        else //若pos越界，返回空指针。
        {
            return NULL;
        }
    }

    /* 针对尾节点插入的特殊情形*/
    if (p != pTail)//如果不是尾结点
    {
        /* 插入元素*/
        Node* pTemp = p->pNext;
        p->pNext = new Node(nVal, pTemp); // 创建节点时，直接指向下一个节点
        //p->pNext->pNext = temp;
    }
    else if (p != NULL) // 如果是尾节点且该链表非空
    {
        /* 插入元素*/
        p->pNext = new Node(nVal);
        pTail = p->pNext;
    }
    else//链表为空
    {
        pHead = new Node(nVal);
        pTail = pHead;
        return pHead;// 返回指向插入数据节点的指针
    }

    /* 返回指向插入数据节点的指针*/
    return p->pNext;
}

/* 指定位置指向删除数据的指针,如果pos越界或者链表为空链表返回空指针*/
void LinkedList::delData(const int& pos)//, const int& nVal)
{
    /* 链表是否为空? */
    if (isEmpty())
    {
        cout << "链表为空！" << endl;
        return;// NULL;
    }

    //用于储存删除的元素值
    //int* pVal = new int;
    //临时指针
    Node *p = pHead;

    /* 针对头节点特殊情况*/
    if (pos == 0)
    {
        //*pVal = pHead->getValue();
        delete pHead;
        pHead = NULL;
        pTail = NULL;
        return;
        //return pVal;
    }

    /* 遍历到pos之前一个节点的位置,支持越界检查*/
    for (register int i = 0; i < pos - 1; ++i)//因为头节点保存数据，所以-1
    {
        if (p != NULL && pTail != NULL && p->pNext != pTail->pNext)
        {
            p = p->pNext;
        }
        else//若pos越界，返回。
        {
            return;// NULL;
        }
    }

    /* 针对尾部删除的特殊情况*/
    if (p->pNext != pTail)//如果不是尾结点
    {
        /* 删除元素*/
        Node* pTemp = p->pNext;
        p->pNext = p->pNext->pNext;
        p->pNext = NULL;
        pTail = p->pNext;//修正尾指针

        //*pVal = pTemp->getValue();//得到删除的元素值
        delete pTemp;//删除节点
    }
    else if(p->pNext == pTail)//如果是尾节点
    {
        //*pVal = p->pNext->getValue();//得到删除的元素值
        delete p->pNext;//删除节点
        p->pNext = NULL;
        pTail = p;//修正尾指针
    }

    //delete pVal;

    /* 返回指向插入数据节点的指针*/
    //return pVal;
}

/* 查找数据并返回数据节点指针，否则返回空，链表为空链表时也返回空*/
bool LinkedList::findData(const int& nVal)
{
    /* 链表是否为空? */
    if (isEmpty())
    {
        cout << "链表为空！" << endl;
        return NULL;
    }

    //临时指针
    Node *p = pHead;

    /* 遍历寻找*/
    while (p != NULL && p->getValue() != nVal)
    {
        p = p->pNext;
    }

    if (p != NULL)//如果元素存在，返回指向该元素的指针
    {
        return true;
    }
    else//如果元素不存在，返回空指针
    {
        return false;
    }
}

/* 在list尾添加元素*/
void LinkedList::appAfterTail(const int& nVal)
{
    /* 链表是否为空? */
    if (isEmpty())
    {
        /* 相当于建立头节点*/
        pHead = new Node(nVal);
        pTail = pHead;
        return;
    }

    /* 在尾部添加新节点*/
    pTail->pNext = new Node(nVal);
    pTail = pTail->pNext;
}

/* 在list首添加元素*/
void LinkedList::appBeforeHead(const int& nVal)
{
    /* 链表是否为空? */
    if (isEmpty())
    {
        /* 相当于建立头节点*/
        pHead = new Node(nVal);
        pTail = pHead;
        return;
    }

    /* 在首部添加新节点*/
    pHead = new Node(nVal, pHead);
    //Node* p = new Node(nVal);
    //p->pNext = pHead;
    //pHead = p;
}

/* 在list尾删除元素*/
void LinkedList::delFromTail()
{
    /* 链表是否为空? */
    if (isEmpty())
    {
        cout << "链表为空！" << endl;
        return;
    }

    /* 针对只有一个节点的特殊情况*/
    if (pHead->pNext == NULL)
    {
        delete pHead;
        pHead = pTail = NULL;

        return;
    }


    //临时指针
    Node *p = pHead;
    /* 针对一般情况*/
    while (p->pNext != pTail)
    {
        p = p->pNext;   //找到尾节点之前的一个节点
    }

    delete p->pNext;
    p->pNext = NULL;
    pTail = p;//调整尾指针

    return;
}

/* 在list首删除元素*/
void LinkedList::delFromHead()
{
    /* 链表是否为空? */
    if (isEmpty())
    {
        cout << "链表为空！" << endl;
        return;
    }

    /* 针对只有一个节点的特殊情况*/
    if (pHead->pNext == NULL)
    {
        delete pHead;
        pHead = pTail = NULL;

        return;
    }

    //临时指针
    Node *p = pHead;
    /* 针对一般情况*/
    pHead = pHead->pNext;
    delete p;

    return;
}

/* 得到尾元素的引用*/
int& LinkedList::getTailVal()
{
    return pTail->data;
}

/* 得到首元素的引用*/
int& LinkedList::getHeadVal()
{
    return pHead->data;
}

/* 清空链表*/
void LinkedList::clearLinkedList()
{
    /* 得到长度然后全部delFromHead掉*/
    for (register int i = 0; i < getLength(); i++)
        delFromHead();//比delFromTail更节约时间
}
