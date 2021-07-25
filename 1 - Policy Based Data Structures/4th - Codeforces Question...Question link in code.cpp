
// ----------------------------Question link--------------------------------------
//          https://codeforces.com/problemset/problem/1324/D 

#include <bits/stdc++.h>
// Header Files
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds ;


typedef tree<pair<int,int>,null_type,less<pair<int,int>> , rb_tree_tag ,
                            tree_order_statistics_node_update > PBDS ;


int main() 
{
    int n ;
    cin >> n ;
    int a[n] , b[n] ;
    for(int i = 0 ; i < n ;i++)
        cin >> a[i] ;
    for(int i = 0 ; i < n ;i++)
        cin >> b[i] ;
    for(int i = 0 ; i < n ;i++)
        a[i] =  a[i] - b[i] ;
    
    PBDS st ;
    
    long long ans = 0 ;
    for(int i = 0 ; i < n ;i++)
    {
        ans += st.size() - ( st.order_of_key( {-a[i] , INT_MAX } ) ) ;
        st.insert( { a[i], i}) ;
    }
    cout << ans ;


}
