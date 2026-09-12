#include <iostream>
#include <windows.h>

using namespace std;

void testfunc() {
	int test = 0;

	SetConsoleOutputCP(CP_UTF8); //sets the console output encoding version to be able to use those special symbols. Requires <windows.h>
	cout << "test output from function in 'Jobardic-test_file.cpp'" << endl;
	cout << "Using Letters: X O " << endl;
	cout << "Using special symbols which require setting encoding version to UTF8: ✕ 〇" << endl << endl;

	cin >> test;     //experimenting with clearing the console output.
	if (test == 1)
	{
		system("cls");
		cout << "console cleared?" << endl;
	}
}