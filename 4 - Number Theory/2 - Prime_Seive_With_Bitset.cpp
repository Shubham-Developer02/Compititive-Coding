#include<bitset>
#include <bits/stdc++.h>

using namespace std;
 
const int n=10000000;
bitset<10000005> b;
vector<int> primes; 

void SieveOfEratosthenes()
{
    b.set();
    b[0]=b[1]=0;
    for (long long int i = 2; i <= n; i++)
    {
        if (b[i]) 
        {
            primes.push_back(i);
            for (long long int j = i * i; j <= n; j += i)
                b[j] = 0;
        }
    }
}
 

int main()
{
    //int n = 30;
    SieveOfEratosthenes();
    for(int i=0;i<primes.size();i++)
        cout<<primes[i]<<endl;
    return 0;
}
