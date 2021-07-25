#include <bits/stdc++.h>
using namespace std;

void euler_tour_1(int cur,int par,vector<int> gr[])
{
    cout<<cur<<" - " ;
    for(auto x : gr[cur])
    {
        if(x != par)
        {
            euler_tour_1(x,cur,gr) ;
            cout<<cur<<" - " ;
        }
    }
    return ;
}

void euler_tour_2(int cur,int par,vector<int> gr[])
{
    cout<<cur<<" - " ;
    for(auto x : gr[cur])
    {
        if(x != par)
        {
            euler_tour_2(x,cur,gr) ;
        }
    }
    cout<<cur<<" - " ;
    return ;
}

void euler_tour_3(int cur,int par,vector<int> gr[])
{
    cout<<cur<<" - " ;
    for(auto x : gr[cur])
    {
        if(x != par)
        {
            euler_tour_3(x,cur,gr) ;
        }
    }
    return ;
}

int main() 
{
    int v,e ;
    cin>>v>>e;
    vector<int> gr[v+1] ;   // initialize nodes from 1
    while(e--)
    {
        int x,y ;
        cin>>x>>y ;
        gr[x].push_back(y) ;
        gr[y].push_back(x) ;
    }
    cout<<"Euler Tour 1 -> "<<"\n"; 
    euler_tour_1(1,0,gr) ;
    cout<<"\n"<<"Euler Tour 2 -> "<<"\n";
    euler_tour_2(1,0,gr) ;
    cout<<"\n"<<"Euler Tour 3 -> "<<"\n";
    euler_tour_3(1,0,gr) ;
    
    
    return 0 ;
}
