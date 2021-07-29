#include <bits/stdc++.h>
using namespace std;

void filterChars(int n , char a[])
{
    int j = 0 ;
    while(n > 0)
    {
        int las_bit = n&1 ;
        if(las_bit)
            cout << a[j] ;
        
        j++ ;
        n = n>>1 ;
    }
    cout << "\n" ;
}

void printSubsets(char a[])
{
    int n = strlen(a) ;
    for (int i = 0 ; i < (1<<n) ; i++)
    {
        filterChars(i,a) ;
    }
    return ;
}

int main() {
    char a[100] ;
    cin >> a ;
    printSubsets(a) ;
}
