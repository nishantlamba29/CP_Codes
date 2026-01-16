#include <bits/stdc++.h>
using namespace std;

inline void n_lamba_29() {

    int n;
    cin >> n;
    vector<int> v(n);
    int mx = -21, mn = 21, pos = 0, neg = 0, ind1 = -1, ind2 = -1;
    for(int i=0;i<n;i++) {
        cin >> v[i];
        if(v[i] < 0) neg++;
        if(v[i] > 0) pos++;
        if(v[i] > mx) {
            mx = v[i];
            ind1 = i+1;
        }
        if(v[i] < mn) {
            mn = v[i];
            ind2 = i+1;
        }
    }

    if(is_sorted(v.begin(), v.end())) {
        cout << "0\n";
        return;
    }

    if(mn >= 0) {
        cout << n - 1 << "\n";
        for(int i=2;i<=n;i++) {
            cout << i << " " << i - 1 << "\n";
        }
        return;
    }
    if(mx <= 0) {
        cout << n - 1 << "\n";
        for(int i=n-1;i>0;i--) {
            cout << i << " " << i + 1 << "\n";
        }
        return;
    }

    int left = 31 - (n - 1); // operations left
    int curr = mx;

    int cnt_double = 0;
    while(curr < abs(mn)) {
        curr += curr;
        cnt_double++;
    }

    if(neg <= left - cnt_double) {
        cout << n - 1 + neg +  cnt_double << "\n";
        for(int i=0;i<cnt_double;i++) {
            cout << ind1 << " " << ind1 << "\n";
        }
        for(int i=0;i<n;i++) {
            if(v[i] < 0) {
                cout << i + 1 << " " << ind1 << "\n";
            }
        }
        for(int i=2;i<=n;i++) {
            cout << i << " " << i - 1 << "\n";
        }
        return;
    }
    curr = abs(mn);
    cnt_double = 0;
    while(curr < mx) {
        curr += curr;
        cnt_double++;
    }
    cout << n - 1 + pos + cnt_double << "\n";
    for(int i=0;i<cnt_double;i++) {
        cout << ind2 << " " << ind2 << "\n";
    }
    for(int i=0;i<n;i++) {
        if(v[i] > 0) {
            cout << i + 1 << " " << ind2 << "\n";
        }
    }
    for(int i=n-1;i>0;i--) {
        cout << i << " " << i + 1 << "\n";
    }


}


int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int _;
    cin >> _;
    while (_-->0) {
        n_lamba_29();
    }


    return 0;
}