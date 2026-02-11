#include<bits/stdc++.h>
using namespace std;
ifstream fin("ciur_desc.in");
ofstream fout("ciur_desc.out");

const int NMAX = 10005;
bitset<NMAX> ciur;
vector<int> prime;

void sieve()
{
    int i, j;
    ciur.set();
    ciur[0] = ciur[1] = 0;
    
    for(i = 4; i < NMAX; i += 2)
        ciur[i] = 0;
    
    for(i = 3; i*i < NMAX; i += 2)
    {
        if(ciur[i] == 1)
        {
            for(j = i*i; j < NMAX; j += i)
                ciur[i] = 0;
        }
    }
    
    prime.push_back(2);
    for(i = 3; i < NMAX; i += 2)
    {
        if(ciur[i] == 1)
            prime.push_back(i);
    }
}
long long desc(long long n)
{
    int d = 0, ans = 1, exp = 0;
    while(d < (int)prime.size() && prime[d] * prime[d] <= n)
    {
        while(n % prime[d] == 0)
        {
            n /= prime[d];
            exp++;
        }
        if(exp > 0)
            ans *= (exp+1);
        d++;
        exp= 0;
    }
    if(n > 1)
        ans *= 2;
        
    return ans;
}

int main()
{
    sieve();
    int n;
    
    fin>> n;
    fout<< desc(n);
    
    fin.close();
    fout.close();
    return 0;
}
