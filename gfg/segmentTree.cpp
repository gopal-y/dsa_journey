#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define rep0(i, n) for (i = 0; i < n; i++)
#define rep(i, n) for (i = 1; i <= n; i++)
#define reps(i, a, n) for (i = a; i <= n; i++)
#define endl "\n"
using namespace std;
class SegmentTree
{
    int *t;
    int N;

public:
    SegmentTree(int n)
    {
        this->t = (int *)malloc((2 * n + 2) * sizeof(int));
        this->N = 2 * n + 2;
    }
    void Build(int node, int start, int end, int arr[])
    {
        // cout << node << " " << start << " " << end << " " << arr[start] << "\n";
        if (start == end)
        {
            this->t[node] = arr[start];
            cout << node << "=>" << arr[start] << "\n";
        }
        else
        {
            int mid = (start + end) / 2;
            Build(2 * node, start, mid, arr);
            Build(2 * node + 1, mid + 1, end, arr);
            this->t[node] = this->t[2 * node] + this->t[2 * node + 1];
            cout << node << " " << arr[start] << "\n";
        }
    }
    int Query(int node, int start, int end, int l, int r)
    {
        if (r < start || l > end)
        {
            return 0;
        }
        if (l <= start && end <= r)
        {
            return this->t[node];
        }
        int mid = (start + end) / 2;
        return Query(2 * node, start, mid, l, r) + Query(2 * node + 1, mid + 1, end, l, r);
    }
    void Print()
    {
        int i;
        reps(i, 1, this->N)
        {
            cout << this->t[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int arr[] = {1, 3, 5, 7, 9, 11};
    SegmentTree st = SegmentTree(6);
    st.Build(1, 0, 5, arr);
    int l, r;
    st.Print();
    cin >> l >> r;
    cout << st.Query(1, 0, 5, l, r);
    return 0;
}
