#include <iostream>

using namespace std;
class X{
    int m,n;
public:
    friend void print(X p);
    void getmn();
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
void X::getmn(){
    cout << "m=" << m <<endl;
    cout << "n=" << n << endl;
}
