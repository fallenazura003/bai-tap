#include<iostream>
#include<stdlib.h>

using namespace std;
void sinhso(int a)
{
	int b = rand() % a;
	cout << b;
}

int main(int argc, char* args[])
{
	int a;
	cin >> a;
	sinhso(a);
	return 0;
}
