#include <iostream>
using namespace std;

/* 请在这里填写答案 */
class Fraction {
private:

public:
    Fraction() = default;

    virtual  ~Fraction(){}
};

int main(void)
{
    Fraction f1;
    Fraction f2;
    cin >> f1 >> f2;
    cout << f1+f2 << endl;
    cout << (double)(f1+f2) << endl;
    cout << f1-f2 << endl;
    cout << f1*f2 << endl;
    cout << f2/f1 << endl;
    double d;
    cin >> d;
    Fraction f(d);
    cout << f << endl;
    f=0.5;
    cout << f << endl;
    Fraction*p = &f1;
    f1=*p;
    cout << f1 << endl;
    cin >> f1;
    f1 = f1*Fraction(2.0);
    cout << f1 << endl;
}