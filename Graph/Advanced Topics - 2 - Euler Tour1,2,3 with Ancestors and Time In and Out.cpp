#include <bits/stdc++.h>
using namespace std;

//for this algo i dont have , time in time out , so better use 2nd method
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

// This tour is best ....always use this
void euler_tour_2(int cur,int par,vector<int> gr[], vector<int> &timeIn, vector<int> &timeOut,int &timer)
{
    cout<<cur<<" - " ;
    timeIn[cur] = timer++;
    for(auto x : gr[cur])
    {
        if(x != par)
        {
            euler_tour_2(x,cur,gr,timeIn,timeOut,timer) ;
        }
    }
    cout<<cur<<" - " ;
    timeOut[cur] = timer++;
    return ;
}

void euler_tour_3(int cur,int par,vector<int> gr[], vector<int> &timeIn, vector<int> &timeOut,int &timer)
{
    cout<<cur<<" - " ;
    timeIn[cur] = ++timer ;
    for(auto x : gr[cur])
    {
        if(x != par)
        {
            euler_tour_3(x,cur,gr,timeIn,timeOut,timer) ;
        }
    }
    timeOut[cur] = timer ;
    return ;
}

//To find if a node is ancestors of another
bool is_ancestor(int x,int y, vector<int> &timeIn, vector<int> &timeOut)
{
    return timeIn[x]<=timeIn[y] && timeOut[x]>=timeOut[y] ;
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
    int timer = 1;
    vector<int> timeIn(v+1),timeOut(v+1) ;
   /* cout<<"Euler Tour 1 -> "<<"\n"; 
    euler_tour_1(1,0,gr) ;
    cout<<"\n"<<"Euler Tour 2 -> "<<"\n";
    euler_tour_2(1,0,gr) ;
    cout<<"\n"<<"Euler Tour 3 -> "<<"\n";
    euler_tour_3(1,0,gr) ;
    */
   
    

    /*euler_tour_2(1,0,gr,timeIn,timeOut,timer) ;
    cout<<"\n" ;
    for(int i=1;i<=v;i++)
    {
        cout<<i<<"-->"<<timeIn[i]<<" "<<timeOut[i]<<"\n";
    }
    */
    timer = 0;
    euler_tour_3(1,0,gr,timeIn,timeOut,timer) ;
    cout<<"\n" ;
    for(int i=1;i<=v;i++)
    {
        cout<<i<<"-->"<<timeIn[i]<<" "<<timeOut[i]<<"\n";
    }
    cout<<"--------------------"<<"\n" ;
    if(is_ancestor(1,7,timeIn,timeOut))
        cout<<"Yes" ;
    else
        cout<<"No " ;
    return 0 ;
}
