#include <bits/stdc++.h>
using namespace std;
#define int long long

int rec(int n) {

    if(n == 0) return 0;
    if(n == 1) {
        return 3;
    }

    int y = 1;
    int prod = 3;
    while(prod < n) {
        prod *= 3;
        y++;
    }
    if(prod > n) {
        prod /= 3;
        y--;
    }

    int ans = (int)pow(3, y + 1) + y * (int)pow(3, y - 1);
    ans += rec(n - prod);

    return ans;



}

inline void n_lamba_29() {

    int n;
    cin >> n;

    int ans = rec(n);
    cout << ans << "\n";


}


int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int _;
    cin >> _;
    while (_-->0) {
        n_lamba_29();
    }


    return 0;
}