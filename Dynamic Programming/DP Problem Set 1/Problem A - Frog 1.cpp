#include <bits/stdc++.h>
using namespace std;
#define int long long

// In this question you can optimize memory
// As current step is only depend upon previous 2 state 
// So you can save memory

int32_t main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n ;
    cin>> n ;
    vector<int> height(n) ;
    vector<int> dp(n) ;
    for(int i=0;i<n;i++)
    {
        cin>>height[i] ;
    }
    dp[0] = 0 ;
    dp[1] = abs(height[1] - height[0]) ;
    for(int i=2;i<n;i++)
    {
        int option1 = dp[i-2] + abs( height[i] - height[i-2] ) ;
        int option2 = dp[i-1] + abs( height[i] - height[i-1] ) ;
        dp[i] = min( option1 , option2 ) ;
    }
    cout<<dp[n-1] ;
}