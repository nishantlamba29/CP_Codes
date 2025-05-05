#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void n_lamba_29() {
    int n;
    cin >> n;
    vector<int> wt(n+1);
    int sum = 0;
    for(int i=1;i<=n;i++) {
        cin >> wt[i];
        sum += wt[i];
    }
    priority_queue<int> pq;
    vector<int> indegre(n+1, 0);

    for(int i=0;i<n-1;i++) {
        int u, v;
        cin >> u >> v;
        indegre[u]++;
        indegre[v]++;
        if(indegre[u] > 1) pq.push(wt[u]);
        if(indegre[v] > 1) pq.push(wt[v]);
    }

    for(int i=0;i<n-1;i++) {
        cout << sum << " ";
        if(!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
    }
    cout << "\n";

}


int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int _;
    cin >> _;
    while (_-->0) {
        n_lamba_29();
    }


    return 0;
}