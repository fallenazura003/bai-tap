#include<iostream>
#include<iomanip>

using namespace std;
void lamtron(double a)
{
	cout << fixed << setprecision(0)<<a;
}

int main(int argc, char* args[])
{
	double a;
	cin >> a;
	lamtron(a);
	return 0;
}
