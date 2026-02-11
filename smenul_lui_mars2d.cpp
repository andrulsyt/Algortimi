#include<bits/stdc++.h>
using namespace std;
ifstream fin("smen2d.in");
ofstream fout("smen2d.out");

const int NMAX = 505;
int mat[NMAX][NMAX], mars[NMAX+5][NMAX+5];

int main()
{
    int n, q, i, j;
    
    fin>> n;
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
            fin>> mat[i][j];
    }
    
    int x1, y1, x2, y2;
    fin>> q;
    
    for(i = 1; i <= q; i++)
    {
        fin>> x1>> y1>> x2>> y2>> v;
        mat[x1][y1] += v;
        mat[x2+1][y1] -= v;
        mat[x1][y2+1] -= v;
        mat[x2+1][y2+1] += v;
    }
    
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
            mars[i][j] = mars[i][j-1] + mars[i-1][j] + mars[i][j] - mars[i-1][j-1];
    }
    
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
            mat[i][j] += mars[i][j];
    }
    
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
            fout<< mat[i][j]<<" ";
        fout<<'\n';
    }
    
    fin.close();
    fout.close();
    return 0;
}
