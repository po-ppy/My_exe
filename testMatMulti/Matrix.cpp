// 实现矩阵类
#include <cstring>
//#include <iostream>

#include "Matrix.h"

//using namespace std;

//------------------------------------------------
// 名称：Matrix()
// 功能：构造函数，仅将行、列数赋为0，
//          将数据指针赋值为nullptr（需要C++11支持）
// 参数：无
// 返回：无
// 作者：耿楠
// 日期：2016年5月30日
//------------------------------------------------
Matrix::Matrix()
{
    Rows = 0;
    Cols = 0;
    pData = nullptr;
}

//------------------------------------------------
// 名称：Matrix(int m, int n)
// 功能：构造函数，指定矩阵行、列值，并动态申请内存，
//          将矩阵数据指针向的内存赋0（需要cstring头文件支持）
// 参数：[int m]---矩阵的行数
//          [int n]---矩阵的列数
// 返回：无
// 作者：耿楠
// 日期：2016年5月30日
//------------------------------------------------
Matrix::Matrix(int m, int n)
{
    Rows = m;
    Cols = n;

    pData = new int [Rows * Cols];

    // 用内存操作函数将指定的内存区域清0（需要cstring头文件支持）
    memset(pData, 0, Rows * Cols * sizeof(int));
}

//------------------------------------------------
// 名称：Matrix(int *p, int m, int n)
// 功能：构造函数，指定矩阵行、列值，并动态申请内存，
//          将矩阵数据区用指针p指向值初始化（需要cstring头文件支持）
// 参数：[int *p] --- 整型指针，指向数组起始地址
//          [int m]---矩阵的行数
//          [int n]---矩阵的列数
// 返回：无
// 作者：耿楠
// 日期：2016年5月30日
//------------------------------------------------
Matrix::Matrix(int *p, int m, int n)
{
    Rows = m;
    Cols = n;

    pData = new int [Rows * Cols];

    // 内存复制（需要cstring头文件支持）
    memcpy(pData, p, Rows * Cols * sizeof(int));
}

//------------------------------------------------
// 名称：Matrix(int **p, int m, int n)
// 功能：构造函数，指定矩阵行、列值，并动态申请内存，
//          将矩阵数据区用指针p指向值初始化（需要cstring头文件支持）
// 参数：[int **p] --- 整型2维数组的指针，指向2维数组行指针数组的起始地址
//          [int m]---矩阵的行数
//          [int n]---矩阵的列数
// 返回：无
// 作者：耿楠
// 日期：2016年5月30日
//------------------------------------------------
Matrix::Matrix(int **p, int m, int n)
{
    Rows = m;
    Cols = n;

    pData = new int [Rows * Cols];

    // 按行复制内存，注意pData指向的内存是连续的（需要cstring头文件支持）
    for(int i = 0; i < Rows; i ++)
    {
        memcpy(pData + i * Cols, p[i], Cols * sizeof(int));
    }
}

//------------------------------------------------
// 名称：Matrix(Matrix &mat)
// 功能：拷贝构造函数（深拷贝）
//          分配内存后，将原矩阵数据区内容拷贝到分配的内存中（需要cstring头文件支持）
// 参数：[Matrix &mat] --- 已有矩阵对象的引用
// 返回：无
// 作者：耿楠
// 日期：2016年5月30日
//------------------------------------------------
Matrix::Matrix(Matrix &mat)
{
    Rows = mat.Rows;
    Cols = mat.Cols;

    pData = new int [Rows * Cols];

    // 复制内存（需要cstring头文件支持）
    memcpy(pData, mat.pData, Rows * Cols * sizeof(int));
}

//------------------------------------------------
// 名称：void Print()
// 功能：输出矩阵中的元素
// 参数：无
// 返回：无
// 作者：耿楠
// 日期：2016年5月30日
//------------------------------------------------
void Matrix::Print()
{
    // 定义临时用指针
    int *pTemp = nullptr;
    for(int i = 0; i < Rows; i++)
    {
        // 指向当前行起始位置
        pTemp = pData;
        pTemp += i * Cols;
        for(int j = 0; j < Cols; j++)
        {
            // 输出当前值
            cout << *pTemp << " ";
            // 指向当前行的下一个元素
            pTemp++;
        }
        cout << endl;
    }
}

