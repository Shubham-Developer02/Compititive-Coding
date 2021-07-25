#include <bits/stdc++.h>
using namespace std;
#define int long long


double total_prob(int n,int head,vector<double> &prob,vector<vector<double>> &dp)
{
    if(head==0)
        return 1 ;
    else if(n==0)
        return 0 ;
    else if(dp[n][head] != -1)
        return dp[n][head] ;
    
    dp[n][head] = prob[n]*(total_prob(n-1,head-1,prob,dp) )  + 
                        (1-prob[n])*(total_prob(n-1,head,prob,dp)) ;
    return dp[n][head] ;
}

int32_t main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n ;
    cin>> n ;
    vector<double> prob(n+1) ;
    for(int i=1;i<=n;i++)
        cin>>prob[i] ;
    vector<vector<double>> dp(n+1,vector<double>(n+1,-1)) ;
    cout<<fixed<<setprecision(10)<<total_prob(n,(n+1)/2,prob,dp) ;

}   