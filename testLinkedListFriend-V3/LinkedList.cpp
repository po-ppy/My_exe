/*
 һ��������һ����ָ��������һ���һ����ʽ�ṹ��
 �䳤�����ڳ��������ڼ�����ʱ�ɱ��.

 һ�����͵�������ڵ�Ķ����Ϊ�����֣�
 һ���������ڱ���ڵ��е����ݵ�������
 ��һ���������ڱ���ָ����һ���ڵ��ָ���ָ����.
 һ�����͵�������Ľڵ�����ͼ��ʾ��
 +---------+
 |  Data   | -----> ���������ڱ���ڵ������.
 +---------+
 | pointer | ----->ָ�������ڱ���ָ����һ���ڵ��ָ��.
 +---------+

 ***ע��***��
 ָ���򱣴�����һ���ڵ�ĵ�ַ����������һ���ڵ������ݵĵ�ַ��
 ��Ȼ�п��������ַ��������������Ԫ�صĵ�ַ��
 β�ڵ�(���һ���ڵ�)��ָ����Ӧ��ΪNULL.

һ�����͵���������ͼ��ʾ��
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

/* �ڵ���Ķ��� */
class Node // ����༼�������Ը��ɿ���ʵ����������
{
    // �������ඨ��Ϊ�ڵ������Ԫ���Բ����ڵ����е�˽�г�Ա
    friend class LinkedList;
private:
    int data;                   /* �����򣬿������κ����ͣ������� */
    Node * pNext;         /* ָ���򣬽ڵ������͵�ָ�� */

public:
    /* �޲ι��캯�� */
    Node() : data(0), pNext(NULL) //��ʼ���б�
    { }

    /* ��ָ�������ݹ���ڵ� */
    Node(int val): data(val), pNext(NULL) //��ʼ���б�
    { }

    /* ��ָ�������ݺ���һ���ڵ��ָ�빹��ڵ� */
    Node(int val, Node* next) : data(val), pNext(next)
    {}

    /* Get���������� */
    int getValue(void) const // ��ȡ�������ֵ
    {
        return data;
    }

    Node* getNext(void) const // ��ȡָ�����ֵ
    {
        return pNext;
    }
};

/* ��ʼ��ͷ�ڵ��β�ڵ� */
LinkedList::LinkedList() : pHead(NULL), pTail(NULL) //��ʼ���б�
{
}

/* ��ָ�����������ֵ����һ���½ڵ㣬
����ֻ��һ���ڵ㣬���ԣ��ýڵ㼴��ͷ�ڵ㣬Ҳ��β�ڵ�� */
LinkedList::LinkedList(int val)
{
    pHead = new Node(val);
    pTail = pHead;
}

/* ������������δʵ�֣���һ�����⣬���������о���*/
LinkedList::~LinkedList()
{
    if (isEmpty())//��Կյ����
    {
        return;
    }
    //��ʱָ��
    Node *p = pHead;
    //�����ͷ��ڴ�
    while (p->pNext != NULL)
    {
        p = p->pNext;
        delete pHead;
        pHead = p;
    }
    delete p;
}

/* �ж������Ƿ�Ϊ������*/
bool LinkedList::isEmpty()
{
    /*���ͷ�ڵ�Ϊ�գ����ǿ����������棬���򷵻ؼ�*/
    return pHead == NULL ? true : false;
}

/*
����������
���������Խڵ����ͳ�ƺ󷵻ؽ��
*/
int LinkedList::getLength()
{
    /* ���Ϊ���������س���0*/
    if (isEmpty())
    {
        return 0;
    }

    //��ʱ�ڵ���ָ��
    Node* p = pHead;

    //���ȼ�����
    int counter = 1;
    while (p != pTail) // todo: �ǲ����������أ����һ���ڵ㴦��ĺ��ʲ���
    {
        p = p->pNext;
        counter++;//����������
    }

    return counter;
}

