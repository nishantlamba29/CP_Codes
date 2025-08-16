#include <bits/stdc++.h>
using namespace std;

const int M = 1e6 + 5;
int f[M];
int g[M];
vector<bool> isPrime;
vector<int> mu;

void seive() {
    isPrime.resize(M, 1);
    mu.resize(M, 1);
    isPrime[0] = 0;
    isPrime[1] = 0;
    for(int i=2;i<M;i++) {
        if(isPrime[i])
        for(int j=i;j<M;j+=i) {
            if(j > i) isPrime[j] = 0;
            if(j % (i * i) == 0) mu[j] = 0;
            mu[j] *= -1;
        }
    }
}

inline void n_lamba_29() {

    int n, m;
    cin >> n >> m;
    for(int i=0;i<=m;i++) {
        f[i] = 0;
        g[i] = 0;
    }
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin >> v[i];
        f[v[i]]++;
    }

    for(int i=1;i<=m;i++) {
        for(int j=i;j<=m;j+=i) {
            g[i] += f[j];
        }
    }

    vector<int> ans(n);
    for(int i=0;i<n;i++) {
        for(int j=1;j*j <= v[i]; j++) {
            if(v[i] % j == 0) {
                int ss = v[i] / j;
                ans[i] += mu[j] * g[j];
                if(ss != j) ans[i] += mu[ss] * g[ss];
            }
        }
        // gcd(ai, aj) = 1 when ai = ai = 1 then counted twice
        if(v[i] == 1) ans[i]--;
    }

    int p = -1, q, r = -1, s;
    int m1 = 0, m2 = M;
    for(int i=0;i<n;i++) {
        if(ans[i] > m1) {
            m1 = ans[i];
            p = i;
        }
    }
    if(m1 == 0) {
        cout << "0\n";
        return;
    }
    for(int i=0;i<n;i++) {
        if(i != p && gcd(v[p], v[i]) == 1) {
            if(m2 > ans[i]) {
                m2 = ans[i];
                q = i;
            }
        }
    }
    for(int i=0;i<n;i++) {
        if(i != p && gcd(v[p], v[i]) == 1) ans[i]--;
        if(i != q && gcd(v[q], v[i]) == 1) ans[i]--;
    }
    ans[p] = 0;
    for(int i=0;i<n;i++) {
        if(i != q && ans[i] > 0) {
            r = i;
            break;
        }
    }
    if(r == -1) {
        cout << "0\n";
        return;
    }
    for(int i=0;i<n;i++) {
        if(i != p && i != q && i != r && gcd(v[r], v[i]) == 1) {
            s = i;
            break;
        }
    }

    cout << p + 1 << " "  << q + 1 << " " << r + 1 << " " << s + 1 << "\n";

}


int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    seive();

    int _;
    cin >> _;
    while (_-->0) {
        n_lamba_29();
    }


    return 0;
}