#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
class Student{
    private:

    int ID;
    string Gender;
    string Birthday;
    string EnrollmentDate;
    public:
        Student(int inID = 0,string inGender = nullptr,string inBirthday = nullptr,string inEnrollmentDate = nullptr):
            ID(inID),Gender(inGender),Birthday(inBirthday),EnrollmentDate(inEnrollmentDate){}
        ~Student(){}
    void show(){
        cout << ID << "//" << Gender << "//" << Birthday << "//" << EnrollmentDate << endl;
    }
    int getID(){
        return ID;
    }

};
int main()
{
	string inFile;
	string outFile;
	cin >> outFile >> inFile;
	
    char *c_str = NULL;
    char *p;

    c_str = (char *)s1.c_str();
    p = strtok(c_str, "/");
    while(p != NULL)
    {
        cout << strlen(p) << '\t' << p << endl;
        p = strtok(NULL, " !");
    }
    cout << "Hello world!" << endl;
    return 0;
}
