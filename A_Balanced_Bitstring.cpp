#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void n_lamba_29() {
    int n, k;
    string s;
    cin >> n >> k >> s;

    int i = 0, j = k;
    while(j < n) {
        if(s[i] != '?' && s[j] != '?' && s[i] != s[j]) {
            cout << "NO\n";
            return;
        }
        if(s[i] == '?') s[i] = s[j];
        if(s[j] == '?') s[j] = s[i];
        i++;
        j++;
    }

    int t1 = 0, t2 = 0;
    for(int i=0;i<k;i++) {
        if(s[i] == '1') t1++;
        else if(s[i] == '0') t2++;
    }
    if(t1 > k/2 || t2 > k/2) {
        cout << "NO\n";
        return;
    }
    i = 0, j = k;
    while(j < n) {
        if(s[i] == '1') t1--;
        else if(s[i] == '0') t2--;
        i++;
        if(s[j] == '1') t1++;
        else if(s[j] == '0') t2++;
        j++;
        if(t1 > k/2 || t2 > k/2) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";


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