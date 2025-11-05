#include <bits/stdc++.h>
using namespace std;
#define int long long
map<int, int> F;

int f(int n) {
    if(n <= 0) return 0;
    if(F.find(n) != F.end()) return F[n];
    int msb = 31 - __builtin_clz(n);
    int t1 = (1 << msb);
    return F[n] = f(t1 - 1) + f(n - t1) + t1;

}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int _;
    cin >> _;
    while (_-->0) {
        int n;
        cin >> n;

        cout << f(n) + ((n & (n - 1)) == 0) - 1 << "\n";

    }


    return 0;
}