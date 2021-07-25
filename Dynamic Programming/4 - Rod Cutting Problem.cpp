#include <bits/stdc++.h>
using namespace std;
//--------------Rod Cutting Problem----------------------------

int Rod_Cutting_DP(vector<int> &prices,int n)
{
    vector<int> dp(n+1) ;
    dp[0] = 0 ;
    for(int len=1;len<=n;len++)
    {
        dp[len] = INT_MIN ;
        for(int i=0;i<len;i++)
        {
            int cut = i + 1 ;
            int current_ans = prices[i] + dp[len - cut] ;
            dp[len] = max(dp[len],current_ans) ; 
        }
    }
    return dp[n] ;
}


int main() 
{
    int n ;
    cin>>n ;
    vector<int> rod(n) ;
    for(int i=0;i<n;i++)
        cin>>rod[i] ;
    
    cout<<Rod_Cutting_DP(rod,n) ;

}
