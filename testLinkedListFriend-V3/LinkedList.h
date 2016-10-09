#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// ǰ������˵����˵��Node��һ����
class Node; // ����༼�������Ը��ɿ���ʵ����������

/* ����������(�����ǽڵ������Ԫ�����Է�����˽�г�Ա) */
class LinkedList
{
private:
    /* ָ��ͷ�ڵ��ָ�� */
    Node *pHead;
    /* ָ��β�ڵ��ָ�� */
    Node *pTail;

public:
    /* �޲ι��캯�� */
    LinkedList();
    /* ָ���ڵ�������Ĺ��캯�� */
    LinkedList(int val);
    /* �������� */
    ~LinkedList(void);

    /* �ж������Ƿ�Ϊ������*/
    bool isEmpty();
    /* ����������*/
    int getLength();
    /* �����������ÿ���ڵ������ */
    void traverseAndPrint();
    /* ָ��λ�ò������ݣ����posԽ�緵�ؿ�ָ��*/
    Node* insertData(const int& pos, const int& nVal);
    /* ָ��λ��ָ��ɾ�����ݵ�ָ��,���posԽ���������Ϊ�������ؿ�ָ��*/
    void delData(const int& pos);//, const int& nVal);
    /* �������ݲ��������ݽڵ�ָ�룬���򷵻ؿգ�����Ϊ������ʱҲ���ؿ�*/
    bool findData(const int& nVal);
    /* ��listβ���Ԫ��*/
    void appAfterTail(const int& nVal);
    /* ��list�����Ԫ��*/
    void appBeforeHead(const int& nVal);
    /* ��listβɾ��Ԫ��*/
    void delFromTail();
    /* ��list��ɾ��Ԫ��*/
    void delFromHead();
    /* �õ�βԪ�ص�����*/
    int& getTailVal();
    /* �õ���Ԫ�ص�����*/
    int& getHeadVal();
    /* �������*/
    void clearLinkedList();
};


#endif // LINKEDLIST_H
