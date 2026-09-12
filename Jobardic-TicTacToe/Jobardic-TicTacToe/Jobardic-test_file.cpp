#include <iostream>
#include <windows.h>
using namespace std;

void testfunc() {

	SetConsoleOutputCP(CP_UTF8); //sets the console output encoding version to be able to use those special symbols.
	cout << "test output from function in 'Jobardic-test_file.cpp'" << endl;
	cout << "Using Letters: X O " << endl;
	cout << "Using special symbols which require setting encoding version to UTF8: ✕ 〇" << endl;
}