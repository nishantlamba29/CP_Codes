#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void n_lamba_29() {

    int n, k;
    cin >> n >> k;
    vector<int> p(n), d(n);
    for(int i=0;i<n;i++) cin >> p[i];
    for(int i=0;i<n;i++) cin >> d[i];

    int q;
    cin >> q;
    int vis[n+1][k+1][2];
    while(q--) {
        int a;
        cin >> a;
        int st = a;
        int dir = 0;
        int time = 0;
        bool flag = 1;
        memset(vis, 0, sizeof(vis));
        while(1) {
            int idx2 = lower_bound(p.begin(), p.end(), st) - p.begin();
            if(idx2 < n && p[idx2] == st) {
                if(vis[idx2][time][dir]) {
                    flag = 0;
                    break;
                }
                vis[idx2][time][dir] = 1;
                if(time == d[idx2]) dir ^= 1;
            }
            int next;
            int dist;
            if(dir == 0) {
                int it = upper_bound(p.begin(), p.end(), st) - p.begin();
                if(it == n) {
                    flag = 1;
                    break;
                }
                next = it;
                dist = p[next] - st;
            }
            else {
                int it = lower_bound(p.begin(), p.end(), st) - p.begin();
                if(it == 0) {
                    flag = 1;
                    break;
                }
                next = it - 1;
                dist = st - p[next];
            }
            time = (time + dist) % k;
            st = p[next];
        }
        if(flag) cout << "YES\n";
        else cout << "NO\n";
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