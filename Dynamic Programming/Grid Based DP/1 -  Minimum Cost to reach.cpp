#include <bits/stdc++.h>
using namespace std;

//-----------------------Grid Based DP-------------------------------


int main() 
{
    int n,m ;
    cin>> n>>m ;
    vector<vector<int>> arr(n,vector<int> (m)) ;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j] ;
        }
    }
    vector<vector<int>> dp(n,vector<int> (m)) ;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i==0 && j==0)
                dp[i][j] = arr[0][0] ;
            else if(i==0)
                dp[0][j] = dp[0][j-1] + arr[0][j] ;
            else if(j==0)
                dp[i][0] = dp[i-1][0] + arr[i][0] ;
            else 
                dp[i][j] = min( dp[i-1][j] , dp[i][j-1] ) + arr[i][j] ;
        }
    }
    cout<<"Minimum cost to reach is = "<<dp[n-1][m-1] ;
}