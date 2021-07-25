#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define mod 1000000007


int32_t main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n , k ;
    cin>>n>>k ;
    vector<int> arr(n) ;
    for(int i=0;i<n;i++)
        cin>>arr[i] ;
    int start = 0 , final_start = 0 , flip_count = 0 , max_length = 0 ;
    for(int i=0;i<n;i++)
    {
        if(arr[i] == 0)
        {
            flip_count++ ;

        }
        while(flip_count > k)
        {
            if(arr[start] == 0)
                flip_count-- ;
            start++ ;
        }
        if(max_length < i - start + 1)
        {
            max_length = i - start + 1 ;
            final_start = start ;
        }
    }
    for(int i=final_start ; i<final_start+max_length;i++)
        arr[i] = 1 ;
    cout<<max_length<<"\n" ;
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" " ;
}