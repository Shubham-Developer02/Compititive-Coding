#include <bits/stdc++.h>
using namespace std;

int countSetbits(int n)
{
    int ans = 0 ;
    while(n>0)
    {
        ans += (n&1) ;
        n = n >> 1 ;
    }
    return ans ;
}

// optimized Way
int countSetbitsFast(int n)
{
    int ans = 0 ;
    while(n>0)
    {
        n = n&(n-1) ;
        ans++ ;
    }
    return ans ;
}


int main() 
{
    int n ;
    cin >> n ;
    cout << countSetbits(n) <<"\n" ;
    cout << countSetbitsFast(n) <<"\n" ;
    cout << __builtin_popcount(n) <<"\n" ;
}
