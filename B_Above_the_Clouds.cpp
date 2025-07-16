#include <bits/stdc++.h>
using namespace std;

inline void n_lamba_29() {

    int n;
    string s;
    cin >> n >> s;

    vector<int> f(26, 0);
    for(int i=0;i<n-1;i++) {
        f[s[i] - 'a']++;
    }
    for(int i=0;i<26;i++) {
        if(f[i] > 1) {
            cout << "Yes\n";
            return;
        }
    }
    f.assign(26, 0);
    for(int i=1;i<n;i++) {
        f[s[i] - 'a']++;
    }
    for(int i=0;i<26;i++) {
        if(f[i] > 1) {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";


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