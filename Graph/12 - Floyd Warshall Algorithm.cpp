#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> Floyd_Warshall(vector<vector<int>> graph , int V)
{
    vector<vector<int>> dist(graph) ;
    //In kth phase , we include (1,2,....,k) as intermediate vetices
    for(int k=0;k<V;k++)
    {
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if ( dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && 
                dist[i][k] + dist[k][j] < dist[i][j]    )
                        dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    return dist ;
}

int main() 
{
    int n,m;
    cin>>n>>m ;
    vector<vector<int>> graph(n,vector<int> (n,INT_MAX)) ;
    for(int i=0;i<m;i++)
    {
        int u,v,wt;
        cin>>u>>v>>wt;
        graph[u][v] = wt ; 
    }
    for(int i=0;i<n;i++)
        graph[i][i] = 0 ;
    
    vector<vector<int>> dist = Floyd_Warshall(graph,n) ;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            if (dist[i][j] == INT_MAX)
                cout << "INFINITE"<< "     ";
            else
                cout << dist[i][j]<< "     ";
        }
        cout << endl;
    }

    return 0 ;
}
