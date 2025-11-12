#include <bits/stdc++.h>
using namespace std;

struct node {
    int mini;
    int maxi;
    bool flag;
    int ops;
    node(int l, int r, bool f, int c) {
        mini = l;
        maxi = r;
        flag = f;
        ops = c;
    }
};

node rec(int l, int r, vector<int> &v) {
    if(l == r) {
        return node(v[l], v[l], 1, 0);
    }
    int mid = (l + r) >> 1;
    node left = rec(l, mid, v);
    node right = rec(mid + 1, r, v);
    if(!left.flag || !right.flag) return node(0, 0, 0, 0);

    if(left.maxi < right.mini) {
        return node(left.mini, right.maxi, 1, left.ops + right.ops);
    }
    if(left.mini > right.maxi) {
        return node(right.mini, left.maxi, 1, left.ops + right.ops + 1);
    }
    return node(0, 0, 0, 0);
}

inline void n_lamba_29() {

    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    
    node ans = rec(0, n - 1, v);
    if(!ans.flag) cout << "-1\n";
    else cout << ans.ops << "\n";

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