#include "stdafx.h"

using namespace std;

int main()
{
	Battery battery;
	battery.init();
	string chain = "2*(2+5*(2+3))";
	cout << battery.chainBalancing(&chain);

	system("pause");
	return EXIT_SUCCESS;
}
