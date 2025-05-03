#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void n_lamba_29() {

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    map<int,int> freq;
    int max_fr = 0, key = 0;

    for(int i=0;i<n;i++) {
        if(v[i] % k == 0) continue;
        int rem = k - v[i] % k;
        freq[rem]++;
        max_fr = max(max_fr, freq[rem]);
    }

    if(max_fr == 0) {
        cout << "0\n";
        return;
    }

    int temp = 0; // wo_wala_modulo_jiska_max_freq_h
    for(auto &[mod, fr] : freq) {
        if(fr == max_fr) {
            temp = mod;
        }
    }

    int ans = k * (freq[temp] - 1) + temp + 1;
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