#include<iostream>

using namespace std;

int UCLN(int a, int b)
{
	if (a == 0 || b == 0){
        return a + b;
    }
    while (a != b){
        if (a > b){
            a -= b; 
        }else{
            b -= a;
        }
    }
    return a;
}

int main(int argc, char* args[])
{
	int a,b;
	cin >> a >> b;
	UCLN(a, b);
	return 0;
}
