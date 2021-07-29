#include <bits/stdc++.h>
using namespace std;

int fastpower(int a,int n)
{
    int ans = 1 ;
    while(n > 0)
    {
        int last_bit = n&1 ;
        if(last_bit)
        {
            ans = ans*a ;
        }
        a = a*a ;
        n = n >> 1 ;
    }
    return ans ;
}

int main() {
    cout<<fastpower(5,4);
}
