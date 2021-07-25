#include <bits/stdc++.h>
using namespace std;
#define int long long

int longest_path(int src,vector<vector<int>> &adj ,vector<int> &dp)
{
    if(dp[src] != -1)
        return dp[src] ;
    dp[src] = 0 ;
    for(auto nbr : adj[src])
    {
        dp[src] = max(dp[src] , 1 + longest_path(nbr , adj , dp )) ;
    }
    return dp[src] ; 
}

int32_t main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m ;
    cin>>n>>m;
    vector<vector<int>> adj(n) ;
    //vector<bool> visited(n) ;
    vector<int> dp(n,-1) ;
    while(m--)
    {
        int x,y ;
        cin>>x>>y ;
        x-- ;
        y-- ;
        adj[x].push_back(y) ;
    }
    int ans = INT_MIN ;
    for(int i=0;i<n;i++)
    {   
        ans = max(ans , longest_path(i , adj , dp )) ;
        
    }
    cout<<ans ;
}   