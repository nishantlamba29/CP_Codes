#include <bits/stdc++.h>
using namespace std;

inline void n_lamba_29() {

    string s;
    cin >> s;
    int n = s.size();
    int t1 = count(s.begin(), s.end(), 'T');
    int t2 = count(s.begin(), s.end(), 'F');
    int t3 = count(s.begin(), s.end(), 'N');
    while(t1--) cout << "T";
    while(t2--) cout << "F";
    while(t3--) cout << "N";
    for(int i=0;i<n;i++) {
        if(s[i] == 'T' || s[i] == 'F' || s[i] == 'N') continue;
        cout << s[i];
    }
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