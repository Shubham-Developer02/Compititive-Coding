#include <bits/stdc++.h>
using namespace std;

int n = 4 ;
int dist[10][10] = {    //Adjancency matrix
    {0,20,42,25},
    {20,0,30,34},
    {42,30,0,10},
    {25,34,10,0}
};
int dp[16][4] ;     // here 16 is bcoz 2^4 = 16 . Bcoz of dp the complexity reduce from n! to 2^n * n . 
int visitedAll = (1<<n) - 1 ;

int travelling_salesman(int mask,int pos)
{
    if(mask==visitedAll)
        return dist[pos][0] ;
    int ans = INT_MAX ;

    //look up 
    if(dp[mask][pos] != - 1)
        return dp[mask][pos] ;

    //try to go to unvisited city
    for(int city=0;city<n;city++)
    {
        if( (mask & (1<<city) ) ==0 )
        {
            int newAns = dist[pos][city] + travelling_salesman( (mask|(1<<city)),city ) ;
            ans = min(ans,newAns) ;
        }
    }
    return dp[mask][pos] = ans ;
}


int main() 
{
    for(int i=0; i < (1<<n) ; i++)
    {   
        for(int j=0;j<n;j++)
        {
            dp[i][j] = -1 ;
        }
    }

    cout<<"Minimun cost for tsp is = "<<(travelling_salesman(1,0))<<"\n" ;
    
    return 0 ;
}
