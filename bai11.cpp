#include<iostream>

using namespace std;

void chuyenHeSo(int n) 
{ 
    
    int mangNhiPhan[1000]; 
 
    
    int i = 0; 
    while (n > 0) { 
 
         
        mangNhiPhan[i] = n % 2; 
        n = n / 2; 
        i++; 
    } 
 
     
    for (int j = i - 1; j >= 0; j--) 
        cout << mangNhiPhan[j]; 
} 
  
int main(int argc, char* args[]) 
{ 
    int n ;
	cin >> n; 
    chuyenHeSo(n); 
    return 0; 
}
