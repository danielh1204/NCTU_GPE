#include <iostream>
#include <cmath>

using namespace std;

bool isprime(int n)
{
    for(int i = 2; i <= sqrt(n); i++)
        if(n%i == 0) return 0;
    return 1;
}

long long mod(long long a, long long power, long long md)
{
    if(power == 0) return 1;
    if(power == 1) return a%md;

    long long val = mod(a, power/2, md);
    if(power%2 == 0)
        return (val*val)%md;
    if(power%2 == 1)
        return (((val*val)%md)*a)%md;
}

bool fermattest(int n)
{
    for(int i = 2; i < n; i++)
    {
        long long a = mod(i, n, n);

        if(a != i) return false;
    }
    return true;
}

int main(){

    while(1)
    {
        int n;
        cin >> n;
        if(!n) break;
        if(!isprime(n) && fermattest(n))
            printf("The number %d is a Carmichael number.\n", n);
        else
            cout << n << " is normal.\n";
    }

    return 0;
}
