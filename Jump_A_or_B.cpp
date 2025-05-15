#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void n_lamba_29() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    int val = m - n*b;
    if(val % (a-b) == 0 && val / (a-b) >= 0 && val / (a-b) <= n) {
        cout << "Yes\n";
        return;
    }
    int val2 = m - n*a;
    if(val2 % (b-a) == 0 && val2 / (b-a) >= 0 && val2 / (b-a) <= n) {
        cout << "Yes\n";
        return;
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