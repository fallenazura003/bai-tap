#include<iostream>
using namespace std;
void input1(int& x)
{
    cout << "Nhap he so so muon chuyen: ";
    cin >> x;
}
void input2(int& n)
{
    cout << "Nhap so can chuyen: ";
    cin >> n;
}

void chuyenHeSo(int n, int x)
{
    int mang[1000];
    int i = 0;
    while (n > 0) {


        mang[i] = n % x;
        n = n / x;
        i++;
    }
    cout << "Ket qua khi chuyen sang he co so "<<x <<" la:";
    for (int j = i - 1; j >= 0; j--)
    {
        switch (mang[j])
        {
        case 0:
        {
             cout<<0;
             break;
        }
        case 1:
            {
                cout <<1;
                break;
            }
        case 2:
            {
                cout <<2;
                break;
            }
        case 3:
            {
                cout <<3;
                break;
            }
        case 4:
            {
                cout <<4;
                break;
            }
        case 5:
            {
                cout <<5;
                break;
            }
        case 6:
            {
                cout <<6;
                break;
            }
        case 7:
            {
                cout <<7;
                break;
            }
        case 8:
            {
                cout <<8;
                break;
            }
        case 9:
            {
                cout <<9;
                break;
            }
        case 10:
            {
                cout <<'A';
                break;
            }
        case 11:
            {
                cout <<'B';
                break;
            }
        case 12:
            {
                cout <<'C';
                break;
            }
        case 13:
            {
                cout <<'D';
                break;
            }
        case 14:
            {
                cout <<'E';
                break;
            }
        case 15:
            {
                cout <<'F';
                break;
            }
        }
    }
}
int main()
{
    int x,n;
    char ch;
    input1(x);
    input2(n);
    chuyenHeSo(n,x);
    cout<<"\nBan co muon thu lai khong [Y/N]: ";
    cin>>ch;
    while(toupper(ch) == 'Y')
    {
        input1(x);
        input2(n);
        chuyenHeSo(n,x);
        cout<<"\nBan co muon thu lai khong [Y/N]: ";
        cin>>ch;
    }
    return 0;
}
