#include <bits/stdc++.h>
using namespace std;
#define int long long

void LCS_problem(string s ,string t)
{
    int m = s.length() , n = t.length() ;
    vector<vector<int>> value(m + 1 , vector<int> (n +1 ) ) ;
    vector<vector<int>> direction(m + 1 , vector<int> (n +1 ) ) ;

    for(int i=0;i<=m;i++)
    {
        value[i][0] = 0 ;
        direction[i][0] = 1 ;
    }
    for(int i=0;i<=n;i++)
    {
        value[0][i] = 0 ;
        direction[0][i] = 0 ;
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s[i-1] == t[j-1] )
            {
                value[i][j] = value[i-1][j-1] + 1 ;
                direction[i][j] = 2 ;
            }
            else if( value[i][j-1] >= value[i-1][j])
            {
                direction[i][j] = 0 ;
                value[i][j] = value[i][j-1] ;
            }
            else
            {
                direction[i][j] = 1 ;
                value[i][j] = value[i-1][j] ;
            }
        }
    }

    string result = "" ;
    int i=m,j=n ;
    while(i!=0 && j!=0)
    {
        if(direction[i][j]==2)
        {
            result = s[i-1] + result ;
            i-- ;
            j-- ;
        }
        else if (direction[i][j] == 1)
        {
            i-- ;
        }
        else
            j-- ;
    }

    cout<<result ;
}


int32_t main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s , t ;
    cin>>s>>t ;

    LCS_problem(s,t) ;

}