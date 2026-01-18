#include <bits/stdc++.h>
using namespace std;
// First you make it work, then you can always make it beautiful


void solve() {

    int n;
    cin >> n;
    vector<string> v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    vector<vector<int>> adj(26);
    vector<int> indegree(26);

    for(int i=0;i<n-1;i++) {
        int ptr = 0;
        int sz1 = v[i].size(), sz2 = v[i+1].size();
        bool flag = 0;
        while(ptr < sz1 && ptr < sz2) {
            if(v[i][ptr] != v[i+1][ptr]) {
                int from = v[i][ptr] - 'a';
                int to = v[i+1][ptr] - 'a';
                adj[from].push_back(to);
                indegree[to]++;
                flag = 1;
                break;
            }
            ptr++;
        }
        if(flag == 0 && sz1 > sz2) {
            cout << "Impossible\n";
            return;
        }
    }

    queue<int> q;
    for(int i=0;i<26;i++) {
        if(indegree[i] == 0) q.push(i);
    }

    vector<int> temp;

    while(q.size()) {
        int node = q.front();
        temp.push_back(node);
        q.pop();
        for(auto j : adj[node]) {
            indegree[j]--;
            if(indegree[j] == 0) {
                q.push(j);
            }
        }
    }

    for(int i=0;i<26;i++) {
        if(indegree[i]) {
            cout << "Impossible\n";
            return;
        }
    }

    for(auto i : temp) {
        cout << (char)('a' + i);
    }
    cout << "\n";

}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // int _;
    // cin >> _;
    // while (_-->0) {
        solve();
    // }

    return 0;
}