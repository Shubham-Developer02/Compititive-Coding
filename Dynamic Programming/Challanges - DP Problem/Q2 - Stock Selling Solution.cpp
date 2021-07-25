#include <bits/stdc++.h>
using namespace std;
#define int long long


void solution()
{
    int trans , n ; 
    cin >> trans >> n ;
    vector<int> arr(n+1) ;
    for(int i = 1 ;i <= n ; i++ )
        cin >> arr[i] ;
    vector<vector<int>> dp(trans+1 , vector<int> ( n+1 ) ) ;
    for(int i = 1 ; i <= trans ; i++)
        dp[i][0] = 0 ;
    for(int j = 1 ;j <=n ; j++)
        dp[0][j] = 0 ;
    for(int t = 1 ; t <= trans ; t++)       // for particular transaction
    {
        for(int i = 1 ; i <=n ; i++)        // selecting the day for which you sell the stock
        {
            int profit = 0 ;
            for(int j = 1 ; j < i ; j++)    // selecting the day for which you buy the stock
            {
                profit = max( profit , arr[i] - arr[j] + dp[t-1][j-1] ) ;
            }
            dp[t][i] = max( dp[t][i-1] , profit ) ;     // which is better , wheather to include or exclude 
        }
    }
    cout<<dp[trans][n]<<"\n" ;
}


int32_t main() 
{
    int t ;
    cin >> t ;
    while( t-- )
    {
        solution() ;
    }

}
