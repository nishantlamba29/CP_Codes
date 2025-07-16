#include <bits/stdc++.h>
using namespace std;

inline void n_lamba_29() {

    vector<pair<int,int>> x(3);
    int area = 0;
    for(int i=0;i<3;i++) {
        cin >> x[i].first >> x[i].second;
        area += x[i].first * x[i].second;
    }
    int S = sqrtl(area);
    if(S*S != area) {
        cout << "NO\n";
        return;
    }

    sort(x.begin(), x.end());
    bool flag = 0;

    if(x[0].second == S && x[1].second == S && x[2].second == S && x[0].first + x[1].first + x[2].first == S) flag = 1;

    if(x[0].first == S && x[1].first == S && x[2].first == S && x[0].second + x[1].second + x[2].second == S) flag = 1;
    if(x[2].second == S) {
        int W = S - x[2].first;
        if(W > 0 && x[0].first == W && x[1].first == W && x[0].second + x[1].second == S) flag = 1;
    }
    if(x[2].first == S) {
        int H = S - x[2].second;
        if(H > 0 && x[0].second == H && x[1].second == H && x[0].first + x[1].first == S) flag = 1;
    }

    if(flag) cout << "YES\n";
    else cout << "NO\n";

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