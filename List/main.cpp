#include <iostream>
#include <stdlib.h>
#define MAXSIZE 50
using namespace std;
 template <class  _T>
class List{
public:
    _T *pData;
    int maxSize;
    int last;
public:
    List(){
        maxSize = MAXSIZE;
        pData = new _T [maxSize];
        last = -1;
    }
    List(_T * p,int n){
        maxSize = MAXSIZE;
        pData = new _T [maxSize];
        for(int i = 0;i < n; i++){
            pData[i] = p[i];
        }
        last = n-1;
    }
    List(List &op){
        maxSize = MAXSIZE;
        pData = new _T [maxSize];
        for(int i = 0;i <= op.last; i++){
            pData[i] = op.pData[i];
        }
        last = op.last;
    }
    ~List(){
        delete [] pData;
        //delete pData;
    }
    bool add( int loc,_T num){
        if(loc-1 > last){
            return false;
        }
        else{
            for(int i = last;i >= loc-1;i-- ){
                pData[i+1] = pData[i];
            }
            pData[loc -1 ] = num;
            last++;
            return true;
        }
    }
    bool del(int loc){
        if(loc-1 > last){
            return false;
        }
        else{
            for(int i = loc - 1;i < last;i++ ){
                pData[i] = pData[i+1];
            }
            last--;
            return true;
        }
    }
    _T searchNum(_T num){
        for(int i = 0;i<last;i++){
            if(pData[i] == num){
                return i+1;
            }
            else{
                return -1;
            }
        }
    }
    bool update(int loc,_T num){
        if(loc-1 > last){
            return false;
        }
        else{
            pData[loc -1] = num;
            return true;
        }
    }
   void operator=(const List &op){

            for(int i = 0 ;i < op.last;i++){
                pData[i] = op.pData[i];
            }
            last = op.last;

    }
    template <class _U>
    friend ostream& operator <<  (ostream& os, const List<_U> & op);
};
template <class _U>
ostream& operator<<  ( ostream& os, const List<_U> &op){
    for(int i = 0;i<op.last;i++){
        os << op.pData[i] << " ";
    }
    os << op.pData[op.last] << endl;
    return os;
}
int main()
{
    List<int> lst;
    lst.add(1,100);
    cout << lst;
    List<int> lst2(lst);
    cout << lst2;
    int n = 10;
    int a[10];
    for (int i =0 ;i< n;i++){
        a[i] = i;
    }
    List<int> lst4(a,10);

    cout << lst4;
    lst4.del(10);
    cout << lst4;
    lst4.add(1,100);
    cout << lst4;

    return 0;
}
