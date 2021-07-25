#include <bits/stdc++.h>
using namespace std;

void dfs(int cur,int par,vector<int> gr[],vector<int> &dp,vector<int> &visited,vector<int> &depth,int dep)
{
    visited[cur] = 1 ;
    dp[cur] = dep ;
    depth[cur] = dep ;   
    for(auto x : gr[cur])
    {
        if(visited[x] == 0)
        {
            dfs(x,cur,gr,dp,visited,depth,dep+1) ;
            dp[cur] = min(dp[cur] , dp[x]) ;
        }
        else if(x != par)
        {   //back edge
            dp[cur] = min(dp[cur] , depth[x]) ;
        }

    }
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
    vector<int> dp(n+1),visited(n+1),depth(n+1) ;
    dfs(1,0,gr,dp,visited,depth,0) ;

    for(int i=1;i<=n;i++)
        cout<<i<<" th have min hight using single back edge = "<<dp[i]<<"\n" ;



    return 0 ;
}
