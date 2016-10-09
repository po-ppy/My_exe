#include <iostream>
#include <cstring>

#define N 5

using namespace std;
struct Student {
int  Id;
string name;
string sex;
int age;
Student *pnext;

//Student(){
//sex = name = "";
//age =0;

//Id = 0;
//pnext = nullptr;
//}

//Setstu(int sId ,string sname ,string ssex,int sage)
};
void sinput(Student *pfirst){
int i = 0;
Student *p = pfirst;
for(i=0;i<N;i++){
    cin >> p->Id >> p->name >> p->sex >> p->age ;
    p->pnext = p->pnext->pnext ;
}
}
void soutput(Student *pfirst){
int i = 0;
Student *p = pfirst;
for(i=0;i<N;i++){
    cout << p->Id << endl;
    cout << p->name << endl;
    cout << p->sex << endl;
    cout << p->age << endl;
    p->pnext = p->pnext->pnext ;
}
}
int main()
{
    Student *student[N];
    int i = 0;
    for(i=0;i<N;i++){
        student[i] = new Student ;
    }
    for (i=0;i<N-1;i++){
        student[i]->pnext = student[i+1];
    }
    sinput(student[0]);

    soutput(student[0]);


    //cout << "Hello world!" << endl;
    return 0;
}
