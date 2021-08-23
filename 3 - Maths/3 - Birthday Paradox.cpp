#include <iostream>
using namespace std;


// Birthday paradox :- Find the no of people such that probability of having same birthday 
                    // of atleast 2 person is 'p' ;


int main() {
    float x = 1.0 ;
    int people_required = 0 ;
    float num = 365 , denom = 365 ;
    float p ;
    cin >> p ;

    while(x > 1-p)
    {
        x = x*num/denom ;
        num-- ;
        people_required++ ;
    }
    cout<<people_required ;
}
