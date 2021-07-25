#include <bits/stdc++.h>
using namespace std;
#define int long long

//-----------------------Optimal game Strategy-------------------------------

int Optimal_game_dp(int i,int j,vector<int> &arr,vector<vector<int>> &dp)
{
    if(i>j)
        return 0 ;
    if(dp[i][j] != -1)
        return dp[i][j] ;
    
    int option1 = arr[i] + min( Optimal_game_dp(i+2,j,arr,dp) , Optimal_game_dp(i+1,j-1,arr,dp)  ) ;
    int option2 = arr[j] + min( Optimal_game_dp(i+1,j-1,arr,dp) , Optimal_game_dp(i,j-2,arr,dp)  ) ;
    dp[i][j] = max(option1 , option2) ;
    return dp[i][j] ;
}

int32_t main() 
{
    int n ;
    cin>> n ;   // n should be even
    vector<int> arr(n) ; 
    int total_points = 0 ;
    for(int i=0;i<n;i++)
    {
        cin >> arr[i] ;
        total_points += arr[i] ;
    }    
    vector<vector<int>> dp( n , vector<int> ( n , -1 ) ) ;
    int player1_points =  Optimal_game_dp(0,n-1,arr,dp) ;
    //cout <<"Player 1 have "<<player1_points<<" points"<<"\n" ;
    //cout <<"Player 2 have "<<total_points - player1_points<<" points"<<"\n" ;
    cout<< 2*player1_points - total_points ;

}