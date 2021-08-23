#include <iostream>
using namespace std;

char keypad[][5] = {"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"} ;

void generate_names(char *in,char *out,int i,int j )
{
    if(in[i] == '\0')
    {
        out[j] = '\0' ;
        cout << out << "\n" ;
	return ;
    }
    int digit = in[i] - '0' ;
    for(int k = 0 ; keypad[digit][k] != '\0' ; k++)
    {
        out[j] = keypad[digit][k] ;
        generate_names(in,out,i+1,j+1) ;
    }
}


int main() {
    char output[10] ;
    char input[] = "234" ;
    generate_names(input,output,0,0) ;

}
