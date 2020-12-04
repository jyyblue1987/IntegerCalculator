#include <iostream>
#include "integer.h"
using namespace std;
int main()
{
	Integer i1; // default constructor => 0
	Integer i2("2"); // constructor => 123
	Integer i3("99999"); // constructor => 456

	i1.add(i2); // i1 += i2;
	i2.add(i3); // i2 += i3;
	cout << i1.toRawStr() << endl;
	cout << i2.toStr() << endl;
	cout << i3.toRawStr() << endl;
	return 0;
}