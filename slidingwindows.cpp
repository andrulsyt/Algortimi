#include<bits/stdc++.h>
using namespace std;

const int MAX = 1000005;

int a[MAX];
int rezultat[MAX];
deque<int> dq;

void sliding_window(int n, int k)
{
    for (int i = 1; i <= n; i++)
    {
        while (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        while (!dq.empty() && a[dq.back()] >= a[i])
            dq.pop_back();

        dq.push_back(i);

        if (i >= k)
            rezultat[i - k + 1] = a[dq.front()];
    }
}

int main()
{
    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    sliding_window(n, k);

    for (int i = 1; i <= n - k + 1; i++)
    {
        cout << rezultat[i] << " ";
    }

    return 0;
}
