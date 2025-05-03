#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    int ans = 0;
    for(int i=0;i<n;i++) {
        int a = s1[i] - '0', b = s2[i] - '0';
        ans += min(abs(a - b), min(abs(10 - a + b), abs(10 - b + a)));
    }
    cout << ans;
    return 0;
}