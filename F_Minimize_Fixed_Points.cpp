#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5;
vector<int> isPrime;
void seive() {
    isPrime.resize(N+1, 1);
    isPrime[0] = 0; isPrime[1] = 0;
    for(int i=2;i<=N;i++) {
        if(isPrime[i]) {
            for(int j=i*i;j<=N;j+=i) {
                isPrime[j] = 0;
            }
        }
    }
}

inline void n_lamba_29() {

    int n;
    cin >> n;
    vector<int> ans(n+1, -1);
    ans[1] = 1;
    for(int p=n;p>1;p--) {
        if(isPrime[p]) {
            int prev = p;
            for(int j=2*p;j<=n;j+=p) {
                if(ans[j] != -1) continue;
                ans[j] = prev;
                prev = j;
            }
            ans[p] = prev;
        }
    }

    for(int i=1;i<=n;i++) cout << ans[i] << " ";
    cout << "\n";

}


int32_t main(){
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