#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;

    int n = (int)s.size();
    int maxi = 0, cnt = 0;


    vector<int> dp(n);
    stack<int> st;

    for(int i=0;i<n;i++) {
        if(s[i] == '(') st.push(i);
        else if(!st.empty()) {
            int j = st.top();
            st.pop();
            dp[i] = i - j + 1 + (j > 0 ? dp[j-1] : 0);
        }
        if(dp[i] > maxi) {
            maxi = dp[i];
            cnt = 1;
        }
        else if(dp[i] == maxi) {
            cnt++;
        }
    }
    
    if(maxi == 0) cnt = 1;

    cout << maxi << " " << cnt << "\n";

    return 0;
}