#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void n_lamba_29() {
    int n;
    cin >> n;
    vector<int> indegree(n+1, 0);
    vector<pair<int,int>> edges;
    for(int i=0;i<n-1;i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
        indegree[u]++;
        indegree[v]++;
    }
    int node = -1;
    for(int i=1;i<=n;i++) {
        if(indegree[i] >= 3) {
            node = i;
            break;
        }
    }
    if(node == -1) {
        for(int i=0;i<n-1;i++) {
            cout << i << "\n";
        }
        return;
    }
    vector<int> ans(n-1, -1);
    int j = 0;
    for(int i=0;i<n-1;i++) {
        int u = edges[i].first, v = edges[i].second;
        if(u == node || v == node) {
            ans[i] = j++;
        }
    }
    for(int i=0;i<n-1;i++) {
        if(ans[i] == -1) {
            ans[i] = j++;
        }
    }
    for(int i=0;i<n-1;i++) {
        cout << ans[i] << "\n";
    }
 
}


int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    n_lamba_29();
    


    return 0;
}