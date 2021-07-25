#include <bits/stdc++.h>
using namespace std;

void dfs(int cur,int par,vector<int> gr[],vector<int> &dp)
{
    dp[cur] = cur ;
    for(auto x:gr[cur])
    {
        if(x!= par)
        {
            dfs(x,cur,gr,dp) ;
            dp[cur] = min(dp[cur],dp[x]) ;
        }
    }
    return ;
}

int main() 
{
    int n,e ;
    cin>>n>>e ;
    vector<int> gr[n+1] ;
    while(e--)
    {
        int x , y ;
        cin>>x>>y ;
        gr[x].push_back(y) ;
        gr[y].push_back(x) ;
    }
    vector<int> dp(n+1) ;
    dfs(1,0,gr,dp) ;

    for(int i=1;i<=n;i++)
        cout<<i<<" has the minimun element = "<<dp[i]<<"\n" ;



    return 0 ;
}
