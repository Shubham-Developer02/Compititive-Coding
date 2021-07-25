#include <bits/stdc++.h>
using namespace std;

int lazy[10000] = {0} ;

void buildTree(int *a,int s,int e,int *tree,int index)
{
    if(s==e)
    {
        tree[index] = a[s] ;
        return ;
    }
    int mid = (s+e)/2 ;
    buildTree(a,s,mid,tree,2*index) ;
    buildTree(a,mid+1,e,tree,2*index +1 ) ;
    tree[index] = min(tree[2*index],tree[2*index +1 ]) ;
    return ;

}

void Lazy_update(int *tree,int ss,int se,int start_pos,int end_pos,int increament,int index)
{
    if(lazy[index] != 0)
    {
        tree[index] += lazy[index] ;
        //not leaf node
        if(ss != se)
        {
            lazy[2*index] += lazy[index] ;
            lazy[2*index+1] += lazy[index] ;
        }
        lazy[index] = 0 ;
    }
    //no overlap
    if(start_pos>se || end_pos<ss)
        return ;
    //complete overlap
    if(ss>=start_pos && se<=end_pos)
    {
        tree[index] += increament ;
        if(ss != se)
        {
            lazy[2*index] += increament ;
            lazy[2*index+1] += increament ;
        }
        return ;
    }
    //partial overlap 
    int mid = (ss + se) / 2 ;
    Lazy_update(tree,ss,mid,start_pos,end_pos,increament,2*index) ;
    Lazy_update(tree,mid+1,se,start_pos,end_pos,increament,2*index+1) ;
    tree[index] = min(tree[2*index] , tree[2*index+1]) ;
    return ; 
}


int Lazy_query(int *tree,int ss,int se,int query_start,int query_end,int index)
{
    if(lazy[index] != 0)
    {
        tree[index] += lazy[index] ;
        //not leaf node
        if(ss != se)
        {
            lazy[2*index] += lazy[index] ;
            lazy[2*index+1] += lazy[index] ;
        }
        lazy[index] = 0 ;
    }
    //no overlap
    if(ss>query_end || se<query_start)
        return INT_MAX ;
    //complete overlap
    if(ss>=query_start && se<=query_end)
    {
        return tree[index] ;
    }    
    //partial overlap
    int mid = (ss+se)/2 ;
    int left = Lazy_query(tree,ss,mid,query_start,query_end,2*index) ;
    int right = Lazy_query(tree,mid+1,se,query_start,query_end,2*index+1) ;
    return min(left,right) ;

}


int main() 
{
    int a[] = {1,3,2,-5,6,4};
    int n = 6 ;//size of array
    int *tree = new int[4*n +1 ] ;
    buildTree(a,0,n-1,tree,1);

    //Print the tree array
    for(int i=1;i<=13;i++)
        cout<<tree[i]<<" " ;
    cout<<"\n" ;

    Lazy_update(tree,0,n-1,0,2,10,1) ;
    Lazy_update(tree,0,n-1,0,4,10,1) ;
    cout<<"Query 1 = "<<Lazy_query(tree,0,n-1,1,1,1)<<"\n" ;
    Lazy_update(tree,0,n-1,3,4,10,1) ;
    cout<<"Query 2 = "<<Lazy_query(tree,0,n-1,3,5,1)<<"\n" ;

    return 0 ;

}
