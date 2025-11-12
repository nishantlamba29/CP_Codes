#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int inf = 1e17;

inline void n_lamba_29() {
    int n;
    cin >> n;
    vector<array<int, 3>> seg(n);
    vector<pair<int, int>> L, R;

    for(int i=0;i<n;i++) {
        int l, r, c;
        cin >> l >> r >> c;
        seg[i] = {l, r, c};
        L.push_back({l, i});
        R.push_back({r, i});
    }

    vector<int> ans(n, inf);

    sort(L.begin(), L.end());
    sort(R.begin(), R.end());

    vector<pair<int, int>> temp;
    int ptr = 0;
    for(int i=0;i<n;i++) {
        int ind = R[i].second;
        int curr_c = seg[ind][2];
        while(ptr < n && L[ptr].first <= R[i].first) {
            int col = seg[L[ptr].second][2];
            int r = seg[L[ptr].second][1];
            bool flag = 0;
            for(auto &it : temp) {
                if(it.second == col) {
                    it.first = max(it.first, r);
                    flag = 1;
                    break;
                }
            }
            if(!flag) temp.push_back({r, col});
            sort(temp.rbegin(), temp.rend());
            if(temp.size() > 2) temp.pop_back();
            ptr++;
        }
        for(auto &[r, c] : temp) {
            if(c != curr_c) {
                ans[ind] = min(ans[ind], max(0LL, seg[ind][0] - r));
            }
        }
    }

    temp.clear();
    ptr = n-1;

    for(int i=n-1;i>=0;i--) {
        int ind = L[i].second;
        int curr_c = seg[ind][2];
        while(ptr >=0 && L[i].first <= R[ptr].first) {
            int col = seg[R[ptr].second][2];
            int l = seg[R[ptr].second][0];
            bool flag = 0;
            for(auto &it : temp) {
                if(it.second == col) {
                    it.first = min(it.first, l);
                    flag = 1;
                    break;
                }
            }
            if(!flag) temp.push_back({l, col});
            sort(temp.begin(), temp.end());
            if(temp.size() > 2) temp.pop_back();
            ptr--;
        }
        for(auto &[l, c] : temp) {
            if(c != curr_c) {
                ans[ind] = min(ans[ind], max(0LL, l - seg[ind][1]));
            }
        }
    }

    for(int i=0;i<n;i++) cout << ans[i] << " ";
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