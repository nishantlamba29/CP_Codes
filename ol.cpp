#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> p(N + 1);
    for (int i = 1; i <= N; i++) cin >> p[i];

    vector<vector<int>> g(N + 1);
    for (int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> par(N + 1, 0), d(N + 1, 0);
    vector<bool> v(N + 1, false);
    queue<int> q;
    q.push(1), v[1] = true, par[1] = -1, d[1] = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int nxt : g[cur]) {
            if (!v[nxt]) {
                v[nxt] = true;
                par[nxt] = cur;
                d[nxt] = d[cur] + 1;
                q.push(nxt);
            }
        }
    }

    vector<bool> c(N + 1, false);
    c[1] = true;
    vector<int> s;

    for (int i = 1; i <= N; i++) 
        if (p[i]) s.push_back(i);

    sort(s.begin(), s.end(), [&](int &a, int &b) { return d[a] > d[b]; });

    int b = 0;
    for (int stop : s) {
        if (!c[stop]) {
            b++;
            int cur = stop;
            while (cur != -1 && !c[cur]) {
                c[cur] = true;
                cur = par[cur];
            }
        }
    }

    cout << b << "\n";
    return 0;
}