#include <iostream>

using namespace std;

const int MAX = 1005;

int a[MAX][MAX];
int sp[MAX][MAX];

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            sp[i][j] = a[i][j]
                       + sp[i - 1][j]
                       + sp[i][j - 1]
                       - sp[i - 1][j - 1];
        }
    }

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int suma = sp[x2][y2]
               - sp[x1 - 1][y2]
               - sp[x2][y1 - 1]
               + sp[x1 - 1][y1 - 1];

    cout << suma;

    return 0;
}
