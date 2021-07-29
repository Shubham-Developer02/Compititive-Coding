#include <bits/stdc++.h>
using namespace std;

// Question Link :- https://hack.codingblocks.com/app/practice/5/433/problem


int main() 
{
    int n ;
    cin >> n ;
    vector<int> arr(n) ;
    vector<int> count(64,0) ;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> arr[i] ;
        int temp = arr[i] ;
        int j = 0 ;
        while(temp > 0)
        {
            count[j] += temp&1 ;
            temp = temp>>1 ;
            j++ ;
        }
    }

    int p = 1 ;
    int ans = 0 ;
    for(int i = 0 ; i < 64 ; i++)
    {
        count[i] %= 3 ;
        ans += count[i]*p ;
        p = p<<1 ; 
    }
    cout << ans ;
}
