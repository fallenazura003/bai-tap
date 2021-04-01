#include<iostream>
#include<math.h>

using namespace std;
/*# define int a = 10;
# define int b = 11;
# define int c = 12;
# define int d = 13;
# define int e = 14;
# define int f = 15;*/

void chuyen10_2(int n) 
{ 
    
    long long soHe2 = 0;
    int p = 0;
    while (n > 0)
    {
        soHe2 += (n % 2) * pow(10, p);
        ++p;
        n /= 2;
    }
    cout<< "Ket qua: "<<soHe2; 
} 
void chuyen2_10(int n)
{
	int p = 0;
    long long soHe10 = 0;
    while (n > 0)
    {
        soHe10 += (n % 10) * pow(2, p);
        ++p;
        n /= 10;
    }
    cout<<  "Ket qua: "<<soHe10;
}
void chuyen2_8(int n)
{
	int p = 0;
	long long soHe8 = 0;
	while (n > 0)
	{
		soHe8 += (n%8) * pow(2, p);
		++p;
		n /=8;
	}	
	cout<< "Ket qua: "<< soHe8;
}
void chuyen8_2(int n)
{
	int p = 0;
	long long soHe2 = 0;
	while (n > 0)
	{
		soHe2 += (n%2) * pow(8, p);
		++p;
		n /=2;
	}
	cout<< "Ket qua: "<< soHe2;
}
void chuyen2_16(int n)
{
	int p = 0;
	long long soHe16 = 0;
	while (n > 0)
	{
		soHe16 += (n%16) * pow(2, p);
		++p;
		n /=16;
	}
	cout<< "Ket qua: "<< soHe16;
}
void chuyen16_2(int n)
{
	int p = 0;
	long long soHe2 = 0;
	while (n > 0)
	{
		soHe2 += (n%2) * pow(16, p);
		++p;
		n /=2;
	}
	cout<< "Ket qua: "<< soHe2;
}

  
int main(int argc, char* args[]) 
{ 
	cout << "Chuong trinh chuyen doi he co so"<< endl;
	cout << "Chon cach chuyen he co so: "<<endl;
	int x;
	cout << "1: chuyen 10 -> 2" << endl;
	cout <<	"2: chuyen 2  -> 10" << endl;
	cout << "3: chuyen 2  -> 8"<<endl;
	cout << "4: chuyen 8  -> 2"<<endl;
	cout << "5: chuyen 2 -> 16"<<endl;
	cout << "6: chuyen 16 -> 2"<<endl;
	cin >> x;
	cout << "Nhap so can chuyen doi: ";
    int n ;
	cin >> n;
	switch (x)
	{
		case 1:
			{
				chuyen10_2( n);
				break;
			}
		case 2:
			{
				chuyen2_10( n);
				break;
			}
		case 3:
			{
				chuyen2_8( n);
				break;
			}
		case 4:
			{
				chuyen8_2( n);	
				break;
			}
		case 5:
			{
				chuyen2_16( n);
				break;
			}
		case 6:
			{
				chuyen16_2( n);
				break;
			}		
	}  
    return 0; 
}
