#include <iostream>

using namespace std;
template<class _T>
class Mstack;

template<class _T>
class node{
private:
    _T elem;
    node* next;
public:
    node(_T data):elem(data),next(NULL){}
    ~node(){
    delete next;
    }
};
template<class _T>
class Mstack{
private:
    node<_T>* top;
public:
    Mstack():top(NULL){}
    ~Mstack(){
        delete top;
    }
    bool push(_T& temp){
        node<_T>* newnode = new node<_T>(temp);
        if(newnode==NULL){
            return false;
        }
        else{
            if(top == NULL){
                top = newnode;
            }
            else{
                newnode->next = top->next;
                top = newnode;
            }
            return true;
        }

    }
    bool pop(){
        if(top == NULL){
            return false;
        }
        else{
            node<_T>* del = top;
            top = del->next;
            delete del;
        }

    }

    _T& getTop(){
        return *top;
    }

    bool show(){
        if(top == NULL){
            return false;
        }
        node<_T>* p = top;
        for(p = top;p->next!=NULL;p = p->next){
        }
    }

};

struct position{
    int dx;
    int dy;
    string descirbe;

    position(int x=-1,int y=-1,string str=NULL):dx(x),dy(y),descirbe(str){}
    ~position(){}
};

position guide[4]={{1,0},{0,1},{-1,0},{0,-1}};

int main()
{
    int rows,cols;
    cin >> cols >> rows;

    int Map[rows][cols];
    int Mark[rows][cols];

    position startPos;
    position endPos;

    for(int i = 0;i < rows;i++){
        for(int j = 0; j < cols;j++){
            cin >> Map[i][j];
            if(Map[i][j] == 3){
                startPos.dx = i;
                startPos.dy = j;
                startPos.descirbe = "start position";
            }
            else if(Map[i][j] == 4){
                endPos.dx = i;
                endPos.dy = j;
                endPos.descirbe = "start position";
            }
        }
    }
    position lastPos = startPos;

    Mstack<position> path;

    path.push(startPos);

    while(path.getTop()!=endPos){

    }



    cout << "Hello world!" << endl;
    return 0;
}
