#include <iostream>
using namespace std;
template<class _T>
class Mstack;
template<class _T>
class node
{
    friend class Mstack<_T>;
private:
    _T elem;
    node* next;
public:
    node(_T temp)
    {
        elem = temp;
        next=NULL;
    }
    ~node()
    {
        delete next;
    }
};
template<class _T>
class Mstack
{
private:
    node<_T>* top;
public:
    Mstack()
    {
        top=NULL;
    }
    ~Mstack()
    {
        delete top;
    }
    bool push(_T data)
    {
        node<_T>* newnode = new node<_T>(data);
        if(newnode == NULL)
        {
            return false;
        }
        else
        {
            if(top == NULL)
            {
                top = newnode;
            }
            else
            {
                newnode->next=top->next;
                top = newnode;
            }
            return true;
        }
    }
        bool pop(_T& data)
        {
            node<_T>* del = top;
            if(del == NULL)
            {
                return false;
            }
            else
            {
                data = top->elem;
                top = top->next;
                delete del;
                return true;
            }
        }
    };


        int main()
        {
            cout << "hello" << endl;
            return 0;
        }
