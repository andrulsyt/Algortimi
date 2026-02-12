#include <iostream>

using namespace std;

const int MAX = 1000005;

int a[MAX];

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> a[i];
    

    int candidat = 0;
    int cnt = 0;

    for (int i = 1; i <= n; i++)
    {
        if (cnt == 0)
        {
            candidat = a[i];
            cnt = 1;
        }

        else if (a[i] == candidat)
            cnt++;
        else
            cnt--;
    }

    cnt = 0;

    for (int i = 1; i <= n; i++)
    {
        if (a[i] == candidat)
            cnt++;
        
    }

    if (cnt > n / 2)
        cout << candidat;
    
    else
        cout << -1;
    

    return 0;
}
