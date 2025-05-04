#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = (int)1e9 + 7;
const int N = 40000;

int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    vector<int> p;
    for(int i=1;i<=N;i++) {
        string s = to_string(i);
        reverse(s.begin(), s.end());
        int j = stoi(s);
        if(i == j) p.push_back(i);
    }
    
    vector<int> dp(N+1, 0);
    dp[0] = 1;
    for(auto &num : p) {
        for(int i=num;i<=N;i++) {
            dp[i] = (dp[i] + dp[i-num]) % mod;
        }
    }

    int _;
    cin >> _;
    while (_-->0) {
        int n;
        cin >> n;
        cout << dp[n] << "\n";
    }


    return 0;
}