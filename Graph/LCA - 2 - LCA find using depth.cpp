#include <bits/stdc++.h>
using namespace std;

const int N=100005,M=22 ;
vector<int> gr[N] ;
int Par[N][M] , dep[N] ;

void calc_sparse_table(int cur,int par)
{
    Par[cur][0] = par ;
    for(int j=1;j<M;j++)
        Par[cur][j] = Par[ Par[cur][j-1] ][ j-1 ] ;

    for(auto x : gr[cur])
    {
        if(x != par)
        {
            calc_sparse_table(x,cur) ;
        }
    }
}


void dfs(int cur,int par)
{
    for(auto x : gr[cur])
    {
        if(x!= par)
        {
            dep[x] = dep[cur] + 1 ;
            dfs(x,cur) ;
        }
    } 
    return ;
}


int LCA_using_depth(int u,int v)
{
    if(u==v) return u;
    if(dep[u] < dep[v] )    swap(u,v) ;
    int diff = dep[u] - dep[v] ;
    for(int i= M-1 ; i>=0 ; i--)
    {
        if( (diff>>i) & 1 )
        {
            u = Par[u][i] ;
        }
    }
    // Now , both u and v have same depth
    if(u == v)    return u ;
    for(int i = M-1 ; i>=0 ; i--)
    {
        if(Par[u][i] != Par[v][i])
        {
            u = Par[u][i] ;
            v = Par[v][i] ;
        }
    }

    return Par[u][0] ;

}


int main() 
{
    int edges ;
    cin>>edges ;    // i have taken nodes = 100005 , so no need to store nodes
    while(edges--)
    {
        int x , y ;
        cin >>x>>y ;
        gr[x].push_back(y) ;
        gr[y].push_back(x) ;
    }
    dfs(1,0) ;
    calc_sparse_table(1,0) ;
    
    // test some query , and find ancestors of 2 pairs 
	/*
    cout<<"Lowest common ancestor = "<<LCA_using_depth(9,15)<<"\n" ;
    cout<<"Lowest common ancestor = "<<LCA_using_depth(18,15)<<"\n" ;
    cout<<"Lowest common ancestor = "<<LCA_using_depth(11,16)<<"\n" ;
    */

}
