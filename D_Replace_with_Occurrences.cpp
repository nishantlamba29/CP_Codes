#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void n_lamba_29() {
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    vector<int> t(n);
    for(int i=0;i<n;i++) {
        cin >> v[i].first;
        t[i] = v[i].first;
        v[i].second = i;
    }
    
    sort(v.begin(), v.end());
    int k = 1;
    vector<int> ans(n);
    for(int i=0;i<n;i++) {
        int val = v[i].first;
        int j = i;
        while(val-- && j < n) {
            ans[v[j].second] = k;
            j++;
        }
        i = j - 1;
        k++;
    }
    vector<int> f(n + 1);
    for(int i=0;i<n;i++) {
        f[ans[i]]++;
    }
    for(int i=0;i<n;i++) {
        if(f[ans[i]] != t[i]) {
            cout << "-1\n";
            return;
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