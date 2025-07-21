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
 
int32_t main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    for(int i=0;i<n;i++) {
        int num;
        cin >> num;
        insert(num);
    }
 
    int ans = 0;
    for(int i=29;i>=0;i--) {
        if(ans >> i & 1) continue;
        ans ^= basis[i];
    }
    cout << ans << "\n";
 
    return 0;
}