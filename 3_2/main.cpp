#include <iostream>
#include <cstring>

using namespace std;
class Vect{
private:
    int N;
    int * pData;
public:
    Vect(int len){
        N = len;
        pData = new int [N];

        memset(pData,0,N*sizeof(int));

    }
    Vect(int arr[]){
        int len = sizeof(arr)/sizeof(int*);
        N=len;
        cout << "sizeof arr=" << sizeof(arr) <<endl;
        cout << "sizeof int* =" << sizeof(int*) <<endl;
        cout <<  "N=" << N << endl;
        pData = new int [N];

            memcpy(pData,arr,N*sizeof(int));
    }
    Vect(Vect &r){
        N = r.N;
        pData = new int[N];

        memcpy(pData, r.pData, N * sizeof(int));

    }
//    ~Vect(){
//        delete pData;
//    }
    void print(){

        int i = 0;

        for(i=0;i<N;i++){
            cout << pData[i] << " ";
        }
        cout << endl;
    }
    void SetVect(int pos,int num){
        cout << "len = " << N <<endl;
        if(pos > N+1){
            cout << "out of boundary" << endl;
            return;
        }
        else{
            pData[pos] = num;
        }
    }
};
int main()
{
    int arr[5] = {1,2,3,4,5};

    cout << arr << endl;
    Vect v1(arr);

    cout << "len arr = " << sizeof(arr)/sizeof(int) << endl;

    int len ;
    int pos,num;
    cin >>  len ;
    cin >> pos >> num ;

    Vect v2(len);
    Vect v3(v1);

    v1.print();
    v2.print();

    v1.SetVect(pos,num);

    v1.print();
    v3.print();

    return 0;
}
