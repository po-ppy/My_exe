/**
*���� : ��� ��˼�
*Ŀ�� : ʵ������
*���� : 2016/6/8
*/

/**
 * һ�����ڴ�������ļ�C++ʾ������
 * �����ڵ����������������
 * ��ʾ��һ���������ֻ��һ���ڵ������Ĳ���
 *
 * Ҫ���������Ķ���ͽṹ����λ��ڽṹ��������
 */


#include <iostream>
#include <string>
#include "LinkedList.h"

using std::cout;
using std::endl;
using std::string;

int main(int argc, const char * argv[])
{
    /* ����һ�������� */
    LinkedList list1;
    cout << "����һ����Ϊlist1�Ŀ�����." << endl;
    /* ������������� */
    cout << "list1:" << endl;
    list1.traverseAndPrint();

    /* ����һ����Ϊlist2��ֻ��һ���ڵ������ */
    LinkedList list2(10);
    cout << "����һ����Ϊlist2��ֻ��һ���ڵ������." << endl;
    /* ������������� */
    cout << "list2:" << endl;
    list2.traverseAndPrint();

    /* ���Ԫ��, ����insertData*/
    for (int i = 1; i <= 5; ++i)
    {
        list1.insertData(i - 1, i);
        list1.traverseAndPrint();
    }

    /* �鿴������*/
    cout << "The length of list1 is " << list1.getLength() << endl;

    /* ���Ҳ����Ԫ��5��λ��*/
    string strTemp =  list1.findData(2) ? " is " : " is not ";
    cout << "The value " << 2 << strTemp << "in list1." << endl;
    strTemp =  list1.findData(1) ? " is " : " is not ";
    cout << "The value " << 1 << strTemp << "in list1." << endl;
    strTemp =  list1.findData(15) ? " is " : " is not ";
    cout << "The value " << 15 << strTemp << "in list1." << endl;

    /* ɾ����ӵ�Ԫ��  ����delData*/
    for (int i = 5; i > 0; --i)
    {
        list1.delData(i - 1);
        list1.traverseAndPrint();
    }

	/* ���Ԫ��  ����appAfterTail*/
	for (int i = 0; i < 5; ++i)
	{
		list1.appAfterTail(i);
		list1.traverseAndPrint();
	}

	/* ɾ��Ԫ��  ����delFromTail*/
	for (int i = 0; i < 5; ++i)
	{
		list1.delFromTail();
		list1.traverseAndPrint();
	}

	/* ���Ԫ��  ����appBeforeHead*/
	for (int i = 0; i < 5; ++i)
	{
		list1.appBeforeHead(i);
		list1.traverseAndPrint();
	}

	/* ɾ��Ԫ��  ����delFromHead*/
	for (int i = 0; i < 5; ++i)
	{
		list1.delFromHead();
		list1.traverseAndPrint();
	}

	/* ���ڲ���getTailVal��getHeadVal����*/
	list2.traverseAndPrint();
	list2.getTailVal() = 2;
	list2.traverseAndPrint();
	list2.getHeadVal() = 1;
	list2.traverseAndPrint();

	/* ���ڲ���clearLinkedList*/
	list2.clearLinkedList();
	list2.traverseAndPrint();

    return 0;
}
