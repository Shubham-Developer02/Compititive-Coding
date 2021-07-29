#include <bits/stdc++.h>
using namespace std;

void unique_no(vector<int> &arr , int n)
{
    int ans = 0 ;
    
    for(int i = 0 ; i < n ; i++)
        ans = ans^arr[i] ;
    
    cout << ans <<"\n" ;
}

int getBits(int n , int i)
{
    int mask = (1<<i)&n ;
    if(mask==0)
        return 0 ;
    return 1 ;
}

int setBits(int n,int i)
{
    int mask = (1<<i) ;
    int no = mask | n ;
    return no ;
}

void clearBit(int &n,int i)
{
    int mask = ~(1<<i) ;
    n =  mask & n ;
}

int clearIBits(int n , int i)
{
    int mask = ( -1 << i ) ;
    return n&mask ;
}

int clearRangeItoJ(int n,int i,int j)
{
    int ones = (~0);
    int a = ones<<(j+1) ;
    int b = (1<<j)-1 ;
    int mask = a | b ;
    int ans = n&mask ;
    return ans ; 
}


int main() 
{
    int n ; 
    cin >> n ;
    vector<int> arr(n) ;
    for(int i = 0 ; i < n ; i++)
        cin >> arr[i] ;
    
    //cout << setBits(9,2) ;



}
