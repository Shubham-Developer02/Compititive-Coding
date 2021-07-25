#include <bits/stdc++.h>
using namespace std;
#define int long long

int knapsack(int n,int w,vector<int> &weight,vector<int> &value)
{
    vector<vector<int>> dp(n+1,vector<int> (w+1)) ;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=w;j++)
        {
            if(i==0 || j==0)
                dp[i][j] = 0 ;
            else if(weight[i-1] > j)
                dp[i][j] = dp[i-1][j] ;
            else
                dp[i][j] = max( value[i-1] + dp[i-1][j-weight[i-1]] , dp[i-1][j]) ;
        }
    }
    return dp[n][w] ;
}

int32_t main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,w ;
    cin>> n >>w ;
    vector<int> weight(n),value(n) ;
    for(int i=0;i<n;i++)
    {
        cin>>weight[i]>>value[i] ;
    }
    cout<<knapsack(n,w,weight,value) ;
}