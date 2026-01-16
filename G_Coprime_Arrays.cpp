#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e6 + 6;
const int mod = 1e9 + 7;
int isPrime[N], spf[N], powr[N];

int modpowr(int a, int b) {
    int res = 1;
    while(b > 0) {
        if(b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

void seive() {
    for(int i=0;i<N;i++) {
        isPrime[i] = 1;
        spf[i] = i;
    }
    isPrime[0] = isPrime[1] = 0;
    for(int i=2;i<N;i++) {
        if(isPrime[i]) {
            for(int j=2*i;j<N;j+=i) {
                isPrime[j] = 0;
                spf[j] = min(spf[j], i);
            }
        }
    }
}

int32_t main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    seive();

    int n, k;
    cin >> n >> k;
    powr[0] = 0;
    for(int i=1;i<=k;i++) {
        powr[i] = modpowr(i, n);
    }

    int ans = 0;
    int prev = 1;


    for(int i=2;i<=k;i++) {
        int curr = prev;
        int t1 = 0, t2 = 0;
        int temp = i;
        vector<int> prime;
        while(temp != 1) {
            int s = spf[temp];
            prime.push_back(s);
            while(spf[temp] == s) {
                temp /= s;
            }
        }
        int sz = prime.size();
        for(int mask = 0; mask < (1 << sz); mask++) {
            int prod = 1;
            for(int j=0;j<sz;j++) {
                if(mask >> j & 1) {
                    prod *= prime[j];
                }
            }
            int mu = 1;
            if((__builtin_popcount(mask)) & 1) mu = mod - 1;

            t1 = (t1 + (mu * powr[i / prod]) % mod) % mod;
            t2 = (t2 + (mu * powr[(i - 1) / prod]) % mod) % mod;

        }

        t1 = (t1 - t2 + mod) % mod;
        curr = (curr + t1) % mod;
        ans = (ans + (curr ^ i)) % mod;
        prev = curr;
        
    }

    cout << ans << "\n";

    return 0;
}