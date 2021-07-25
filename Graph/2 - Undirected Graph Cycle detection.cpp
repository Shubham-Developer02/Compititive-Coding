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
       /* void bfs(int src)
        {
            map<int,int> visited ;
            queue<int> q ;
            q.push(src) ;
            visited[src] = true ;
            while(!q.empty())
            {
                int node = q.front() ;
                cout<<node<<"\n" ;
                q.pop() ;
                for( int nbr : l[node] )
                {
                    if(!visited[nbr])
                    {
                        q.push(nbr) ;
                        visited[nbr] = true ;
                    }
                }
            }
        }*/
        bool cycle_helper(int node , bool *visited , int parent )
        {
            visited[node] = true ;
            for(auto nbr : l[node] )
            {
                if(!visited[nbr])
                {
                    bool ifCycle = cycle_helper(nbr,visited,node) ;
                    if(ifCycle)
                        return true ;
                }
                else if(nbr != parent)
                {
                    return true ;
                }
            }
            return false ;
        }


        bool contains_cycle()
        {
            bool *visited = new bool[V] ;
            for(int i=0;i<V;i++)
            {
                visited[i] = false ;
            }
            return cycle_helper(0,visited,-1) ;
        }
};

int main() 
{
    Graph g(5);
    g.addEdge(0,1) ;
    g.addEdge(1,2) ;
    g.addEdge(2,3) ;
    g.addEdge(3,4) ;
    g.addEdge(4,0) ;
  
    //g.bfs(0) ;
    if(g.contains_cycle())
        cout<<"Cycle present" ;
    else    
        cout<<"No cycle" ;
    return 0 ;
}
