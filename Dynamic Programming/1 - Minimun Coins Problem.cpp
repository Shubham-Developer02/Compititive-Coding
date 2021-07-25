#include <bits/stdc++.h>
using namespace std;

int min_coins_Top_Down(int n,vector<int> &coins,vector<int> &dp)
{
    if(n==0)
        return 0 ;
    //if already computed
    if(dp[n] != 0)
        return dp[n] ;

    int ans = INT_MAX ;
    for(int i=0;i<coins.size() ;i++)
    {
        if(n-coins[i] >= 0)
        {
            int subproblem = min_coins_Top_Down(n-coins[i],coins,dp) ;
            ans = min(ans,subproblem + 1) ;
        }
    }
    dp[n] = ans ;
    return dp[n] ;
}

int min_coins_Bottom_Up(int n,vector<int> &coins,vector<int> &dp)
{
    // Iterate for all amounts from 1 to n
    for(int i=1;i<=n;i++)
    {
        dp[i] = INT_MAX ;
        //iterate for all coins for all corresponding amount 
        for(int j=0;j<coins.size();j++)
        {
            if(i - coins[j] >= 0)
            {
                int subproblem = dp[ i - coins[j] ] ;
                dp[i] = min(dp[i] , subproblem + 1) ;
            }
        }
    }
    return dp[n] ;

}

int main() 
{
    int n ;
    //cout<<"Enter the types of coin" ;
    cin>>n ;
    vector<int> coins(n) ;
    for(int i=0;i<n;i++)
        cin>>coins[i] ;
    
    int amount ;
    cin>>amount ;
    vector<int> dp(amount+1,0) ;
    cout<<min_coins_Bottom_Up(amount,coins,dp) ;

}
