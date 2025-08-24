#include <bits/stdc++.h>
using namespace std;
#define int long long

pair<int,int> dp[17][2][2];

pair<int,int> func(int ind, string &s, bool tight, bool start, int d) {
    if(ind == s.size()) {
        if(!start) return {0, 0};
        return {0, 1};
    }
    auto &res = dp[ind][tight][start];
    if(res != make_pair(-1, -1)) return res;
    int limit = (tight ? (s[ind] - '0') : 9);

    int ans = 0, cnt = 0;
    for(int i=0; i <= limit; i++) {
        auto pr = func(ind + 1, s, tight & (s[ind] - '0' == i), (start | (i != 0)), d);

        ans = ans + pr.first + (pr.second * (i == d));
        cnt = cnt + pr.second;

    }

    return res = {ans, cnt};
    
}

void reset() {
    for(int i=0;i<17;i++) {
        for(int j=0;j<2;j++) {
            for(int l=0;l<2;l++)
                dp[i][j][l] = {-1, -1};
        }
    }
}

inline void n_lamba_29() {

    int k;
    cin >> k;
    if(k <= 9) {
        int sum = k*(k + 1) / 2;
        cout << sum << "\n";
        return;
    }
    int p = 9, sum = 0, digit = -1;
    for(int i=1;i<=16;i++) {
        if(sum > k - p*i) break;
        sum += p * i;
        p *= 10;
        digit = i;
    }
    vector<int> f(10, 0);
    int left = k - sum;

    int ff = (int)pow(10, digit);
    int cnt = left / (digit + 1);

    string s = to_string(ff + cnt - 1);
    for(int d = 1; d <= 9; d++) {
        reset();
        f[d] = func(0, s, 1, 0, d).first;
    }

    int cnt2 = left % (digit + 1);
    
    string s2 = to_string(ff + cnt);
    for(int i=0;i<cnt2;i++) {
        f[s2[i] - '0']++;
    }

    int ans = 0;
    for(int i=1;i<=9;i++) {
        ans += i*f[i];
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