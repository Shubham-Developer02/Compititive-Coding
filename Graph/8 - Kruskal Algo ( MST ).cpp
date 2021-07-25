#include<bits/stdc++.h>
using namespace std;

class DSU{
    int *parent ;
    int *rank ;

    public :
        DSU(int n)
        {
            parent = new int[n] ;
            rank = new int[n] ;
            for(int i=0;i<n;i++)
            {
                parent[i] = -1 ;
                rank[i] = 1 ;
            }
        }

        int findSet(int i)
        {
            if(parent[i] == -1)
            {
                return i;
            }
        // path compression optimization
            return parent[i] = findSet(parent[i]);
        }

        void union_Set(int u,int v)
        {
            int s1 = findSet(u);
            int s2 = findSet(v);
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
};

class Graph
{
    vector<vector<int>> edgeList ;
    int V ;
    public :
        Graph(int V)
        {
            this->V = V ;
        }
        void addEdge(int x,int y,int w)
        {
            edgeList.push_back({w,x,y}) ;   // w is weight , and we have to sort according to weight 
        }
        int kruskal_mst()
        {
            sort( edgeList.begin() , edgeList.end() ) ;
            DSU s(V) ; //initialize DSU
            int ans = 0 ;
            for(auto edge : edgeList)
            {
                int w = edge[0] ;
                int x = edge[1] ;
                int y = edge[2] ;
                if(s.findSet(x) != s.findSet(y))
                {
                    s.union_Set(x,y) ;
                    ans += w ;
                }
            }
            return ans ; //total weight of spanning tree
        }

};


int main()
{
    int n,e;
    cin>>n>>e ;
    Graph g(n+1) ;
    while(e--)
    {
        int x,y,w ;
        cin>>x>>y>>w ;
        g.addEdge(x,y,w) ;
    }
    cout<<g.kruskal_mst() ;
    /*
    Graph g(4);
    g.addEdge(0,1,1);
    g.addEdge(1,2,2);
    g.addEdge(3,2,4);
    g.addEdge(1,3,3);
    g.addEdge(2,0,2);
    g.addEdge(0,3,2);
    cout<<g.kruskal_mst() ;
    */
    return 0;
}