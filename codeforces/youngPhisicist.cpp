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
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        x += a;
        y += b;
        z += c;
    }
    if (x + y + z == 0)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    cout << endl;
    return 0;
}