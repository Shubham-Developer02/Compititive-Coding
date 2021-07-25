#include <bits/stdc++.h>
using namespace std;

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

// Point update ... i mean update at certain index  
void Point_update(int *tree,int ss,int se,int pos,int increament,int index)
{
    if(pos<ss || pos>se)
        return ;
    //leaf node , i.e. when you are at desired position
    if(ss == se)
    {
        tree[index] += increament ;
        return ;
    }    
     
    int mid = (ss + se)/2 ;
    Point_update(tree,ss,mid,pos,increament,2*index) ;
    Point_update(tree,mid+1,se,pos,increament,2*index+1) ;
    tree[index] = min( tree[2*index] , tree[2*index+1] ) ;
    return ;

}


int query(int *tree,int ss,int se,int qs,int qe,int index)
{
    //Complete overlap
    if(ss>=qs && se<=qe)
    {
        return tree[index] ;
    }
    //No Overlap
    if(qe<ss || qs >se)
    {
        return INT_MAX ;
    }
    //Partial Overlap
    int mid = (ss+se)/2 ;
    int left = query(tree,ss,mid,qs,qe,2*index) ;
    int right = query(tree,mid+1,se,qs,qe,2*index+1) ;
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

    Point_update(tree,0,n-1,3,10,1) ;

    cout<<"\n" ;
    int q ;
    cin>>q ;
    cout<<"\n" ;
    while(q--)
    {
        int l,r ;
        cin>>l>>r ;
        cout<<query(tree,0,n-1,l,r,1)<<"\n" ;
    }

    return 0 ;

}
