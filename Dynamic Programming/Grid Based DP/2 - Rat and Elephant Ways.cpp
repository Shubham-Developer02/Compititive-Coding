#include <bits/stdc++.h>
using namespace std;

//-----------------------Grid Based DP #2-------------------------------
//---------------------Rat and Elephant Ways----------------------------

int Rat_ways(int n,int m)
{
    vector<vector<int>> dp(n,vector<int> (m)) ;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j] = 1 ;
            }
            else
                dp[i][j] = dp[i-1][j] + dp[i][j-1] ;
        }
    }
    return dp[n-1][m-1] ;
}

int Elephant_ways(int n,int m)
{
    vector<vector<int>> dp(n,vector<int> (m)) ;
    dp[0][0] = 1 ;
    //for 1st row
    for(int i=0;i<m;i++)
    {
        for(int k = 0 ; k<i;k++)
        {
            dp[0][i] += dp[0][k] ;
        }
    }
    //for 1st column
    for(int i=0;i<n;i++)
    {
        for(int k = 0 ; k<i;k++)
        {
            dp[i][0] += dp[k][0] ;
        }
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            for(int k=0;k<i;k++)
            {
                dp[i][j] += dp[k][j] ;
            }
            for(int k=0;k<j;k++)
            {
                dp[i][j] += dp[i][k] ;
            }
        }
    }

    return dp[n-1][m-1] ;
}

int main() 
{
    int n,m ;
    cin>> n>>m ;
    cout<<Rat_ways(n,m)<<"\n" ;
    cout<<Elephant_ways(n,m)<<"\n" ;

}