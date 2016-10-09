#include <iostream>

using namespace std;
void Math(float a,float b,float &sum,float &sub,float &pro);
int main()
{
    float a;
    float b;
    float sum;
    float sub;
    float pro;

    cin >> a >> b;

    Math(a,b,sum,sub,pro);

    cout << sum << " "<<  sub <<" "<<  pro << endl ;
    return 0;
}
void Math(float a,float b,float &sum,float &sub,float &pro){
    sum = a + b;
    sub = a - b;
    pro = a * b;
}