//------------------------------------------------
// 名称：~Matrix()
// 功能：析构函数，清理内存
// 参数：无
// 返回：无
// 作者：耿楠
// 日期：2016年5月30日
//------------------------------------------------
Matrix::~Matrix()
{
    delete [] pData;
}

//------------------------------------------------
// 名称：int GetCell(int i, int j)
// 功能：获取矩阵中指定位置元素的值
// 参数：[int i] --- 指定行位置
//          [int j] --- 指定列位置
// 返回：int---返回指定位置矩阵元素的值
// 作者：耿楠
// 日期：2016年5月30日
//------------------------------------------------
int Matrix::GetCell(int i, int j) const
{
    return *(pData + i * Cols +j);
}

//------------------------------------------------
// 名称：void SetCell(int i, int j, int cell)
// 功能：设置矩阵中指定位置元素的值
// 参数：[int i] --- 指定行位置
//          [int j] --- 指定列位置
//          [int cell] --- 需要设置的值
// 返回：无
// 作者：耿楠
// 日期：2016年5月30日
//------------------------------------------------
void Matrix::SetCell(int i, int j, int cell)
{
    pData[i * Cols + j] = cell;
}

//------------------------------------------------
// 名称：void GetRowVec(int *pV, int i)
// 功能：获取矩阵中指定行的行向量
// 参数：[int *pV] --- 整型指针，指向行向量数组的起始地址（也就是一个1维数组）
//          [int i] --- 指定的行位置
// 返回：无
// 作者：耿楠
// 日期：2016年5月30日
//------------------------------------------------
void Matrix::GetRowVec(int *pV, int i)
{
    // 内存拷贝
    memcpy(pV, pData + i * Cols, Cols * sizeof(int));
}

//------------------------------------------------
// 名称：void GetColVec(int *pV, int j)
// 功能：获取矩阵中指定列的列向量
// 参数：[int *pV] --- 整型指针，指向列向量数组的起始地址（也就是一个1维数组）
//          [int j] --- 指定的列位置
// 返回：无
// 作者：耿楠
// 日期：2016年5月30日
//------------------------------------------------
void Matrix::GetColVec(int *pV, int j)
{
    // 用GetCell函数实现
    for(int i = 0; i < Rows; i++)
    {
        pV[i] = GetCell(i, j);
    }
}

//------------------------------------------------
// 名称：Matrix& MultiMat(const Matrix &mat)
// 功能：计算当前矩阵与另一个矩阵的乘积
// 参数：[const Matrix &mat] --- 整型指针，指向列向量数组的起始地址（也就是一个1维数组）
// 返回：Matrix&---当前矩阵与另一个矩阵的乘积结果
// 作者：耿楠
// 日期：2016年5月30日
//------------------------------------------------
Matrix Matrix::MultiMat(Matrix &mat)
{
    Matrix tempMat(Rows, mat.GetCols());

    int *pRowV = new int[Cols];
    int *pColV = new int[Cols];

    for(int i =0; i < Rows; i++)
    {
        for(int j = 0; j < mat.GetCols(); j++)
        {
            GetRowVec(pRowV, i);
            mat.GetColVec(pColV, j);
            tempMat.SetCell(i, j, GetDot(pRowV, pColV, Cols));
        }
    }
    delete []pRowV;
    delete []pColV;
    return tempMat;
}

//------------------------------------------------
// 名称：int GetDot(int *pV1, int *pV2, int m)
// 功能：计算两个向量的点积
// 参数：[int *pV1] --- 整型指针，指向第1个向量的起始地址
//          [int *pV2] --- 整型指针，指向第2个向量的起始地址
// 返回：int---两个向量的点积
// 作者：耿楠
// 日期：2016年5月30日
//------------------------------------------------
int Matrix::GetDot(int *pV1, int *pV2, int m)
{
    int sum = 0;

    for(int i = 0; i < m; i++)
    {
        sum += pV1[i] * pV2[i];
    }

    return sum;
}

ostream& operator<<(ostream& os, const Matrix &mat)
{
    for(int i = 0; i < mat.Rows; i++)
    {
        for(int j = 0; j < mat.Cols; j++)
        {
            os << mat.GetCell(i, j) << " ";
        }
        os << endl;
    }

    return os;
}
