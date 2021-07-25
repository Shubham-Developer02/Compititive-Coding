#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define mod 1000000007

//white means color 1 , black means 0

int total_ways(int src,int color,int par,vector<int> adj[] , vector<vector<int>> &dp)
{

    if(dp[src][color] != -1)
        return dp[src][color] ;
    int ans = 0 , ways1 =1 , ways2 = 1;
    // paint white
    for(auto nbr : adj[src])
    {
        if(nbr != par)
        {
            ways1 = ( ways1 * total_ways(nbr,1,src,adj,dp) ) % mod ;
        }
    }
    ans = ( ans + ways1 ) % mod ;
    //paint black only if parent color is 1
    if(color==1)
    {
        for(auto nbr : adj[src] )
        {
            if(nbr != par)
            {
                ways2 = ( ways2 * total_ways(nbr,0,src,adj,dp) ) % mod ;
            }
        } 
        ans = ( ans + ways2 ) % mod ;  
    }

    
    return dp[src][color] = ans ;
}


int32_t main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n ;
    cin>>n;
    vector<int> adj[n+1] ;
    for(int i=0;i<n-1;i++)
    {
        int x , y ;
        cin>>x>>y ;
        adj[x].push_back(y) ;
        adj[y].push_back(x) ;
    }
    vector<vector<int>> dp(n+1,vector<int>(2,-1)) ;
    cout << total_ways(1,1,-1,adj,dp) ;
   
}
