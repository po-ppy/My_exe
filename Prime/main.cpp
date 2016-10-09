#include <iostream>
#include <cmath>

using namespace std;
 int Prime(int n){
        int i = 2,x = (int) sqrt(n);
            while(i<=x){
                if(n%i == 0) break;
                i++;
            }
        if(i>x) return 1;
        else return 0;
        }
int main()
{
for(int i = 0;i<100;i++){
    cout << "i = " << i << " , Prime(i) = " << Prime(i) <<endl;
}

    return 0;
}
