#include <bits/stdc++.h>
using namespace std;
#define int long long

void load_Balancer()
{
    int n ;
    cin >> n ;
    vector<int> arr(n) , prefix(n) ;
    int ans = INT_MIN , prefix_sum = 0;
    for(int i =0 ;i<n;i++)
    {
        cin >> arr[i] ;
        prefix_sum += arr[i] ;
        prefix[i] = prefix_sum ;
    }
    if( prefix_sum % n != 0)
    {
        cout<<"-1"<<"\n" ;
        return ;
    }
    int bal_load = prefix_sum / n ;
    for(int i = 0 ; i < n-1 ; i++)
    {
        int temp = abs( prefix[i] - ( bal_load * (i+1) ) ) ;
        ans = max ( ans , temp ) ;
    }
    cout<<ans <<"\n" ;
}

int32_t main() 
{
    int t=1 ;
    // cin >> t ; 
    while(t--)
        load_Balancer() ;

}
