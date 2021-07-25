#include <bits/stdc++.h>
using namespace std;

class Graph
{
    map<int,list<int> >  l ;
    int V ;
    public :
        Graph(int V)
        {
            this->V = V ;
        }
        void addEdge(int x,int y)
        {
            l[x].push_back(y);
            l[y].push_back(x);
        }
        bool dfs_helper(int node,int *visited,int parent,int color)
        {
            visited[node] = color ;
            for(auto nbr : l[node])
            {
                if(visited[nbr]==0)
                {
                    bool ifBipartite = dfs_helper(nbr,visited,node,3-color) ;
                    if(!ifBipartite)
                        return false ;
                }
                else if(nbr != parent && color == visited[nbr])
                {
                    return false ;
                }
            }
            return true ;
        }

        bool dfs()
        {
            int visited[V] = {0} ; // 0 - not visited, 1- visited color 1 , 2- visitedcolor 2
            int color = 1 ;
            bool isBipartite =  dfs_helper(0,visited,-1,color) ;


            // To check which node have which color , you can comment it if you want
            for(int i=0;i<V;i++)
            {
                cout<<i<<"th node have color --"<<visited[i]<<"\n" ;
            }

            return isBipartite ;
        }
       
};

int main() 
{
    int n,m;    //n- no of vertices , m-no of edges 
    cin>>n>>m;
    Graph g(n);
    for(int i=0;i<m;i++)
    {
        int x,y ;
        cin>>x>>y;
        g.addEdge(x,y);
    }
    if(g.dfs())
        cout<<"Yes bipartite graph" ;
    else
        cout<<"Not a bipartite graph" ;
    
    return 0 ;
}
