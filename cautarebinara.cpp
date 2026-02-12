#include <iostream>

using namespace std;

const int MAX = 1000005;

int a[MAX];

int cautare_binara(int n, int x)
{
    int st = 1;
    int dr = n;

    while (st <= dr)
    {
        int mij = (st + dr) / 2;

        if (a[mij] == x)
        {
            return mij;
        }
        else if (a[mij] < x)
        {
            st = mij + 1;
        }
        else
        {
            dr = mij - 1;
        }
    }

    return -1;
}

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    int x;
    cin >> x;

    cout << cautare_binara(n, x);

    return 0;
}
