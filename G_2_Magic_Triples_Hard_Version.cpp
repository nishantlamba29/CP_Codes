#include <bits/stdc++.h>
using namespace std;
// First you make it work, then you can always make it beautiful
#define int long long
const int MAX = 1e6 + 5;
const int MAX2 = 1e9 + 5;

vector<int> get(int n) {
    vector<int> res;
    for(int i=1;i*i<=n;i++) {
        if(n % i == 0) {
            res.push_back(i);
            if(i*i != n) res.push_back(n / i);
        }
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    map<int, int> freq;
    for(int i=0;i<n;i++) {
        cin >> v[i];
        freq[v[i]]++;
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    n = v.size();
    int mx = *max_element(v.begin(), v.end());

    int ans = 0;

    for(int i=0;i<n;i++) {
        if(v[i] < MAX) {
            auto fac = get(v[i]);
            for(auto b : fac) {
                if(b == 1) continue;
                int ff = v[i] / b;
                int ss = v[i] * b;
                auto it1 = freq.find(ff);
                auto it2 = freq.find(ss);
                if(it1 != freq.end() && it2 != freq.end()) {
                    ans += (it1->second) * (it2->second) * freq[v[i]];
                }
            }
        }
        else {
            for(int b = 2; v[i] * b <= MAX2; b++) {
                if(v[i] % b == 0) {
                    int ff = v[i] / b;
                    int ss = v[i] * b;
                    auto it1 = freq.find(ff);
                    auto it2 = freq.find(ss);
                    if(it1 != freq.end() && it2 != freq.end()) {
                        ans += (it1->second) * (it2->second) * freq[v[i]];
                    }
                }
            }
        }
    }

    for(int i=0;i<n;i++) {
        ans += freq[v[i]] * (freq[v[i]] - 1) * (freq[v[i]] - 2);
    }

    cout << ans << "\n";

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