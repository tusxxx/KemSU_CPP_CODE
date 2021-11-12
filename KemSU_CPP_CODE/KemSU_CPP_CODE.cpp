#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	ifstream file("C:\\text.txt");
	string stroke;
	file >> stroke;
	cout << stroke;
}

