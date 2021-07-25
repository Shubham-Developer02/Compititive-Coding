#include <bits/stdc++.h>
using namespace std;

#define ll long long 

ll k ;
vector<ll> a,b,c;

vector<vector<ll>> multiply(vector<vector<ll>> A , vector<vector<ll>> B)
{
    vector<vector<ll>> C(k+1,vector<ll> (k+1)); 
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=k;j++)
        {
            for(int x=1;x<=k;x++)
            {
                C[i][j] = C[i][j] + A[i][x] * B[x][j] ;     // You can do mod if asked in question 

            }
        }
    }
    return C;
}


vector<vector<ll>> pow(vector<vector<ll>> A , ll p)
{
    if(p==1)    
        return A ;
    if(p&1)
        return multiply(A,pow(A,p-1));

    vector<vector<ll>> X = pow(A,p/2);
    return multiply(X,X);
}


ll compute(ll n)
{
    if(n==0)    return 0;
    if(n<=k)    return b[n-1];

    vector<ll> F1(k+1) ;    // indexing from 1
    for(int i=1;i<=k;i++)
        F1[i]=b[i-1];

    vector<vector<ll>> T(k+1,vector<ll> (k+1));     // Transformation matrix

    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=k;j++)
        {
            if(i<k)
            {
                if(j==i+1)
                    T[i][j]=1;
                else    
                    T[i][j]=0;
            }
            else
            {
                T[i][j] = c[k-j];
            }
        }
    }    

    // Calculate power of a matrix

    T = pow(T,n-1);

    ll res =0;
    for(int i=1;i<=k;i++)
    {
        res = res + T[1][i] * F1[i] ;      //  Do mode here also if asked in question 
    } 
    return res ;
}


int main()
{
    ll t,n,num ;
    cin>>t ;        // t is no of test cases
    while(t--)
    {
        cin>>k;     // k is no factor nth term depend upon ..for eg fibonacci Fn = Fn-1 +Fn-2 hence k is 2 
                    // if , Fn = Fn-1 +Fn-3 than k = 3 bcoz Fn = Fn-1 + 0*Fn-2 + Fn-3
        
        for(int i=0;i<k;i++)    // This loop is for init vector , inital value upto kth terms
        {
            cin>>num;
            b.push_back(num);
        } 

        for(int i=0;i<k;i++)    // This loop is for coefficient vector
        {
            cin>>num;
            c.push_back(num);
        } 
        cin >> n ;  // value of n 
        cout << compute(n)<<endl ;
        b.clear();
        c.clear();
    }
    return 0;
}