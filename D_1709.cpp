#include <bits/stdc++.h>
using namespace std;

inline void n_lamba_29() {

    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];

    vector<pair<int,int>> res;
    for(int i=0;i<n;i++) {
        int ind = i, mini = a[i];
        for(int j=i+1;j<n;j++) {
            if(a[j] < mini) {
                mini = a[j];
                ind = j;
            }
        }
        if(i != ind) {
            while(ind > i) {
                swap(a[ind], a[ind-1]);
                res.push_back({1, ind});
                ind--;
            }
        }
    }
    for(int i=0;i<n;i++) {
        int ind = i, mini = b[i];
        for(int j=i+1;j<n;j++) {
            if(b[j] < mini) {
                mini = b[j];
                ind = j;
            }
        }
        if(i != ind) {
            while(ind > i) {
                swap(b[ind], b[ind-1]);
                res.push_back({2, ind});
                ind--;
            }
        }
    }
    for(int i=0;i<n;i++) {
        if(a[i] > b[i]) {
            swap(a[i], b[i]);
            res.push_back({3, i + 1});
        }
    }
    cout << res.size() << "\n";
    for(auto [a, b] : res) cout << a << " " << b << "\n";

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