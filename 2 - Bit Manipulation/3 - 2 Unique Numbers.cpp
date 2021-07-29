#include <bits/stdc++.h>
using namespace std;



int main() 
{
    int n ;
    cin >> n ;
    vector<int> arr(n) ;
    int xor_value = 0 ;
    for(int i = 0 ; i<n ; i++)
    {
        cin >> arr[i] ;
        xor_value^= arr[i] ;
    }
    int temp = xor_value ;
    int pos = 0 ;
    while((temp&1) != 1)
    {
        pos ++ ;
        temp = temp >> 1 ;
    }
    int mask = 1<<pos ;
    int a = 0 ;
    for(int i = 0 ; i<n ; i++)
    {
        if( (arr[i]&mask) > 0)
        {
            a = a^arr[i] ;
        }
            
    }
    int b = a^xor_value ;
    cout << min(a,b) <<" "<< max(a,b) ;
}
