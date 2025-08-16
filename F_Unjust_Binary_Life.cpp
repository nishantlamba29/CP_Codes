#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void n_lamba_29() {

    int n;
    string a, b;
    cin >> n >> a >> b;
    vector<int> cnt1(n); //  0 - 1;
    for(int i=0;i<n;i++) {
        cnt1[i] = (a[i] == '0') - (a[i] == '1');
        if(i != 0) cnt1[i] += cnt1[i-1];
    }
    vector<int> cnt2(n); // 1 - 0;
    for(int i=0;i<n;i++) {
        cnt2[i] = (b[i] == '1') - (b[i] == '0');
        if(i != 0) cnt2[i] += cnt2[i-1];
    }
    sort(cnt1.begin(), cnt1.end());
    sort(cnt2.begin(), cnt2.end());

    vector<int> pre(n), suff(n + 1);
    pre[0] = cnt2[0], suff[n-1] = cnt2[n-1];
    for(int i=1;i<n;i++) pre[i] = pre[i-1] + cnt2[i];
    for(int i=n-2;i>=0;i--) suff[i] = suff[i+1] + cnt2[i];

    int ans = 0;

    for(int i=0;i<n;i++) {
        int ind = upper_bound(cnt2.begin(), cnt2.end(), cnt1[i]) - cnt2.begin();
        if(ind == 0) {
            if(cnt2[0] > cnt1[i]) {
                ans += suff[0] - n * cnt1[i];
            }
            else {
                ans += suff[1] - (n - 1) * cnt1[i] + cnt1[i] - pre[0];
            }
        }
        else if(ind == n) {
            ans += n * cnt1[i] - pre[n-1];
        }
        else {
            ind--;
            ans += (ind + 1) * cnt1[i] - pre[ind] + suff[ind + 1] - (n - ind - 1) * cnt1[i];
        }
    }

    int res = (n*n)*(n+1) / 2 - ans / 2;
    cout << res << "\n";

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