#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    fstream infile("in.txt",ios::in);
    fstream outfile("out.txt",ios::out);
    string temp;
//    getline(infile,outfile) ;
    getline(infile,temp);
    outfile << temp;
    cout <<  setw(10) << setfill('0')<<temp << endl;
    return 0;
}
