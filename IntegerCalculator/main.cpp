#include <iostream>
#include "integer.h"
using namespace std;
int main()
{
	Integer i1; // default constructor => 0
	Integer i2("2"); // constructor => 123
	Integer i3("123456"); // constructor => 456

	i1.add(i2); // i1 += i2;
	i2.add(i3); // i2 += i3;
	cout << i1.toRawStr() << endl;
	cout << i2.toStr() << endl;
	cout << i3.toRawStr() << endl;

	i2.shift_left(1);
	cout << i2.toStr() << endl;

	i3.shift_right(3);
	cout << i3.toStr() << endl;

	return 0;
}