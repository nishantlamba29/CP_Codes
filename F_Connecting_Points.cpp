#include <bits/stdc++.h>
using namespace std;
#define int long long

template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

class DSU {
public:
    vector<int> par, sz;
    DSU(int n){
        par.resize(n + 1);
        iota(par.begin(), par.end(), 0);
        sz.resize(n + 1, 1);
    }
    int find(int x){
        return x == par[x] ? x : par[x] = find(par[x]);
    }
    bool merge(int u, int v) {
        int p1 = find(u), p2 = find(v);
        if (p1 == p2) return 0;
        if (sz[p1] < sz[p2]) swap(p1, p2);
        par[p2] = p1;
        sz[p1] += sz[p2];
        return 1;
    }
};

int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;
    vector<pair<int,int>> coord(n);
    for(int i=0;i<n;i++) {
        cin >> coord[i].first >> coord[i].second;
    }

    min_heap<array<int,3>> pq;
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            int dist = abs(coord[i].first - coord[j].first) + abs(coord[i].second - coord[j].second);
            pq.push({dist, i, j});
        }
    }

    DSU ds(n+q);

    while(q--) {
        int type;
        cin >> type;
        if(type == 1) {
            int a, b;
            cin >> a >> b;
            coord.push_back({a, b});
            for(int i=0;i<n;i++) {
                int dist = abs(coord[i].first - a) + abs(coord[i].second - b);
                pq.push({dist, n, i});
            }
            n++;
        }
        else if(type == 2) {
            int mini = -1;
            while(!pq.empty()) {
                auto [w, u, v] = pq.top();
                pq.pop();
                if(ds.merge(u, v)) {
                    mini = w;
                    break;
                }
            }
            if(mini == -1) {
                cout << "-1\n";
                continue;
            }
            while(!pq.empty() && pq.top()[0] == mini) {
                auto [w, u, v] = pq.top();
                pq.pop();
                ds.merge(u, v);
            }
            cout << mini << "\n";
        }
        else {
            int a, b;
            cin >> a >> b;
            a--, b--;
            if(ds.find(a) != ds.find(b)) {
                cout << "No\n";
            }
            else cout << "Yes\n";
        }
    }


    return 0;
}