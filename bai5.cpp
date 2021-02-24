#include<iostream>
#include<cmath>

using namespace std;
bool checkNT(int a)
{
	if (a < 2)
		return false;
	else
	{
		int n = 0;
		for (int i = 2; i <= sqrt(a); i++)
		{
			if (a % i == 0)
			{
				n++;
			}
		}
		if (n == 0)
			return true;
		return false;
	}
}

int main(int argc, char* args[])
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		if (checkNT(i))
			cout << i << ' ';
	}
	return 0;
}


