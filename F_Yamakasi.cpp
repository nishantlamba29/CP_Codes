#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void n_lamba_29() {

    int n, s, x;
    cin >> n >> s >> x;
    vector<int> v(n), pre(n+1);
    for(int i=0;i<n;i++) {
        cin >> v[i];
        pre[i+1] = pre[i] + v[i];
    }

    map<int,int> mp;
    int left = 0, ans = 0;
    for(int i=0;i<n;i++) {
        if(v[i] > x) {
            mp.clear();
            left = i+1;
        }
        else if(v[i] == x) {
            while(left <= i) {
                mp[pre[left]]++;
                left++;
            }
        }
        // https://leetcode.com/problems/subarray-sum-equals-k/description/
        // now count subarrays ending at i whose sum == s
        // sum of a[j..i] = pref[i+1] - pref[j]
        // so we need pref[j] = pref[i+1] - s
        ans += mp[pre[i+1] - s];
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