#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    int n = s.size();
    
    int sum = 0;
    int ans = 1;
    for(int i=0;i<n;i++) {
        if(s[i] == 'a') {
            sum++;
        }
        if(s[i] == 'b') {
            ans = (ans * (sum + 1)) % mod;
            sum = 0;
        }
    }
    ans = (ans * (sum + 1)) % mod;
    ans = (ans - 1 + mod) % mod;

    cout << ans << "\n";

    return 0;
}