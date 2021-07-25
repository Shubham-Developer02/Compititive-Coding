#include <bits/stdc++.h>
using namespace std;
#define int long long

#define mod 1000000007

int Rat_ways(int n,int m,vector<vector<int>> &grid)
{
    int ans = 0 ;
    vector<vector<int>> dp(n,vector<int> (m)) ;
    bool forward = true,downward = true ;
    for(int i=0;i<m;i++)
    {
        if(forward && grid[0][i])
            dp[0][i] = 1 ;
        else
        {
            dp[0][i] = 0 ;
            forward = false ;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(downward && grid[i][0])
            dp[i][0] = 1 ;
        else
        {
            dp[i][0] = 0 ;
            downward = false ;
        }
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(grid[i][j])
            {
                dp[i][j] = ( dp[i-1][j] + dp[i][j-1] ) % mod ;
            }
            else
                dp[i][j] = 0 ;
        }
    }


    return dp[n-1][m-1] ;
}


int32_t main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,k ;
    cin>> n>>m>>k ;
    vector<vector<int>> grid(n,vector<int> (m , 1)) ;
    while(k--)
    {
        int i,j ;
        cin>>i>>j;
        i-- ;
        j-- ;
        grid[i][j] = 0 ;
    }
    cout<<Rat_ways(n,m,grid)<<"\n" ;
}