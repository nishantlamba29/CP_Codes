#include <bits/stdc++.h>
using namespace std;

inline void n_lamba_29() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    vector<int> fact;
    for(int i=1;i*i<=n;i++) {
        if(n%i == 0) {
            fact.push_back(i);
            if(i != n/i) fact.push_back(n/i);
        }
    }

    int ans = 0;
    for(auto &num : fact) {
        int i = 0, j = num;
        if(num == n) {
            ans += 1;
            continue;
        }
        int gcd = 0;
        bool flag = 1;
        while(j < n) {
            gcd = __gcd(gcd, abs(v[i] - v[j]));
            flag &= (v[i] == v[j]);
            i++;
            j++;
        }
        ans += (gcd >= 2 || flag);
    }
    cout << ans << "\n";

}


int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int _;
    cin >> _;
    while (_-->0) {
        n_lamba_29();
    }


    return 0;
}