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
        }

        void topological_sort(int source,bool *visited,list<int> &ordering)
        {
            visited[source] = true ;
            // go to all neighbours
            for(auto nbr : l[source])
            {
                if(!visited[nbr])
                {
                    topological_sort(nbr,visited,ordering) ;
                }
            } 
            // push node
            ordering.push_front(source) ;
            return ;
        }

        void dfs()  // for topological sort
        {
            list<int> ordering ;
            bool* visited = new bool[V];
            for (int i = 0; i < V; i++)
                visited[i] = false;
            
            for(int i=0;i<V;i++)
            {
                if(!visited[i])
                    topological_sort(i,visited,ordering) ;
            }
            cout<<"Topological order is :-"<<"\n" ;
            for(auto node : ordering)
                cout<<node<<"\n" ;

            return ;
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

    g.dfs() ;

    return 0 ;
}
