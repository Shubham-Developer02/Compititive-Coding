#include <bits/stdc++.h>
using namespace std;

//  It helps in solving equations like :---->
//      Ax + By = GCD(A,B)


int x,y,GCD;
void extended_Euclid(int a,int b)
{
    if(b==0)
    {
        x=1;
        y=0;
        GCD=a;
        return ;
    }
    extended_Euclid(b,a%b);
    int cX = y;
    int cY = x - (a/b)*y ;
    x = cX;
    y = cY;
}

int main()
{
    extended_Euclid(30,18);
    cout<<"Value of x = "<<x<<"Value of y = "<<y;  
    return 0;
}
