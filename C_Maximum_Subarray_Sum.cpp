#include <bits/stdc++.h>
using namespace std;
#define int long long

const int inf = (int) 1e13;

void print(vector<int> &v) {
    for(auto &i : v) cout << i << " ";
    cout << "\n";
}

inline void n_lamba_29() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    int ind = - 1;
    for(int i=0;i<n;i++) {
        if(s[i] == '0') {
            ind = i;
            break;
        }
    }
    if(ind == -1) {
        int maxi = 0, sum = 0;
        for(int i=0;i<n;i++) {
            sum = max(v[i], sum + v[i]);
            maxi = max(maxi, sum);
        }
        if(maxi == k) {
            cout << "YES\n";
            print(v);
        }
        else {
            cout << "NO\n";
        }
        return;
    }

    
    int sum = 0, maxi = 0;
    for(int i=0;i<n;i++) {
        if(s[i] == '0') {
            sum = 0;
        }
        else {
            sum = max(v[i], sum + v[i]);
            maxi = max(maxi, sum);
        }
    }
    if(maxi > k ) {
        cout << "NO\n";
        return;
    }

    for(int i=0;i<n;i++) {
        if(s[i] == '0' && i != ind) {
            v[i] = -inf;
        }
    }
    int s1 = 0, s2 = 0, m1 = 0, m2 = 0;
    for(int i=ind+1;i<n;i++) {
        s1 += v[i];
        m1 = max(m1, s1);
    }
    for(int i = ind-1;i>=0;i--) {
        s2 += v[i];
        m2 = max(m2, s2);
    }
    v[ind] = k - m1 - m2;
    cout << "YES\n";
    print(v);

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