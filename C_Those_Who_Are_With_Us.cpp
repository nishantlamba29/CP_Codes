#include <bits/stdc++.h>
using namespace std;

inline void n_lamba_29() {

    int n, m;
    cin >> n >> m;
    int maxi = 0;
    vector<vector<int>> v(n, vector<int>(m));
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> v[i][j];
            maxi = max(maxi, v[i][j]);
        }
    }
    vector<int> row(n), col(m);
    int cnt = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(v[i][j] == maxi) {
                row[i]++;
                col[j]++;
                cnt++;
            }
        } 
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(row[i] + col[j] - (v[i][j] == maxi) == cnt) {
                cout << maxi - 1 << "\n";
                return;
            }
        }
    }

    cout << maxi << "\n";

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