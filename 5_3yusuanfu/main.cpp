#include <iostream>

using namespace std;
class Rational{
private:
    int iUp;
    int iDown;
    int Gcd(int l ,int r){
        int temp;
        while(r!=0){
            temp=r;
            r=l%r;
            l = temp;
        }
        return l;
    }
        void Reduce(){
            int temp = Gcd(iUp,iDown);
            iUp = iUp/temp;
            iDown = iDown / temp;
    }
public:
    Rational(int l=0,int r=1){
        if(r==0){
            cout << "error input" << endl;
            //exit(1);
        }
        else{
            iUp = l;
            iDown = r;
            Reduce();
            if(iDown<0){
                iDown = -iDown;
                iUp = -iUp;
            }
        }
    }
    ~Rational(){}

const Rational operator-() const{
    return Rational(-iUp,iDown);
}
Rational & operator=(const Rational& right){
    iUp = right.iUp;
    iDown = right.iDown;
    return *this;
}
const Rational& operator++(){
    iUp = iUp + iDown;
    return *this;
}
const Rational& operator--(){
    iUp = iUp - iDown;
    return *this;
}

const Rational operator++(int x){
    iUp = iUp + iDown;
    return Rational(iUp-iDown,iDown);
}
const Rational operator--(int x){
    iUp = iUp - iDown;
    return Rational(iUp+iDown,iDown);
}
friend istream& operator>>(istream& is,Rational& op);
friend ostream & operator<<(ostream& os,const Rational& op);
friend const  Rational  operator+(const Rational& left,const Rational & right);
friend const  Rational  operator-(const Rational& left,const Rational & right);
friend const  Rational  operator*(const Rational& left,const Rational & right);
friend const  Rational  operator/(const Rational& left,const Rational & right);
friend bool operator<(const Rational& left,const Rational & right );
friend bool operator<=(const Rational& left,const Rational & right );
friend bool operator>(const Rational& left,const Rational & right );
friend bool operator>=(const Rational& left,const Rational & right );
};
istream& operator>>(istream& is,Rational & op){
    return is >> op.iUp >> op.iDown ;
}
ostream & operator<<(ostream& os,const Rational& op){
    os<< op.iUp << "/" <<op.iDown <<endl;
        return os;
}
const  Rational  operator+(const Rational& left,const Rational & right){
    return Rational(left.iUp*right.iDown+right.iUp*left.iDown,left.iDown*right.iDown);
}
const  Rational  operator-(const Rational& left,const Rational & right){
    return Rational(left.iUp*right.iDown-right.iUp*left.iDown,left.iDown*right.iDown);
}
const  Rational  operator*(const Rational& left,const Rational & right){
return Rational(left.iUp*right.iUp,left.iDown*right.iDown);
}
const  Rational  operator/(const Rational& left,const Rational & right){
return Rational(left.iUp*right.iDown,left.iDown*right.iUp);
}
bool operator<(const Rational& left,const Rational & right ){
    return left.iUp*right.iDown<left.iDown*right.iUp;
}
bool operator<=(const Rational& left,const Rational & right ){
return left.iUp*right.iDown<=left.iDown*right.iUp;
}
bool operator>(const Rational& left,const Rational & right ){
    return left.iUp*right.iDown>left.iDown*right.iUp;

}
bool operator>=(const Rational& left,const Rational & right ){
    return left.iUp*right.iDown>=left.iDown*right.iUp;

}
string com(bool flag){
    if(flag)
        return "true";
    else
        return "false";
}
int main()
{
    Rational a;
    Rational b;
    cin >>a >>b;
    cout << "a+b:" << a+b << endl;
    cout << "a-b:" << a-b << endl;
    cout << "a*b:" << a*b << endl;
    cout << "a/b:" << a/b << endl;
    cout << "-a:" << -a << endl;
    cout << "++a:" << ++a << endl;
    cout << "--a:" << --a << endl;
    cout << "a++:" << a++ << endl;
    cout << "a--:" << a-- << endl;
    cout << "a<b:" <<  com(a<b)  << endl;
    cout << "a<=b:" << com(a<=b) << endl;
    cout << "a>b:" << com(a>b) << endl;
    cout << "a>=b:" << com(a>=b) << endl;

    return 0;
}
