#include <bits/stdc++.h>
using namespace std;
#define int long long

#define ld long double
const int N = 2e5;
vector<pair<int, ld>> adj[N+5];
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
const int inf = 2e18;

ld dijkstra(int n) {
    min_heap<pair<ld, int>> pq;
    vector<ld> d(n + 2, inf);
    d[n] = 0;
    pq.push({0, n});
    while (!pq.empty()) {
        auto [dist, node] = pq.top();
        pq.pop();
        if (dist > d[node]) continue;
        for (auto & [v, len] : adj[node]){
            if (d[node] + len < d[v]) {
                d[v] = d[node] + len;
                pq.push({d[v], v});
            }
        }
    }
    return d[n + 1];
}

int minDistance(vector<int> &a, vector<int> &b, vector<vector<int>> &lights){

    auto fun = [&](vector<int> &a, vector<int> &b){
        int x1 = a[0], x2 = b[0];
        int y1 = a[1], y2 = b[1];
        ld t1 = sqrtl((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
        return t1;
    };

    int n = lights.size();
    for (int i = 0; i <= n + 1; i++) adj[i].clear();

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            ld t1 = fun(lights[i], lights[j]);
            ld dist = max((ld)0.0, t1 - (lights[i][2] + lights[j][2]));
            adj[i].push_back({j, dist});
            adj[j].push_back({i, dist});
        }
    }

    for (int i = 0; i < n; ++i) {
        ld t1 = fun(a, lights[i]);
        ld dist = max((ld)0.0, t1 - lights[i][2]);
        adj[n].push_back({i, dist});
    }
    for (int i = 0; i < n; ++i) {
        ld t1 = fun(b, lights[i]);
        ld dist = max((ld)0.0, t1 - lights[i][2]);
        adj[i].push_back({n + 1, dist});
    }
    ld direct = fun(a, b);
    adj[n].push_back({n + 1, direct});

    ld result = dijkstra(n);
    return (int)result;


}


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int n;
    cin>>n;
    vector<int> a(2), b(2);
    for(int i=0;i<2;i++) cin>>a[i];
    for(int i=0;i<2;i++) cin>>b[i];
    vector<vector<int>> lights(n, vector<int>(3));
    for(int i=0;i<n;i++) cin>>lights[i][0]>>lights[i][1]>>lights[i][2];


    int ans = minDistance(a, b, lights);
    cout<<ans;
}