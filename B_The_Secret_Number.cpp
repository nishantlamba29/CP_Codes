#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void n_lamba_29() {
    int n;
    cin >> n;

    int p = 10;
    vector<int> res;
    for(int i=0;i<=18;i++) {

        int num = p + 1;
        if(n % num == 0) {
            res.push_back(n / num);
        }
        p *= 10;

    }
    cout << res.size() << "\n";
    sort(res.begin(), res.end());
    if(res.size()){
    for(int i : res) cout << i << " "; cout << "\n";}

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