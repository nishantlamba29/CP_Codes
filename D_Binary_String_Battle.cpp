#include <bits/stdc++.h>
using namespace std;

inline void n_lamba_29() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    int cnt = count(s.begin(), s.end(), '1');
    
    if(cnt <= k || 2 * k - n >= 1) cout << "Alice\n";
    else cout << "Bob\n";

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