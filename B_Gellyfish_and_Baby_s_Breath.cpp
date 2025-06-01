#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;

int modpowr(int a, int b) {
    int res = 1;
    while(b > 0) {
        if(b & 1LL) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1LL;
    }
    return res;
}

inline void n_lamba_29() {

    int n;
    cin >> n;
    vector<int> p(n), q(n);
    for(int i=0;i<n;i++) cin >> p[i];
    for(int i=0;i<n;i++) cin >> q[i];

    vector<int> pre1(n), ind1(n);
    pre1[0] = p[0], ind1[0] = 0;
    for(int i=1;i<n;i++) {
        if(p[i] > pre1[i-1]) {
            pre1[i] = p[i];
            ind1[i] = i;
        }
        else {
            pre1[i] = pre1[i-1];
            ind1[i] = ind1[i-1];
        }
    }
    vector<int> pre2(n), ind2(n);
    pre2[0] = q[0], ind2[0] = 0;
    for(int i=1;i<n;i++) {
        if(q[i] > pre2[i-1]) {
            pre2[i] = q[i];
            ind2[i] = i;
        }
        else {
            pre2[i] = pre2[i-1];
            ind2[i] = ind2[i-1];
        }
    }

    for(int i=0;i<n;i++) {
        if(pre1[i] > pre2[i]) {
            int ind = ind1[i];
            int temp = q[i - ind];
            cout << (modpowr(2, pre1[i]) + modpowr(2, temp)) % mod << " ";
        }
        else if(pre1[i] < pre2[i]) {
            int ind = ind2[i];
            int temp = p[i - ind];
            cout << (modpowr(2, pre2[i]) + modpowr(2, temp)) % mod << " ";
        }
        else {
            int ind = ind1[i];
            int temp = q[i - ind];
            int ind3 = ind2[i];
            temp = max(temp, p[i - ind3]);
            cout << (modpowr(2, pre1[i]) + modpowr(2, temp)) % mod << " ";
        }
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