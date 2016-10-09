#include <iostream>

using namespace std;
double getEarning(double salary, int absenceDays);

double getEarning(double baseSalary, double salesSum, double rate);

double getEarning(int workPieces, double wagePerPiece);

double getEarning(double hours, double wagePerHour);
int main()
{
    int sel;

    cout << "Please select..." << endl;
    cout << "1: Manager." << endl;
    cout << "2: Sales Man." << endl;
    cout << "3: Pieces Worker." << endl;
    cout << "4: Hour-Worker." << endl;
    cout << "Others: Quit" << endl;

    cin >> sel;

    double salary , baseSalary , salesSum , rate , wagePerPiece , hours , wagePerHour;
    int absenceDays , workPieces;

    switch(sel)
    {
    case 1:
        cin >> salary >> absenceDays;
        cout << getEarning(salary , absenceDays);
        break;
    case 2:
        cin >> baseSalary >> salesSum >> rate;
        cout << getEarning(baseSalary , salesSum , rate);
        break;
    case 3:
        cin >> workPieces >> wagePerPiece ;
        cout << getEarning(workPieces , wagePerPiece);
        break;
    case 4:
        cin >> hours >>  wagePerHour;
        cout << getEarning(hours, wagePerHour);
        break;
    default:
        break;
    }
    return 0;
}
double getEarning(double salary, int absenceDays){
    double sum;
    sum = salary - absenceDays*salary/22;
    return sum;
}

    double getEarning(double baseSalary, double salesSum, double rate){
        double sum;
        sum = baseSalary + salesSum*rate;
        return sum;
    }

    double getEarning(int workPieces, double wagePerPiece){
        double sum;
        sum = workPieces * wagePerPiece;
        return sum;
    }

    double getEarning(double hours, double wagePerHour){
        double sum;
        sum = hours * wagePerHour;
        return sum;
    }
