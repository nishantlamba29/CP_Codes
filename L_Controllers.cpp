#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void n_lamba_29() {
    int n;
    string s;
    cin >> n >> s;
    int q;
    cin >> q;
    int x = count(s.begin(), s.end(), '+');
    int y = n - x;
    while(q--) {
        int a, b;
        cin >> a >> b;
        int val = a*y - b*x;
        if(a == b) {
            if(x == y) cout << "YES\n";
            else cout << "NO\n";
        }
        else if(val % (a-b) != 0) cout << "NO\n";
        else {
            int k = val / (a-b);
            if(k >= 0 && k <= n) cout << "YES\n";
            else cout << "NO\n";
        }
    }

}


int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    n_lamba_29();

    return 0;
}