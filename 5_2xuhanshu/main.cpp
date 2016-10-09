#include <iostream>
#include <string>
#include <cstring>
#include "stdlib.h"
using namespace std;
class Person
{
protected:
    string szName;
public:
    Person(string inSzName):szName(inSzName) {}
    ~Person() {}
    virtual void Print()
    {
        cout << "Person " << szName << endl;
    }
};
class Student:public Person
{
protected:
    int iNumber;
public:
    Student(string inSzName,int inINumber):Person(inSzName),iNumber(inINumber) {}
    ~Student() {}
    void Print()
    {
        cout << "Student " << szName << " " << iNumber << endl;
    }
};
class Teacher:public Person
{
protected:
    int iYear;
public:
    Teacher(string inSzName,int inIYear):Person(inSzName),iYear(inIYear) {}
    ~Teacher() {}
    void Print()
    {
        cout << "Teacher " << szName << " " << iYear << endl;
    }
};
class Graduate:public Student
{
protected:
    string szResearch;
public :
    Graduate(string inSzName,int inINumber,string inSzResearch):Student(inSzName,inINumber) {}
    ~Graduate() {}
    void Print()
    {
        cout << "Graduate " << szName<< " " << iNumber << " " << szResearch << endl;
    }
};
int main()
{
    //cout << "Hello world!" << endl;
    int n;
    cin >> n;
    Person* arr[n];
    string temp;
    int i = 0;
    for(i=0; i<n; i++)
    {
        cin >> temp;
        if(temp == "Person")
        {
            string name;
            cin >> name;
            arr[i] = new Person(name);
        }
        else if(temp == "Student")
        {
            string name;
            int number;
            cin >> name >> number;
            arr[i] = new Student(name,number);
        }
        else if(temp=="Teacher")
        {
            string name;
            int year;
            cin >> name >>year;
            arr[i] = new Teacher(name,year);
        }
        else if(temp == "Graduate")
        {
            string name;
            int number;
            string research;
            cin >> name >> number >> research;
            arr[i]= new Graduate(name,number,research);
        }
        else
        {
            cout << "Error input!!" << endl;
        }
    }

    int num[n];
    int _count = 0;
    for(i=0; i<n; i++)
    {
        num[i] = 0;
    }
    //char ch[5];
    i = 0;
    cin >> temp;
    while(temp!="exit")
    {

//
//        if(static_cast<int>(temp) <= 0 || static_cast<int>(temp) > (n-1)){
//            cout << "invaliable number" <<endl;
//        }

        {
            // char ch ;
            char * end;
            num[i] = static_cast<int>(strtol(temp.c_str(),&end,10));

            _count++;
//            cout << "num[]" << num[i] << endl;
//            cout << "i = " << i << endl;
//            cout << "_count = " << _count << endl;


        }
        i++;
        cin >> temp;
    }

    for(i=0; i < _count ; i++)
    {
//        cout << "arr_num[]" << num[i] <<endl ;
        arr[(num[i])]->Print();
    }
    return 0;
}


