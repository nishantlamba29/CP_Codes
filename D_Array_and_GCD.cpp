#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<bool> isPrime;
const int N = 6e6;
vector<int> prime;
void seive(int N){ isPrime.resize(N+1,1); isPrime[0]=0; isPrime[1]=0;
    for(int i=2;i<=N;i++) if(isPrime[i]) for(int j=i*i;j<=N;j+=i) isPrime[j] = 0;
}

inline void n_lamba_29() {

    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    int s1 = accumulate(prime.begin(), prime.begin() + n, 0LL);
    int s2 = accumulate(v.begin(), v.end(), 0LL);
    if(s1 <= s2) cout << 0 << "\n";
    else {
        sort(v.rbegin(), v.rend());
        for(int i=n-1;i>=0;i--) {
            s1 -= prime[i];
            s2 -= v[i];
            if(s1 <= s2) {
                cout << n - i << "\n";
                break;
            }   
        }
    }

}


int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    seive(N);
    for(int i=2;i<=N;i++){
        if(isPrime[i]) prime.push_back(i);
    }
    int _;
    cin >> _;
    while (_-->0) {
        n_lamba_29();
    }


    return 0;
}