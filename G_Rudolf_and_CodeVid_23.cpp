#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;

int fun(string s) {
    int mask = 0;
    for(int i=0;i<s.size();i++) {
        if(s[i] == '1')
        mask |= (1 << i);
    }
    return mask;
}

inline void n_lamba_29() {

    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int start = fun(s);

    vector<array<int,3>> v(m);
    for(int i=0;i<m;i++) {
        int days;
        string a, b;
        cin >> days >> a >> b;
        v[i] = {days, fun(a), fun(b)};
    }

    vector<int> dist(1 << 20, inf);

    dist[start] = 0;
    queue<int> q;
    q.push(start);
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(auto &[days, rem, add] : v) {
            int new_node = (node & ~(node & rem)) | add;
            // int new_node = node;
            // for(int i=0;i<n;i++) {
            //     if(node >> i & 1 && rem >> i & 1) {
            //         new_node &= ~(1 << i);
            //     }
            //     if(add >> i & 1) {
            //         new_node |= (1 << i);
            //     }
            // }
            if(dist[new_node] > dist[node] + days) {
                dist[new_node] = dist[node] + days;
                q.push(new_node);
            }
        }
    }

    int ans = dist[0];
    if(ans == inf) ans = -1;
    cout << ans << "\n";

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