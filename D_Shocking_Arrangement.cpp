#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void n_lamba_29() {
    int n;
    cin >> n;

    vector<int> v(n);
    int m1 = 0, m2 = 0;
    int cnt = 0;
    for(int i=0;i<n;i++) {
        cin >> v[i];
        if(v[i] == 0) cnt++;
        m1 = max(m1, v[i]);
        m2 = min(m2, v[i]);
    }

    if(cnt == n) {
        cout << "No\n";
        return;
    }
    int val = m1 - m2;
    sort(v.rbegin(), v.rend());
    int sum = 0;
    int l = 0, r = n - 1;
    cout << "Yes\n";
    while(l < r) {
        if(sum + v[l] >= val) {
            sum += v[r];
            cout << v[r--] << " ";
        }
        else {
            sum += v[l];
            cout << v[l++] << " ";
        }
    }
    if(l == r) cout << v[l] << " ";
    cout << "\n";

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