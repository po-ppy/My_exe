/**
*作者 : 耿楠 王思琛
*目标 : 实现链表
*更新 : 2016/6/8
*/

/**
 * 一个用于创建链表的简单C++示例代码
 * 包括节点类和链表类两个类
 * 演示了一个空链表和只有一个节点的链表的操作
 *
 * 要求：理解链表的定义和结构及如何基于结构构建链表
 */


#include <iostream>
#include <string>
#include "LinkedList.h"

using std::cout;
using std::endl;
using std::string;

int main(int argc, const char * argv[])
{
    /* 创建一个空链表 */
    LinkedList list1;
    cout << "创建一个名为list1的空链表." << endl;
    /* 遍历并输出链表 */
    cout << "list1:" << endl;
    list1.traverseAndPrint();

    /* 创建一个名为list2的只有一个节点的链表 */
    LinkedList list2(10);
    cout << "创建一个名为list2的只有一个节点的链表." << endl;
    /* 遍历并输出链表 */
    cout << "list2:" << endl;
    list2.traverseAndPrint();

    /* 添加元素, 测试insertData*/
    for (int i = 1; i <= 5; ++i)
    {
        list1.insertData(i - 1, i);
        list1.traverseAndPrint();
    }

    /* 查看链表长度*/
    cout << "The length of list1 is " << list1.getLength() << endl;

    /* 查找并输出元素5的位置*/
    string strTemp =  list1.findData(2) ? " is " : " is not ";
    cout << "The value " << 2 << strTemp << "in list1." << endl;
    strTemp =  list1.findData(1) ? " is " : " is not ";
    cout << "The value " << 1 << strTemp << "in list1." << endl;
    strTemp =  list1.findData(15) ? " is " : " is not ";
    cout << "The value " << 15 << strTemp << "in list1." << endl;

    /* 删除添加的元素  测试delData*/
    for (int i = 5; i > 0; --i)
    {
        list1.delData(i - 1);
        list1.traverseAndPrint();
    }

	/* 添加元素  测试appAfterTail*/
	for (int i = 0; i < 5; ++i)
	{
		list1.appAfterTail(i);
		list1.traverseAndPrint();
	}

	/* 删除元素  测试delFromTail*/
	for (int i = 0; i < 5; ++i)
	{
		list1.delFromTail();
		list1.traverseAndPrint();
	}

	/* 添加元素  测试appBeforeHead*/
	for (int i = 0; i < 5; ++i)
	{
		list1.appBeforeHead(i);
		list1.traverseAndPrint();
	}

	/* 删除元素  测试delFromHead*/
	for (int i = 0; i < 5; ++i)
	{
		list1.delFromHead();
		list1.traverseAndPrint();
	}

	/* 用于测试getTailVal和getHeadVal函数*/
	list2.traverseAndPrint();
	list2.getTailVal() = 2;
	list2.traverseAndPrint();
	list2.getHeadVal() = 1;
	list2.traverseAndPrint();

	/* 用于测试clearLinkedList*/
	list2.clearLinkedList();
	list2.traverseAndPrint();

    return 0;
}
