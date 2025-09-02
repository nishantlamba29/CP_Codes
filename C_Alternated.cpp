#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    string s;
    cin >> n >> s;

    vector<int> p1, p2;
    for(int i=0;i<2*n;i++) {
        if(s[i] == 'A') p1.push_back(i);
        else p2.push_back(i);
    }
    int t1 = 0, t2 = 0, t3 = 0, t4 = 0;
    for(int i=0;i<n;i++) {
        t1 += abs(2 * i - p1[i]);
        t3 += abs(2 * i + 1 - p1[i]);
        t2 += abs(2 * i + 1 - p2[i]);
        t4 += abs(2 * i - p2[i]);
    }
    cout << min({t1, t2, t3, t4}) << "\n";

    return 0;
}