/* ������������ڵ��е����� */
void LinkedList::traverseAndPrint() // todo���ǲ��ǿ������Ϊ<<����������ظ�Ϊ����
{

    /* �����Ƿ�Ϊ��? */
    if (isEmpty())
    {
        cout << "����Ϊ�գ�" << endl;
        return;
    }
    //

    cout << "���� ";

    // ��ʱָ��
    Node *p = pHead;

    /* ����������ķ��� */
    while (p != NULL) // �ǲ������һ���ڵ� */
    {
        /* ����ڵ��е����� */
        cout << p->data;   // ˽�г�Ա����Ԫ���Է���
        /* ָ����һ���ڵ� */
        p = p->pNext;         // ˽�г�Ա����Ԫ���Է���
    }
    cout << endl;
}

/* ָ��λ�ò������ݣ����posԽ�緵�ؿ�ָ��*/
Node* LinkedList::insertData(const int& pos, const int& nVal)
{
    //��ʱָ��
    Node *p = pHead;

    /* ������pos��λ��,֧��Խ����*/
    for (register int i = 0; i < pos - 1; ++i) // ��Ϊͷ�ڵ㱣�����ݣ�����-1
    {
        if (p->pNext != pTail->pNext)
        {
            p = p->pNext;
        }
        else //��posԽ�磬���ؿ�ָ�롣
        {
            return NULL;
        }
    }

    /* ���β�ڵ�������������*/
    if (p != pTail)//�������β���
    {
        /* ����Ԫ��*/
        Node* pTemp = p->pNext;
        p->pNext = new Node(nVal, pTemp); // �����ڵ�ʱ��ֱ��ָ����һ���ڵ�
        //p->pNext->pNext = temp;
    }
    else if (p != NULL) // �����β�ڵ��Ҹ�����ǿ�
    {
        /* ����Ԫ��*/
        p->pNext = new Node(nVal);
        pTail = p->pNext;
    }
    else//����Ϊ��
    {
        pHead = new Node(nVal);
        pTail = pHead;
        return pHead;// ����ָ��������ݽڵ��ָ��
    }

    /* ����ָ��������ݽڵ��ָ��*/
    return p->pNext;
}

/* ָ��λ��ָ��ɾ�����ݵ�ָ��,���posԽ���������Ϊ�������ؿ�ָ��*/
void LinkedList::delData(const int& pos)//, const int& nVal)
{
    /* �����Ƿ�Ϊ��? */
    if (isEmpty())
    {
        cout << "����Ϊ�գ�" << endl;
        return;// NULL;
    }

    //���ڴ���ɾ����Ԫ��ֵ
    //int* pVal = new int;
    //��ʱָ��
    Node *p = pHead;

    /* ���ͷ�ڵ��������*/
    if (pos == 0)
    {
        //*pVal = pHead->getValue();
        delete pHead;
        pHead = NULL;
        pTail = NULL;
        return;
        //return pVal;
    }

    /* ������pos֮ǰһ���ڵ��λ��,֧��Խ����*/
    for (register int i = 0; i < pos - 1; ++i)//��Ϊͷ�ڵ㱣�����ݣ�����-1
    {
        if (p != NULL && pTail != NULL && p->pNext != pTail->pNext)
        {
            p = p->pNext;
        }
        else//��posԽ�磬���ء�
        {
            return;// NULL;
        }
    }

    /* ���β��ɾ�����������*/
    if (p->pNext != pTail)//�������β���
    {
        /* ɾ��Ԫ��*/
        Node* pTemp = p->pNext;
        p->pNext = p->pNext->pNext;
        p->pNext = NULL;
        pTail = p->pNext;//����βָ��

        //*pVal = pTemp->getValue();//�õ�ɾ����Ԫ��ֵ
        delete pTemp;//ɾ���ڵ�
    }
    else if(p->pNext == pTail)//�����β�ڵ�
    {
        //*pVal = p->pNext->getValue();//�õ�ɾ����Ԫ��ֵ
        delete p->pNext;//ɾ���ڵ�
        p->pNext = NULL;
        pTail = p;//����βָ��
    }

    //delete pVal;

    /* ����ָ��������ݽڵ��ָ��*/
    //return pVal;
}

