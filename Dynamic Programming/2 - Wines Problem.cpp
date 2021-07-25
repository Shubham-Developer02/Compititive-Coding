#include <bits/stdc++.h>
using namespace std;

//i is start index and j is end endex
int profit(vector<int> &wines,int i,int j,int year,vector<vector<int>> &dp)
{   
    if(i > j)
        return 0 ;
    
    if(dp[i][j] != -1)
        return dp[i][j] ;

    int option1 = wines[i]*year + profit(wines,i+1,j,year+1,dp) ;
    int option2 = wines[j]*year + profit(wines,i,j-1,year+1,dp) ;
    dp[i][j] = max(option1,option2) ; 
    return dp[i][j] ;
}

int main() 
{
    int n ;
    //cout<<"Enter the number of wines" ;
    cin>>n ;
    vector<int> wines(n) ;
    for(int i=0;i<n;i++)
        cin>>wines[i] ; // store price of wines 

    vector<vector<int> > dp(n,vector<int> (n,-1)) ;
    cout<<profit(wines,0,n-1,1,dp) ;

}
