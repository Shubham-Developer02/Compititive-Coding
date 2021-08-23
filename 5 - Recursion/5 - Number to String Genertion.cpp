#include <iostream>
using namespace std;


void generate_strings(char *in,char *out,int i,int j )
{
    if(in[i] == '\0')
    {
        out[j] = '\0' ;
        cout << out << "\n" ;
        return ;
    }

    int digit = in[i] - '0' ;
    char ch = digit + 'A' - 1 ;
    out[j] = ch ;
    generate_strings(in,out,i+1,j+1) ;

    if(in[i+1] != '\0')
    {
        int second = in[i+1] - '0' ;
        int no = digit*10 + second ;
        if(no <= 26)
        {
            ch = no +'A' -1 ;
            out[j] = ch ;
            generate_strings(in,out,i+2,j+1) ;
        }
    }
}


int main() {
    char output[10] ;
    char input[] = "234" ;
    generate_strings(input,output,0,0) ;

}
