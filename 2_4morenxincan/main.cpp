#include <iostream>
#include <cmath>
using namespace std;
float distance(float x1,float y1,float z1, float x2=0,float y2=0,float z2=0);
float P_C(float x,float y);
int main()
{
    float x1,y1,z1,x2,y2,z2;
    cin >> x1 >> y1 >> z1;
    cin >> x2 >> y2 >> z2;

    float dis1,dis2;

    dis1 = distance(x1,y1,z1);
    dis2 = distance(x1,y1,z1,x2,y2,z2);

    cout << dis1 << endl;
    cout << dis2 << endl;
    return 0;
}
float P_C(float x,float y){
    float result;
    result = (x-y)*(x-y);
    return  result;
}
float distance(float x1,float y1,float z1, float x2,float y2,float z2){
    float dis;
    dis = sqrt(P_C(x1,x2)+P_C(y1,y2)+P_C(z1,z2));
    return dis;
}
