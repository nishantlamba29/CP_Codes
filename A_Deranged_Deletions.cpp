#include <bits/stdc++.h>
using namespace std;

inline void n_lamba_29() {

    int n;
    cin >> n;
    vector<int> v(n);
    vector<pair<int,int>> v2(n);
    for(int i=0;i<n;i++) {
        cin >> v[i];
        v2[i] = {v[i], i};
    }
    if(is_sorted(v.begin(), v.end())) {
        cout << "NO\n";
        return;
    }
    sort(v2.begin(), v2.end());
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            if(v2[i].second > v2[j].second) {
                cout << "YES\n";
                cout << 2 << "\n";
                cout << v2[j].first << " " << v2[i].first << "\n";
                return;
            }
        }
    }
    
    cout << "NO\n";

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