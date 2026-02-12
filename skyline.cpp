#include<bits/stdc++.h>
using namespace std;

ifstream fin("skyline.in");
ofstream fout("skyline.out");

const int NMAX = 40005;

int v[NMAX], stanga[NMAX], dreapta[NMAX];
long long sume[NMAX], maxarea = 0;
stack<int> st;

int main()
{
    int n, i, x;

    fin>> n;
    for(i = 1; i <= n; i++)
    {
        fin>> v[i]>> x;
        sume[i] = sume[i-1]+x;
    }

    st.push(n+1);

    for(i = n; i >= 1; i--)
    {
        while(!st.empty() && v[st.top()] >= v[i])
            st.pop();
        if(!st.empty())
            dreapta[i] = st.top();

        st.push(i);
    }

    st.push(0);

    for(i = 1; i <= n; i++)
    {
        while(!st.empty() && v[st.top()] >= v[i])
            st.pop();
        if(!st.empty())
            stanga[i] = st.top();

        st.push(i);
    }

    while(!st.empty()) st.pop();

    int latime, lungime;

    for(i = 1; i <= n; i++)
    {
        latime = sume[dreapta[i]-1] - sume[stanga[i]];
        lungime = v[i];
        maxarea = max(maxarea, 1LL*latime*lungime);
    }
    fout<< maxarea;


    fin.close();
    fout.close();
    return 0;
}
