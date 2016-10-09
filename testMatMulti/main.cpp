// CodeBlocks支持中文的方法：
// 文件编码格式是utf-8
// g++编译器，加编译选项 -fexec-charset=GBK
#include <iostream>
#include "Matrix.h"
using namespace std;

// 测试矩阵类
int main()
{
    // 行、列值
    int m = 3, n =3;

    // 1维数组
    int arr1[9] = {1,2,3,4,5,6,7,8,9};

    // 2维数组
    int arr2[3][3] = {{1,2,3},{4,5,6},{7,8,9}};

    // 2维动态数组
    int **pM;
    pM = new int * [m];
    for(int i =0; i < m; i++)
    {
        pM[i] = new int [n];
        for(int j =0; j < n; j++)
        {
            pM[i][j] = (i + 3) * j;
        }
    }

    // 无参构造
    cout << "mat1：无参构造..." << endl;
    Matrix mat1;
    mat1.Print();

    // 无数据构造
    cout << "mat2：无数据构造..." << endl;
    Matrix mat2(m, n);
    mat2.Print();

    // 1维数组构造
    cout << "mat3：1维数组构造..." << endl;
    Matrix mat3(arr1, m, n);
    mat3.Print();

    // 2维静态数组构造
    cout << "mat4：2维静态数组构造..." << endl;
    Matrix mat4((int*)arr2, m, n);
    mat4.Print();

    // 2维动态数组构造
    cout << "mat5：2维动态数组构造..." << endl;
    Matrix mat5(pM, m, n);
    mat5.Print();

    // 拷贝构造
    cout << "mat6：拷贝构造..." << endl;
    Matrix mat6(mat5);
    //mat6.Print();
    cout << mat6;
    // 测试行、列向量处理
    int *pRowV, *pColV;
    pRowV = new int[n];
    pColV = new int[m];
    cout << endl;

    // 测试行向量
    mat6.GetRowVec(pRowV, 1);
    cout << "mat6矩阵的第2行的行向量..." << endl;
    for(int i = 0; i < n; i++)
    {
        cout << pRowV[i] << " ";
    }
    cout << endl;

    // 测试行向量
    mat6.GetColVec(pColV, 1);
    cout << "mat6矩阵的第2列的列向量..." << endl;
    for(int i = 0; i < m; i++)
    {
        cout << pColV[i] << " ";
    }
    cout << endl;

    // 释放内存
    for(int i = 0; i < m; i++)
    {
        delete [] pM[i];
    }

    delete [] pM;
    delete [] pRowV;
    delete [] pColV;


    // 测试乘法
    // 空间一个2维点
    int v1[3] = {1, 1, 1};
    // 旋转矩阵
    //  cost   sint sx
    // -sint   cost sy
    //  dx       dy   1
    int v2[3][3] = {{1, 0, 0},
                            {0, 1, 0},
                            {1,  0, 1}
                            };

    Matrix matMulti1(v1, 1, 3);
    Matrix matMulti2((int*)v2, 3, 3);

    cout << "矩阵乘法..." << endl;

    cout << matMulti1 << endl;
    cout << matMulti2 << endl;

    cout << matMulti1.MultiMat(matMulti2)  << endl;

    return 0;
}
