#include <bits/stdc++.h>
// Header Files
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds ;


typedef tree<pair<int,int>,null_type,less<pair<int,int>> , rb_tree_tag ,
                            tree_order_statistics_node_update > PBDS ;

// To insert same value multiple time stored them as pair with index
int main() 
{
    PBDS st ;
    st.insert({1,0}) ;
    st.insert({15,1}) ;
    st.insert({3,2}) ;
    st.insert({4,3}) ;
    st.insert({10,4}) ;
    
    // kth largest element at till now O(logn)
    for(int i = 0 ; i <st.size() ; i++)
    {
        cout << i << " " << st.find_by_order(i)->first << " " << st.find_by_order(i)->second << "\n" ;
    }

    
    cout << st.order_of_key({15,0}) << "\n" ;
    cout << st.order_of_key({15,3}) << "\n" ;
    /*cout << st.order_of_key(15) << "\n" ;
    cout << st.order_of_key(9) << "\n" ;
    */
}
