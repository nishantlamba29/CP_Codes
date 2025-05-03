#include <bits/stdc++.h>
using namespace std;
#define int long long
class DSU
{
public:
    vector<int> parent, size;
    DSU(int n)
    {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
        size.resize(n + 1, 1);
    }
    int find_par(int x)
    {
        if (x == parent[x])
            return x;
        return parent[x] = find_par(parent[x]);
    }
    bool union_set(int u, int v)
    {
        int p1 = find_par(u);
        int p2 = find_par(v);
        if (p1 == p2)
            return 0;
        if (size[p1] > size[p2])
        {
            swap(p1, p2);
        }
        parent[p1] = p2;
        size[p2] += size[p1];
        return 1;
    }
};

inline void lamba()
{
    int n;
    cin >> n;

    vector<vector<int>> x, y, z, v;

    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        x.push_back({a, i});
        y.push_back({b, i});
        z.push_back({c, i});
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    sort(z.begin(), z.end());

    for (int i = 1; i < n; i++)
    {
        v.push_back({x[i][0] - x[i - 1][0], x[i][1], x[i - 1][1]});
        v.push_back({y[i][0] - y[i - 1][0], y[i][1], y[i - 1][1]});
        v.push_back({z[i][0] - z[i - 1][0], z[i][1], z[i - 1][1]});
    }

    sort(v.begin(), v.end());
    DSU ds(n);
    int cost = 0;

    for (auto &i : v)
    {
        int ff = i[1], ss = i[2], wt = i[0];
        if (ds.union_set(ff, ss))
        {
            cost += wt;
        }
    }
    cout << cost << "\n";
}
int32_t main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    lamba();

    return 0;
}