##6-1 vector（10 分）
本题要求实现一个Vector类模板，能实现数据的存储和访问。通过[]运算符访问时只能访问已经存在的元素，而通过add()方法访问时可以自动扩展内部存储空间。

注意，这个Vector的行为和std::vector是不同的

#函数接口定义：
``` C++
template <class T>
class Vector {
...
```
#裁判测试程序样例：
``` C++
#include <iostream>
using namespace std;

/* 请在这里填写答案 */

int main()
{
	Vector<int> vint;
	int n,m;
	cin >> n >> m;
	for ( int i=0; i<n; i++ ) {
		//	add() can inflate the vector automatically
		vint.add(i);	
	}
	//	get_size() returns the number of elements stored in the vector
	cout << vint.get_size() << endl;
	cout << vint[m] << endl;
	//	remove() removes the element at the index which begins from zero
	vint.remove(m);
	cout << vint.add(-1) << endl;
	cout << vint[m] << endl;
	Vector<int> vv = vint;
	cout << vv[vv.get_size()-1] << endl;
	vv.add(m);
	cout << vint.get_size() << endl;
}
```
#输入样例：

``` C++
100 50
```
#输出样例：

``` C++
100
50
99
51
-1
100
```