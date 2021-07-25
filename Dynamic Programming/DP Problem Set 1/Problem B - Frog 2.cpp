#include <bits/stdc++.h>
using namespace std;
#define int long long


int32_t main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k ;
    cin>> n>>k ;
    vector<int> height(n) ;
    vector<int> dp(n) ;
    for(int i=0;i<n;i++)
    {
        cin>>height[i] ;
    }
    dp[0] = 0 ;
    // dp[1] = abs(height[1] - height[0]) ;
    for(int i=1;i<n;i++)
    {
        dp[i] = INT_MAX ;
        for(int j=1 ; j<= k ;j++)
        {
            if(i - j >= 0)
            {
                int option1 = dp[i-j] + abs(height[i-j] - height [i]) ;
                dp[i] = min(dp[i] , option1) ;
            }
            else
                break ;
        }
    }
    cout<<dp[n-1] ;
}