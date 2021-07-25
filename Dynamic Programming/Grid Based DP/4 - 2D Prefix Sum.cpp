#include <bits/stdc++.h>
using namespace std;
#define int long long

// DOn't copy it ..... might be wrong somewhere....just understand

//------------------------2D Prefix SUM,Gold Grid ---------------

/*
    Very important concept ..... Prefix sum in 2D
    Formula for prefix sum for i,jth coordinate is :->
        arr[x][y] = arr[x-1][y] + arr[x][y-1] - arr[x-1][y-1]
*/


int32_t main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m ;
    cin>> n>>m ;
    // 1 based indexing
    vector<vector<int>> arr(n+1,vector<int> (n+1,0)) ;
    while(m--)
    {
        int i,j ;
        cin>>i>>j ;
        arr[i][j] = 1 ;
    }

    vector<vector<int>> dp(n+1,vector<int>(n+1)) ;
    //intialize 1st row and 1st column
    dp[0][0] = 0 ;
    for(int i=1;i<=n;i++)
    {
        dp[i][0] = dp[i-1][0] + arr[i][0] ;
        dp[0][i] = dp[0][i-1] + arr[0][i] ;
    }
    for(int i=2;i<=n;i++)
    {
        for(int j=2;j<=n;j++)
        {
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + arr[i][j] ;
        }
    }
    // Till now prefix array is calculated
    
    int ans = INT_MIN ;
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<n;j++)
        {
            int option1 = dp[i][j] ;
            int option2 = dp[i][n] - dp[i][j] ;
            int option3 = dp[n][j] - dp[i][j] ;
            int option4 = dp[n][n] - option1 - option2 - option3 ;

            ans = max(ans , min( min(option1,option2) , min(option3 , option4) ) ) ;

        }
    }

    cout << ans ;

}