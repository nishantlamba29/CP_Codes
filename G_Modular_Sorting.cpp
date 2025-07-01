#include <bits/stdc++.h>
using namespace std;

const int N = 5'000'05;
int v[N], bad[N];
vector<int> factor;

inline void n_lamba_29() {

    int n, m, q;
    cin >> n >> m >> q;

    for(int i=0;i<n;i++) {
        cin >> v[i];
    }

    factor.clear();
    for(int i=2;i*i<=m;i++) {
        if(m % i == 0) {
            factor.push_back(i);
            if(i * i != m) factor.push_back(m / i);
        }
    }

    for(int i=0;i<=m;i++) bad[i] = 0;

    for(auto it : factor) {
        for(int i=0;i<n-1;i++) {
            if(v[i] % it > v[i+1] % it) bad[it]++;
        }
    }

    while(q--) {
        int type;
        cin >> type;
        if(type == 1) {
            int ind, x;
            cin >> ind >> x;
            ind--;
            for(auto it : factor) {
                if(ind != n-1) {
                    if(v[ind] % it > v[ind + 1] % it) bad[it]--;
                    if(x % it > v[ind + 1] % it) bad[it]++;
                }
                if(ind != 0) {
                    if(v[ind] % it < v[ind - 1] % it) bad[it]--;
                    if(x % it < v[ind - 1] % it) bad[it]++;
                }
            }
            v[ind] = x;
        }
        else {
            int k;
            cin >> k;
            int g = __gcd(m, k);
            int max_jump = m / g;
            if(bad[g] < max_jump) cout << "YES\n";
            else cout << "NO\n";
        }
    }


}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int _;
    cin >> _;
    while (_-->0) {
        n_lamba_29();
    }


    return 0;
}