#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 100005;
int arr[N] ;

struct segmentTree_of_vectors
{
    vector<int> segmentTree[N*4 + 1] ;
    
    void build(int start , int end , int index)
    {
        if(start==end)
        {
            segmentTree[index].push_back( arr[start] ) ;
            return ;
        }
        int mid = (start + end) / 2 ;
        build(start,mid,2*index) ;
        build(mid+1,end,2*index + 1) ;

        merge( segmentTree[2*index].begin() , segmentTree[2*index].end() ,
                segmentTree[2*index+1].begin() , segmentTree[2*index+1].end() ,
                    back_inserter(segmentTree[index])  )  ;

    }

    int query(int start,int end , int l, int r , int k , int index)
    {
        //no overlap
        if(end < l || start > r)
            return 0 ;
        //complete overlap
        if( start >= l && end <= r )
            return segmentTree[index].size() - ( upper_bound( segmentTree[index].begin() , segmentTree[index].end() , k ) - segmentTree[index].begin() ) ;
        //partial overlap
        int mid = ( start + end ) / 2 ;
        int left = query( start , mid , l , r , k , 2*index ) ;
        int right = query( mid + 1 , end , l , r , k , 2*index+1 ) ;
        return left + right ;
    }

}tree;

int32_t main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n ;
    cin >> n ;
    for(int i = 0 ; i < n ;i++)
        cin>>arr[i] ;
    tree.build(0,n-1,1) ;
    int query , ans = 0 , l , r , k;
    cin>>query ;
    while(query--)
    {   
        cin >> l >> r >> k ;
        l = l ^ ans ;
        r = r ^ ans ;
        k = k ^ ans ;
        l-- ; r-- ;
        /*if( l > r )
            ans = 0 ;
        if( r > n-1 ) r = n-1 ;
        if( l <= r )*/
        ans = tree.query(0 , n-1 , l , r , k , 1 ) ;
        cout << ans << "\n" ;
    }
}
