## 6-1 分数（10 分）
实现一个分数类Fraction,能读写“1/2”样子的分数。

# 函数接口定义：
``` C++
class Fraction {...
```
请根据main自行推断。

# 裁判测试程序样例：
``` C++
#include <iostream>
using namespace std;

/* 请在这里填写答案 */

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
```
# 输入样例：
``` C++
1/2
1/3
0.5
1/4
```
# 输出样例：
``` C++
5/6
0.833333
1/6
1/6
2/3
1/2
1/2
1/2
1/2
```