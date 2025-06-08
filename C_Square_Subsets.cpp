#include <bits/stdc++.h>
using namespace std;
const int mod = 1'000'000'007;

int modpowr(int64_t a, int64_t b) {
    int64_t res = 1;
    while(b > 0) {
        if(b & 1LL) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1LL;
    }
    return res;
}

const int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};
const int d = sizeof(prime) / sizeof(prime[0]);
int basis[d];
int sz;

void insert(int mask) {
    for(int i=d-1;i>=0;i--) {
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

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for(int i=0;i<n;i++) {
        int a;
        cin >> a;
        int mask = 0;
        int x = a;
        for(int j=0;j<d;j++) {
            int cnt = 0;
            while(x % prime[j] == 0) {
                x /= prime[j];
                cnt ^= 1;
            }
            if(cnt) mask |= (1 << j);
        }
        insert(mask);
    }
    // number of subsets whose xor is zero 
    // sz are independent
    // n-sz are dependent i.e. can be made from linear combination of independent variable
    int ans = modpowr(2, n - sz);
    ans = (ans - 1 + mod) % mod;
    cout << ans << "\n";


    return 0;
}