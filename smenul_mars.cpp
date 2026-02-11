#include<bits/stdc++.h>
using namespace std;
ifstream fin("smen.in");
ofstream fout("smen.out");

const int NMAX = 1001;
int v[NMAX], mars[NMAX+5];

int main()
{
    int n, m, s, d, X, i;
    fin>> n>> m;
    
    for(i = 1; i <= n; i++)
        fin>> v[i];
    
    for(i = 1; i <= m; i++)
    {
        fin>> s>> d>> X;
        mars[s] += x;
        mars[d+1] -= x;
    }
    
    for(i = 1; i <= n; i++)
    {
        mars[i] += mars[i-1];
        v[i] += mars[i];
    }
    
    for(i = 1; i <= n; i++)
        fout<< v[i]<<" ";
    
    fin.close();
    fout.close();
    return 0;
}
