#include <bits/stdc++.h>
using namespace std;
#define int long long


int32_t main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n , k ;
    cin>>n>>k ;
    vector<int> arr(n+1) ;
    for(int i=1;i<=n;i++)
        cin>>arr[i] ;
     //sort(arr.begin()+1,arr.end()) ;
    if( k < arr[1] )
    {
        cout<<"Second" ;
        return 0 ;
    }
    vector<int> dp(k+1,0) ;
    for(int i=0 ; i <= k ; i++)
    {
        for(int j=1 ; j <= n ; j++)
        {
            if( i >= arr[j] && dp[i - arr[j] ]== 0)
                dp[i] = 1 ;
        }
    }
    //cout<<dp[k]<<"\n" ;
    if(dp[k] == 1)
        cout<<"First" ;
    else
        cout<<"Second" ;
    
}   