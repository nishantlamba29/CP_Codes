#include <bits/stdc++.h>
using namespace std;
#define int long long

int powr(int a, int b) {
    int res = 1;
    while(b > 0) {
        if(b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

int fx(int x) {
    int ans = powr(3, x + 1) + x * powr(3, x - 1);
    return ans;
}

inline void n_lamba_29() {

    int n, k;
    cin >> n >> k;
    vector<int> cnt(20, 0);
    int i = 0;
    int temp = n;
    while(temp) {
        cnt[i++] = temp % 3;
        temp /= 3;
    }

    int c1 = accumulate(cnt.begin(), cnt.end(), 0LL);
    if(c1 > k) {
        cout << "-1\n";
        return;
    }
    int ans = 0;
    for(int i=0;i<20;i++) {
        ans += cnt[i] * fx(i);
    }

    int extra = (k - c1) / 2;

    // f[x] - 3f[x-1] = pow(3, x-1)
    // taking (k - c1) / 2 bcz
    // 2 extra deals needed for deacreasing cost by pow(3, x-1)

    for(int i=19;i>0;i--) {
        if(extra == 0) break;
        int take = min(cnt[i], extra);
        int reduce = powr(3, i - 1);
        ans -= reduce * take;
        cnt[i] -= take;
        cnt[i-1] += (3 * take);
        extra -= take;
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