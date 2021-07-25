#include <bits/stdc++.h>
using namespace std;
#define int long long

int BIT[100000] = {0} ;

void update(int i , int value , int n)
{
    while( i<=n )
    {
        BIT[i] = max( BIT[i] , value ) ;
        i+= ( i&(-i) ) ;
    }
}

int query(int i)
{
    int ans = INT_MIN ;
    while(i > 0)
    {
        ans = max( ans , BIT[i] ) ;
        i-= ( i&(-i) ) ;
    }
    return ans ;
}


void solve()
{
    int n ;
    cin >> n ;
    int a[n+1]  ;
    for(int i = 1 ; i <= n ; i++)
        cin >> a[i] ;
    // build BIT
    for(int i = 1 ; i <= n ; i++)
        update(i,a[i],n) ;
    
    int q ;
    cin >> q ;
    while(q--)
    {
        int index ;
        cin >> index ;
        // you can do update also...........
        cout<<query(index)<<"\n" ;
    }
    
}

int32_t main() 
{
    int t = 1 ;
    while(t--)
        solve() ;
}
