#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define rep0(i, n) for (i = 0; i < n; i++)
#define rep(i, n) for (i = 1; i <= n; i++)
#define reps(i, a, n) for (i = a; i <= n; i++)
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, x, y, z;
    cin >> t;
    if (t == 1)
        cout << -1;
    else if (t % 2 == 0)
    {
        int i;
        int c = 2;
        rep0(i, t)
        {
            if (i % 2 == 0)
            {
                cout << c << " ";
                c += 2;
            }
            else
            {
                cout << i << " ";
            }
        }
    }
    else
    {
        cout<<-1;
    }
    cout << endl;
    return 0;
}