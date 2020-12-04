#include <iostream>
#include <sstream>
#include "integer.h"


using namespace std;

#define MAX_PARAM 10
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

	cout << "Memory Size? ";

	int memory_size = 0;
	cin >> memory_size;

	Integer *d = new Integer[memory_size];
	
	string param;
	getline(cin, param); 

	while(true)
	{		
		cout << "> ";

		// read command line
		getline(cin, param); 
		if( param.compare("x") == 0 )
			break;

		// split command string
		string arr[MAX_PARAM];
		int param_count = 0;
		stringstream ssin(param);
		while (ssin.good() && param_count < MAX_PARAM){
			ssin >> arr[param_count];
			++param_count;
		}

		// check param count
		if( param_count > 3 )	// if not provide sufficient information about connection
		{
			cout << "Invalid command, try again" << endl;
			continue;
		}

		if( arr[0][0] != 'i' )
		{
			cout << "Invalid command, try again" << endl;
			continue;
		}

		int num = atoi(arr[0].c_str() + 1);
		
		if( num < 1 || num > memory_size )
		{
			cout << "Invalid Variable, try again..." << endl;
			continue;
		}
		
		if( arr[1] == "?" )
		{
			cout << d[num - 1].toStr() << endl;
		}

		if( arr[1] == "=" )
		{
			d[num - 1] = Integer(arr[2]);
		}

		if( arr[1] == "+=" )
		{
			if( arr[2][0] == 'i' )
			{
				int num1 = atoi(arr[2].c_str() + 1);
				if( num1 < 0 || num1 > memory_size)
				{
					cout << "Invalid Variable, try again..." << endl;
					continue;
				}

				d[num - 1].add(d[num1 -1]);
			}
			else
			{
				d[num - 1].add(Integer(arr[2]));
			}
		}

		if( arr[1] == "<<" )
			d[num - 1].shift_left(atoi(arr[2].c_str()));

		if( arr[1] == ">>" )
			d[num - 1].shift_right(atoi(arr[2].c_str()));

		continue;
	}


	return 0;
}