#include <iostream>
using namespace std;

void permute(char *in , int i)
{
    if(in[i] == '\0')
    {
        cout << in << "\n" ;
        return ;
    }
    for(int j = i ; in[j] != '\0' ; j++)
    {
        swap(in[i],in[j]) ;
        permute(in,i+1) ;
        swap(in[i],in[j]) ;
    }
}

int main() {
    char input[] = "abc" ;
    permute(input,0) ;

}
