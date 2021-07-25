#include <bits/stdc++.h>
using namespace std;
#define int long long

void activity_Selection()
{
    int n ;
    cin >> n ;
    vector<pair<int,int>> arr(n) ;
    for( int i = 0 ; i < n ; i++ )
    {
        int start , end ;
        cin >> start >> end ;
        arr[i] = {end,start} ;
    }
    sort(arr.begin(),arr.end()) ;
    int count =  1 ;
    int finish = arr[0].first ;
    for(int i = 1 ; i < n ; i++)
    {
        if(arr[i].second >= finish)
        {
            count++ ;
            finish = arr[i].first ;
        }
    }
    cout<<count<<"\n" ;
}

int32_t main() 
{
    int t ;
    cin >> t ; 
    while(t--)
        activity_Selection() ;

}
