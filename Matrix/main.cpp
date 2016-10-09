#include <iostream>
#include <cstring>

using namespace std;
class Matrix{
private:
    int Rows;
    int Cols;
    int *pData;

public:
    Matrix();
    Matrix(int m,int n,int *p=nullptr);
   /* Matrix(){
    Rows = 0;
    Cols = 0;
    pData = nullptr;
    }
    Matrix(int m,int n,int *p = nullptr){
    Rows = m;
    Cols = n;
    pData = p;
    }*/
    int getRows(){
        return Rows;
    }
    int getCols(){
        return Cols;
    }
    void setRows(int m){
        Rows = m;
    }
    void setCols(int n){
        Cols = n;
    }
    void setpData(int *p){
        pData = p;
    }

};

int main()
{
    Matrix mat;

    cout << mat.getCols() << endl;

    Matrix mat2(4,5);
    cout << mat2.getRows() << endl;
    cout << "Hello world!" << endl;
    return 0;
}


Matrix::Matrix():Rows(0),Cols(0),pData(nullptr) {
    /*Rows = 0;
    Cols = 0;
    pData = nullptr;*/
    }
    Matrix::Matrix(int m,int n,int *p){
    Rows = m;
    Cols = n;
    pData = p;
    }
