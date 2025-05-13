#include <bits/stdc++.h>
using namespace std;

inline void n_lamba_29() {
    int n, k;
    cin >> n >> k;
    if(k < n - 1) {
        cout << "-1\n";
        return;
    }
    if(k == n - 1) {
        for(int i=0;i<n;i++) {
            cout << i + 1 << " ";
        }
        cout << "\n";
        return;
    }
    int val = k - n + 2;
    vector<int> ans;
    ans.push_back(val);
    ans.push_back(2*val);
    int num = 2;
    for(int i=2;i<n;i++) {
        int x = 2*val + i - 1;
        ans.push_back(x);
    }
    for(auto i : ans ) cout << i << " ";
    cout << "\n";


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