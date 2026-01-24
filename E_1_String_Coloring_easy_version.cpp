#include <bits/stdc++.h>
using namespace std;
// First you make it work, then you can always make it beautiful

void solve() {
    int n;
    string org;
    cin >> n >> org;

    string s = org;
    s.erase(unique(s.begin(), s.end()), s.end());
    n = s.size();

    vector<vector<int>> adj(n+1);

    for(int i=0;i<n-1;i++) {
        int j = i;
        while(j >= 0) {
            if(s[j] > s[i+1]) {
                adj[i+1].push_back(j);
                adj[j].push_back(i+1);
            }
            j--;
        }
        j = i+1;
        while(j < n) {
            if(s[j] < s[i]) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
            j++;
        }
    }
    vector<int> color(n, -1);
    for(int i=0;i<n;i++) {
        if(color[i] == -1) {
            color[i] = 0;
            queue<int> q;
            q.push(i);
            while(q.size()) {
                int node = q.front();
                q.pop();
                for(auto j : adj[node]) {
                    if(color[j] == -1) {
                        color[j] = (1 ^ color[node]);
                        q.push(j);
                    }
                    else if(color[j] == color[node]) {
                        cout << "NO\n";
                        return;
                    }
                }
            }
        }
    }

    int ptr = 0;
    int sz = org.size();
    cout << "YES\n";
    for(int i=0;i<n;i++) {
        int curr = ptr;
        while(ptr < sz && org[curr] == org[ptr]) {
            cout << color[i];
            ptr++;
        }
    }

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