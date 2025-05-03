#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void n_lamba_29() {

    int n;
    string s;
    cin >> n >> s;
    for(int i=0;i<n;i++) {
        if(s[i] == 'A'){
            bool flag = 1;
            for(int j=0;j<n;j++) {
                if(s[j] == 'B') {
                    if((j == 0 && i == n-1) || (j == n-1 && i != 0) || (j != n-1 && j > i)) flag = 0;
                }
            }
            if(flag) {
                cout << "Alice\n";
                return;
            }
        }
    }
    cout << "Bob\n";


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