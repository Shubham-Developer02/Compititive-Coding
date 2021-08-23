#include <bits/stdc++.h>
using namespace std;

void permute(char *in , int i , set<string> &s)
{
    if(in[i] == '\0')
    {
        // cout << in << "\n" ;
        s.insert(string(in)) ;
        return ;
    }
    for(int j = i ; in[j] != '\0' ; j++)
    {
        swap(in[i],in[j]) ;
        permute(in,i+1,s) ;
        swap(in[i],in[j]) ;
    }
}

int main() {
    char input[] = "abca" ;
    set<string> s ;
    permute(input,0,s) ;
    for( auto x : s)
        cout << x << "\n" ;

}