/* �������ݲ��������ݽڵ�ָ�룬���򷵻ؿգ�����Ϊ������ʱҲ���ؿ�*/
bool LinkedList::findData(const int& nVal)
{
    /* �����Ƿ�Ϊ��? */
    if (isEmpty())
    {
        cout << "����Ϊ�գ�" << endl;
        return NULL;
    }

    //��ʱָ��
    Node *p = pHead;

    /* ����Ѱ��*/
    while (p != NULL && p->getValue() != nVal)
    {
        p = p->pNext;
    }

    if (p != NULL)//���Ԫ�ش��ڣ�����ָ���Ԫ�ص�ָ��
    {
        return true;
    }
    else//���Ԫ�ز����ڣ����ؿ�ָ��
    {
        return false;
    }
}

/* ��listβ���Ԫ��*/
void LinkedList::appAfterTail(const int& nVal)
{
    /* �����Ƿ�Ϊ��? */
    if (isEmpty())
    {
        /* �൱�ڽ���ͷ�ڵ�*/
        pHead = new Node(nVal);
        pTail = pHead;
        return;
    }

    /* ��β������½ڵ�*/
    pTail->pNext = new Node(nVal);
    pTail = pTail->pNext;
}

/* ��list�����Ԫ��*/
void LinkedList::appBeforeHead(const int& nVal)
{
    /* �����Ƿ�Ϊ��? */
    if (isEmpty())
    {
        /* �൱�ڽ���ͷ�ڵ�*/
        pHead = new Node(nVal);
        pTail = pHead;
        return;
    }

    /* ���ײ�����½ڵ�*/
    pHead = new Node(nVal, pHead);
    //Node* p = new Node(nVal);
    //p->pNext = pHead;
    //pHead = p;
}

/* ��listβɾ��Ԫ��*/
void LinkedList::delFromTail()
{
    /* �����Ƿ�Ϊ��? */
    if (isEmpty())
    {
        cout << "����Ϊ�գ�" << endl;
        return;
    }

    /* ���ֻ��һ���ڵ���������*/
    if (pHead->pNext == NULL)
    {
        delete pHead;
        pHead = pTail = NULL;

        return;
    }


    //��ʱָ��
    Node *p = pHead;
    /* ���һ�����*/
    while (p->pNext != pTail)
    {
        p = p->pNext;   //�ҵ�β�ڵ�֮ǰ��һ���ڵ�
    }

    delete p->pNext;
    p->pNext = NULL;
    pTail = p;//����βָ��

    return;
}

/* ��list��ɾ��Ԫ��*/
void LinkedList::delFromHead()
{
    /* �����Ƿ�Ϊ��? */
    if (isEmpty())
    {
        cout << "����Ϊ�գ�" << endl;
        return;
    }

    /* ���ֻ��һ���ڵ���������*/
    if (pHead->pNext == NULL)
    {
        delete pHead;
        pHead = pTail = NULL;

        return;
    }

    //��ʱָ��
    Node *p = pHead;
    /* ���һ�����*/
    pHead = pHead->pNext;
    delete p;

    return;
}

/* �õ�βԪ�ص�����*/
int& LinkedList::getTailVal()
{
    return pTail->data;
}

/* �õ���Ԫ�ص�����*/
int& LinkedList::getHeadVal()
{
    return pHead->data;
}

/* �������*/
void LinkedList::clearLinkedList()
{
    /* �õ�����Ȼ��ȫ��delFromHead��*/
    for (register int i = 0; i < getLength(); i++)
        delFromHead();//��delFromTail����Լʱ��
}
