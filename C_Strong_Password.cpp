#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;
int n, m;
string s, l, r;
int nx[N][10];
int dp[11][N];

bool rec(int i, int j) {
    if(i == m) return 0;
    if(j == n) return 1;
    auto &res = dp[i][j];
    if(res != -1) return res;
    res = 0;
    for(int k = l[i] - '0'; k <= r[i] - '0'; k++) {
        if(nx[j][k] == n) {
            res = 1;
            break;
        }
        res |= rec(i+1, nx[j][k] + 1);
        if(res) break;
    }
    return res;
}

inline void n_lamba_29() {

    cin >> s >> m >> l >> r;
    n = s.size();

    for(int i=0;i<10;i++) {
        nx[n][i] = n;
    }
    for(int i=n-1;i>=0;i--) {
        for(int j=0;j<10;j++) {
            nx[i][j] = nx[i+1][j];
        }
        nx[i][s[i] - '0'] = i;
    }

    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) dp[i][j] = -1;
    }   

    if(rec(0, 0)) cout << "YES\n";
    else cout << "NO\n";

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