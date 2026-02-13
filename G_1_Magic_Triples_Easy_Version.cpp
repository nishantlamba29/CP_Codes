#include <bits/stdc++.h>
using namespace std;
// First you make it work, then you can always make it beautiful
#define int long long

const int MAX = 1e6 + 5;
int freq[MAX];

void solve() {
    int n;
    cin >> n;
    vector<int> org(n);
    for(int i=0;i<n;i++) {
        cin >> org[i];
        freq[org[i]]++;
    }
    vector<int> v = org;

    int mx = *max_element(v.begin(), v.end());

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    n = v.size();
    
    int ans = 0;
    for(int b = 2; b*b <= mx; b++) {
        for(int i=0;i<n;i++) {
            if(v[i] % b == 0) {
                int ff = v[i] / b;
                int ss = v[i] * b;
                if(ss <= mx && freq[ff] && freq[ss]) {
                    ans += freq[ff] * freq[v[i]] * freq[ss];
                }
            }
        }
    }
    for(int i=0;i<n;i++) {
        ans += freq[v[i]] * (freq[v[i]] - 1) * (freq[v[i]] - 2);
    }

    cout << ans << "\n";

    // just this optimisation was needed :( 
    for(int i=0;i<org.size();i++) {
        freq[org[i]]--;
    }

}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int _;
    cin >> _;
    while (_-->0) {
        solve();
    }

    return 0;
}