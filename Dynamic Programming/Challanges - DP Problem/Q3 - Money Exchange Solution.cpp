#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define mod 1000000007

void solution()
{
    int value , n ;
    cin>>n ;
    vector<int> arr(n+1) ;
    for(int i=1;i<=n;i++)
        cin>>arr[i] ;
    cin>>value ;
    vector<int> dp( value + 1 , 0) ;
    dp[0] = 1 ;
	for(int i = 1 ; i <= n ;i++ )
    {
        for(int j = 1 ; j <= value ; j++)
        {
            if( j>= arr[i])
                dp[j] = ( dp[j] + dp[j-arr[i]] ) % mod ;
        }
    }

    cout<<dp[value]<<"\n" ;
    
}

int32_t main() 
{
    ios_base::sync_with_stdio(0) ;
    cin.tie(0) ;
    cout.tie(0) ;
    int t ;
    cin>>t;
    while(t--)
    {
        solution() ;
    }

}