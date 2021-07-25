#include <bits/stdc++.h>
using namespace std;
//--------------Ladder Problem----------------------------

// You can write top down or bottom up ...no problem
// Here is best optimized approach 

int ladder_best_approach(int n,int k)
{   
    vector<int> dp(n+1,0) ;
    dp[0] = dp[1] = 1 ;
    for(int i=2;i<=k;i++)
        dp[i] = 2*dp[i-1] ;
    for(int i=k+1;i<=n;i++)
        dp[i] = 2*dp[i-1] - dp[i-k-1] ;

   /* for(int i=1;i<=n;i++)
        cout<<dp[i]<<" " ;
    cout<<"\n" ;
    */
    return dp[n] ;

}


int main() 
{
    int n , k ;
    cin >>n>> k;
    // n is the ladder no for which we want to know the no of ways
    // k is the no of stairs in which in corresponding stair depend  .
    // for eg :- if k =3 , dp[n] = dp[n-1] + dp[n-2] + dp[n-3]
    cout<<ladder_best_approach(n,k) ;

}
