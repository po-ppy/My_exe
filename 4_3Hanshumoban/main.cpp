#include <iostream>

using namespace std;
template<class _T>
void exchange(_T &a,_T &b){
    _T temp;
    temp = a;
    a = b;
    b = temp;
}
int main()
{
    int a ,b;
    char c,d;

    cin >> a >> b;
    cin >> c >>d ;

    exchange(a,b);
    exchange(c,d);

    cout << a << " "<< b << endl;
    cout << c << " "<< d << endl;
    return 0;
}
