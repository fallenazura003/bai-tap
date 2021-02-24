#include<iostream>
using namespace std;


void vetamgiac(int a)
{
	int m, n;
	n = 1;
	while (n <= a)
	{
		m = (a - n) / 2;
		for (int i = 0; i < m; i++)
		{
			cout << ' ';
		}
		for (int i = 0; i < n; i++)
		{
			cout << '*';
		}
		cout <<endl;
		n = n + 2;
	}
}
int main(int argc, char* args[])
{
	int  a;
	cin >> a;
	vetamgiac(a);
	return 0;
}
