// To calculate G.C.D. and L.C.M.

#include <bits/stdc++.h>

using namespace std;
 
 int calculate_GCD(int a,int b)
 {
     if(b==0)
        return a;
     return calculate_GCD(b,a%b) ;
 }

int main()
{
    int a,b;
    cin>>a>>b;
    int gcd = calculate_GCD(a,b);
    int lcm = (a*b)/gcd ;
    cout<<"GCD ="<<gcd<<"LCM="<<lcm ;
    return 0;
}
