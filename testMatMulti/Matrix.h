#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

#include <iostream>
using namespace std;

// 定义矩阵类
class Matrix
{
public:
    // 无参构造函数
    Matrix();
    // 指定大小，无数据的构造函数
    Matrix(int m, int n);
    // 指定大小，用1维数组初始化数据的构造函数
    Matrix(int *p, int m, int n);
    // 指定大小，用2维数组初始化数据的构造函数
    Matrix(int **p, int m, int n);
    // 深拷贝构造函数
    Matrix(Matrix &mat);
    // 析构函数
    ~Matrix();

    // 输出矩阵
    void Print();

    // 获取指定位置的矩阵元素的值
    int GetCell(int i, int j) const;
    // 设置指定位置的矩阵元素的值
    void SetCell(int i, int j, int cell);

    int GetRows(){return Rows;}
    int GetCols(){return Cols;}

    Matrix MultiMat(Matrix &mat);

    // 获取指定行的行向量
    void GetRowVec(int *pV, int i);
    // 获取指定列的列向量
    void GetColVec(int *pV, int j);

    friend ostream& operator<<(ostream& os, const Matrix &mat);

private:
    int GetDot(int *pV1, int *pV2, int m);

    int Rows;     // 矩阵的行数
    int Cols;       // 矩阵的列数
    int *pData;   //   矩阵数据的指针
};

#endif // MATRIX_H_INCLUDED
