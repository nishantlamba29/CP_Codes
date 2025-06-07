#include <bits/stdc++.h>
using namespace std;

inline void n_lamba_29() {

    int n;
    string s;
    cin >> n >> s;

    int ind = -1;
    for(int i=0;i<n-1;i++) {
        if(s[i] > s[i+1]) {
            ind = i;
            break;
        }
    }
    if(ind == -1) {
        cout << s << "\n";
        return;
    }
    int ind2 = -1;
    for(int i=ind+1;i<n;i++) {
        if(s[i] > s[ind]) {
            ind2 = i;
            break;
        }
    }
    if(ind2 == -1) {
        for(int i=0;i<n;i++) {
            if(i == ind) continue;
            cout << s[i];
        }
        cout << s[ind] << "\n";
    }
    else {
        for(int i=0;i<n;i++) {
            if(i == ind) continue;
            if(i == ind2) {
                cout << s[ind] << s[i];
                continue;
            }
            cout << s[i];
        }
        cout << "\n";
    }



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