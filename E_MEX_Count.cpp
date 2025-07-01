#include <bits/stdc++.h>
using namespace std;

inline void n_lamba_29() {

    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> freq(n+1, 0);
    for(int i=0;i<n;i++) {
        cin >> v[i];
        freq[v[i]]++;
    }

    vector<int> ans(n+2, 0);
    
    ans[freq[0]]++;
    ans[n + 1]--;

    for(int i=1;i<=n;i++) {
        if(!freq[i-1]) break;
        ans[freq[i]]++;
        ans[n-i+1]--;
    }

    for(int i=1;i<=n;i++) ans[i] += ans[i-1];
    for(int i=0;i<=n;i++) cout << ans[i] << " ";
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