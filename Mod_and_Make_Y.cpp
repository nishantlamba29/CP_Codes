#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void n_lamba_29() {
    int n, x, y;
    cin >> n >> x >> y;

    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    vector<int> temp, ans;
    
    for(int i=0;i<n;i++) {
        if(v[i] <= y) {
            break;
        }
        temp.push_back(v[i]);
        vector<int> vis(x+1, 0);
        queue<int> q;
        q.push(x);
        vis[x] = 1;
        bool flag = 0;
        while(q.size() && !flag) {
            int t = q.front(); 
            q.pop();
            if (t == y) {
                flag = 1;
                break;
            }
            for(auto it : temp) {
                int r = t % it;
                if(!vis[r]) {
                    vis[r] = 1;
                    if(r == y) {
                        flag = 1;
                        break;
                    }
                    q.push(r);
                }
            }
        }
        if(flag) {
            ans.push_back(i+1);
        }
    }


    cout << ans.size() << "\n";
    if(ans.size()) {
        for(auto i : ans) cout << i << " ";
        cout << '\n';
    }
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