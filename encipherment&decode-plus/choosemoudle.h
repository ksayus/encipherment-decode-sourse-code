#ifndef CHOOSEMOUDLE
#define CHOOSEMOUDLE

#include <iostream>
#include "password_txt.cpp"

using namespace std;

int moudle_1 = 0;
int moudle_2 = 0;


void choosemoudle()
{
	cout << "ÇëÑ¡ÔñÄ£Ê½:" << endl;
	cout << mode_encryption_1 << "    " << mode_encryption_2 << endl;
	do {
		cin >> moudle_1;
	} while (moudle_1 != 1 && moudle_1 != 2 && moudle_1 != 3);
}

#endif // !CHOOSEMOUDLE

