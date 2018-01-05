#include <iostream>

using namespace std;

/* 请在这里填写答案 */
#include <sstream>

class Fraction {
private:
    long long upper;
    long long lower;
public:
    Fraction() : upper(0), lower(0) {};

    Fraction(double num);

    Fraction(long long upper, long long lower) : upper(upper), lower(lower) {}

    long long calMaxFactor(long long num_1, long long num_2);

    void reduce();

    virtual  ~Fraction() = default;

    friend istream &operator>>(istream &is, Fraction &fraction);

    friend const Fraction operator+(const Fraction &fraction_1, const Fraction &fraction_2);

    friend const Fraction operator-(const Fraction &fraction_1, const Fraction &fraction_2);

    friend const Fraction operator*(const Fraction &fraction_1, const Fraction &fraction_2);

    friend const Fraction operator/(const Fraction &fraction_1, const Fraction &fraction_2);

    friend ostream &operator<<(ostream &os, const Fraction &fraction);

    explicit operator double() const;
};

Fraction::Fraction(double num) {
    long long upper = num * 10000000000000000 + 0.5;    // Fuck 0.5
    long long lower = 10000000000000000LL;
    Fraction fraction = Fraction(upper, lower);
    fraction.reduce();
    *this = fraction;
}

long long Fraction::calMaxFactor(long long num_1, long long num_2) {
    long long th = num_1, tl = num_2;
    if (num_1 < num_2) {
        th = num_2;
        tl = num_1;
    }
    if (th % tl == 0)
        return tl;
    else
        return calMaxFactor(tl, th % tl);
}

void Fraction::reduce() {
//    cout << "I am " << upper << "/" << lower << endl;
    // Reduce myself
    long long maxFactor = calMaxFactor(this->upper, this->lower);
    if (maxFactor > 1) {
        this->upper /= maxFactor;
        this->lower /= maxFactor;
    }
//    cout << "After reduction, I am " << upper << "/" << lower << endl;
}

const Fraction operator+(const Fraction &fraction_1, const Fraction &fraction_2) {
    long long upper = fraction_1.upper * fraction_2.lower + fraction_2.upper * fraction_1.lower;
    long long lower = fraction_1.lower * fraction_2.lower;
    Fraction newFraction(upper, lower);
    newFraction.reduce();
    return newFraction;
}

const Fraction operator-(const Fraction &fraction_1, const Fraction &fraction_2) {
    long long upper = fraction_1.upper * fraction_2.lower - fraction_2.upper * fraction_1.lower;
    long long lower = fraction_1.lower * fraction_2.lower;
    Fraction newFraction(upper, lower);
    newFraction.reduce();
    return newFraction;
}

const Fraction operator*(const Fraction &fraction_1, const Fraction &fraction_2) {
    long long upper = fraction_1.upper *  fraction_2.upper;
    long long lower = fraction_1.lower * fraction_2.lower;
    Fraction newFraction(upper, lower);
    newFraction.reduce();
    return newFraction;
}

const Fraction operator/(const Fraction &fraction_1, const Fraction &fraction_2) {
    long long upper = fraction_1.upper *  fraction_2.lower;
    long long lower = fraction_1.lower * fraction_2.upper;
    Fraction newFraction(upper, lower);
    newFraction.reduce();
    return newFraction;
}

istream &operator>>(istream &is, Fraction &fraction) {
    string str;
    is >> str;
    string string_upper = str.substr(0, str.find('/'));
    string string_lower = str.substr(str.find('/') + 1);
    stringstream sstream_upper(string_upper);
    stringstream sstream_lower(string_lower);
    sstream_upper >> fraction.upper;
    sstream_lower >> fraction.lower;
    return is;
}

ostream &operator<<(ostream &os, const Fraction &fraction) {
    os << fraction.upper << "/" << fraction.lower;
    return os;
}

Fraction::operator double() const {
    return this->upper / (double) this->lower;
}

int main() {
    Fraction f1;
    Fraction f2;
    cin >> f1 >> f2;
//    cout << "f1 + f2 = " << f1 + f2 << endl;
//    cout << "double(f1 + f2) = " << double(f1 + f2) << endl;
//    cout << "f1 - f2 = " << f1 - f2 << endl;
//    cout << "f1 * f2 = " << f1 * f2 << endl;
//    cout << "f1 / f2 = " << f2 / f1 << endl;
//    Fraction f1;
//    Fraction f2;
//    cin >> f1 >> f2;
    cout << f1 + f2 << endl;
    cout << (double) (f1 + f2) << endl;
    cout << f1 - f2 << endl;
    cout << f1 * f2 << endl;
    cout << f2 / f1 << endl;
    double d;
    cin >> d;
//    cout << "d = " << d << endl;
    Fraction f(d);
//    cout << "f = " << f << endl;
    cout << f << endl;
    f = 0.5;
//    cout << "f = " << f << endl;
    cout << f << endl;
    Fraction *p = &f1;
    f1 = *p;
//    cout << "f1 = " << f1 << endl;
    cout << f1 << endl;
    cin >> f1;
    f1 = f1 * Fraction(2.0);
//    cout << "f1 = " << f1 << endl;
    cout << f1 << endl;
}