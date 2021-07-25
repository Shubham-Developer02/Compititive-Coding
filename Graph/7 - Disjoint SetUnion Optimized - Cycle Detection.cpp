#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    map<int,list<int>> l;
    public:
    Graph(int V)
    {
        this->V = V;
    }
    
    void addEdge(int v,int w)
    {
        l[v].push_back(w);
    }
    
    int findSet(int i, int parent[])
    {
        if(parent[i] == -1)
        {
            return i;
        }
        // path compression optimization
        return parent[i] = findSet(parent[i],parent);
    }
    
    void union_Set(int u,int v,int parent[],int rank[])
    {
        int s1 = findSet(u,parent);
        int s2 = findSet(v,parent);
        //int s1 = u;
        //int s2 = v;
        if(s1 != s2)
        {
            if(rank[s1] < rank[s2])
            {
                parent[s1] = s2;
                rank[s2] += rank[s1] ;
            }
            else
            {
                parent[s2] = s1;
                rank[s1] += rank[s2] ;
            }
        }
    }
    
    bool contains_Cycle()
    {
        int *parent = new int[V];
        int *rank = new int[V] ;
        for(int i=0;i<V;i++)
        {
            parent[i] = -1;
            rank[i] = 1 ;
        }
        for(int i=0;i<V;i++)
        {
            for(auto nbr : l[i])
            {
                int s1 = findSet(i,parent);
                int s2 = findSet(nbr,parent);
                if(s1 != s2)
                {
                    union_Set(s1,s2,parent,rank);
                }
                else
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0);
    if( g.contains_Cycle()  ) 
        cout<<"Contains Cycle"<<"\n" ;
    return 0;
}