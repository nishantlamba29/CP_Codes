#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void n_lamba_29() {

    int n;
    cin >> n;
    vector<int> pos;
    for(int i=0;i<n;i++){
        char ch;
        cin >> ch;
        if(ch == '*') pos.push_back(i);
    }
    if(pos.empty()) {
        cout << "0\n";
        return;
    }
    int ans = 0;
    int ind = pos.size() / 2;
    int med = pos[ind];
    for(int i=0;i<pos.size();i++) {
        int target = med - (ind - i);
        ans += abs(pos[i] - target);
    }
    
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