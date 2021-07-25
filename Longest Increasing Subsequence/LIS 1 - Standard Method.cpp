#include <bits/stdc++.h>
using namespace std;

// Complexity is O(n^2)

void LIS_Standard()
{
    int n ;
    cin >> n ;
    int a[n] ;
    for(int i =0 ; i <n ;i++)
        cin >> a[i] ;
    int dp[n] = {1} ;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < i ; j++)
        {
            if(a[j] < a[i])
                dp[i] = max(dp[i] , dp[j] + 1) ;
        }
    }
    int max_length = 0 ;
    for(int i =0 ; i <n ;i++)
        max_length = max(max_length,dp[i]) ;
        //cout << dp[i] <<" " ;
    cout << max_length ;
}

int main() 
{
    int t = 1 ;
    while(t--)
        LIS_Standard() ;

}
