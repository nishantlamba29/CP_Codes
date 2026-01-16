#include <bits/stdc++.h>
using namespace std;

inline void n_lamba_29() {

    int n;
    cin >> n;
    vector<array<int,3>> v(n);
    for(int i=0;i<n;i++) {
        cin >> v[i][0] >> v[i][1];
        v[i][2] = i;
    }

    sort(v.begin(), v.end());
    int maxi = v[0][1];
    int ind = -1;
    for(int i=0;i<n-1;i++) {
        maxi = max(maxi, v[i][1]);
        if(maxi < v[i+1][0]) {
            ind = i;
            break;
        }
    }
    if(ind == -1) {
        cout << "-1\n";
        return;
    }
    vector<int> ans(n);
    for(int i=0;i<=ind;i++) ans[v[i][2]] = 1;
    for(int i=ind+1;i<n;i++) ans[v[i][2]] = 2;

    for(int i : ans) cout << i << " ";
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