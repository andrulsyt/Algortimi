#include<bits/stdc++.h>
using namespace std;

const int MAX = 1005;

int n, m;
int a[MAX][MAX];
int distanta[MAX][MAX];

queue<pair<int, int>> q;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void lee(int xs, int ys)
{
    q.push({ xs, ys });
    distanta[xs][ys] = 0;

    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();

        int x = p.first;
        int y = p.second;

        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m)
            {
                if (a[nx][ny] == 0 && distanta[nx][ny] == -1)
                {
                    distanta[nx][ny] = distanta[x][y] + 1;
                    q.push({ nx, ny });
                }
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
            distanta[i][j] = -1;
        }
    }

    int xs, ys;
    cin >> xs >> ys;

    lee(xs, ys);

    return 0;
}
