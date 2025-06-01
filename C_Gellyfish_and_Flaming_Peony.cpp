#include <bits/stdc++.h>
using namespace std;

inline void n_lamba_29() {
    
    int n;
    cin >> n;
    vector<int> v(n);
    int val = 0;
    for(int i=0;i<n;i++) {
        cin >> v[i];
        val = __gcd(val, v[i]);
    }
    int one = 0;
    for(int i=0;i<n;i++) {
        v[i] /= val;
        one += (v[i] == 1);
    }
    if(one != 0) {
        cout << n - one << "\n";
        return;
    }
    vector<int> dist(5005, 5005);
    queue<int> q;
    vector<int> vis(5005, 0);
    for(int i=0;i<n;i++) {
        if(!vis[v[i]]) {
            vis[v[i]] = 1;
            dist[v[i]] = 0;
            q.push(v[i]);
        }
    }

    while(q.size()) {
        int curr = q.front();
        q.pop();
        if(curr == 1) break;
        for(int i=0;i<n;i++) {
            int temp = __gcd(curr, v[i]);
            if(dist[temp] > dist[curr] + 1) {
                dist[temp] = dist[curr] + 1;
                q.push(temp);
            }
        }
    }

    int mini = dist[1];
    cout << mini + n - 1 << "\n";

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