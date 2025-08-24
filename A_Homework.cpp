#include <bits/stdc++.h>
using namespace std;

inline void n_lamba_29() {

    int n;
    string s;
    cin >> n >> s;
    int m;
    cin >> m;
    string b, c;
    cin >> b >> c;

    for(int i=0;i<m;i++) {
        if(c[i] == 'V') {
            s = b[i] + s;
        }
        else {
            s += b[i];
        }
    }
    cout << s << "\n";
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