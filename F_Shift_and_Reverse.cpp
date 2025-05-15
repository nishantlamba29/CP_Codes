#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
// sss..r
int func(vector<int> v, int n) {
    int cnt = 0, ind = -1;
    for(int i=0;i<n;i++) {
        if(v[i] < v[(i+1) % n]) {
            cnt++;
            ind = i + 1;
        }
    }
    if(cnt >= 2) return inf;
    if(cnt == 0) return 0;
    return n - ind + 1;
} 
// ssss
int func2(vector<int> v, int n) {
    int cnt = 0, ind = -1;
    for(int i=0;i<n;i++) {
        if(v[i] > v[(i+1) % n]) {
            cnt++;
            ind = i + 1;
        }
    }
    if(cnt >= 2) return inf;
    if(cnt == 0) return 0;
    return n - ind;
}

inline void n_lamba_29() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    int ans = func(v, n); // ss..sr
    ans = min(ans, func2(v, n)); //ss..ss

    reverse(v.begin(), v.end());

    ans = min(ans, func(v, n) + 1); // rss..sr
    ans = min(ans, func2(v, n) + 1); // rss..ss

    cout << (ans == inf ? -1 : ans) << "\n";

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