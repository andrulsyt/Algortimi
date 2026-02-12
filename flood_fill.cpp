#include <iostream>

using namespace std;

const int MAX = 1005;

int n, m;
int a[MAX][MAX];
int viz[MAX][MAX];

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void flood_fill(int x, int y, int val)
{
    viz[x][y] = 1;

    for (int k = 0; k < 4; k++)
    {
        int nx = x + dx[k];
        int ny = y + dy[k];

        if (nx >= 1 && nx <= n && ny >= 1 && ny <= m)
        {
            if (!viz[nx][ny] && a[nx][ny] == val)
            {
                flood_fill(nx, ny, val);
            }
        }
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }

    int x, y;
    cin >> x >> y;

    flood_fill(x, y, a[x][y]);

    return 0;
}
