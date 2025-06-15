#include <bits/stdc++.h>
using namespace std;

int sz;
int basis[30];
void insert(int mask) {
    for(int i=29;i>=0;i--) {
        if(mask >> i & 1) {
            if(!basis[i]) {
                basis[i] = mask;
                sz++;
                return;
            }
            mask ^= basis[i];
        }
    }
}


int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin >> v[i];
        insert(v[i]);
    }

    int ans = 0;
    vector<int> res;
    for(int i=0;i<k;i++) {
        for(int j=0;j<30;j++) {
            if(ans >> j & 1) continue;
            ans ^= basis[i];
        }
        cout << ans << " ";
    }
    cout << "\n";

    return 0;
}