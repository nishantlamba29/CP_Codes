#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    if(k == 1) {
        cout << *min_element(v.begin(), v.end());
    }
    else if(k >= 3) {
        cout << *max_element(v.begin(), v.end());
    }
    else {
        vector<int> pre(n);
        pre[0] = v[0];
        for(int i=1;i<n;i++) pre[i] = min(pre[i-1], v[i]);
        vector<int> suff(n);
        suff[n-1] = v[n-1];
        for(int i=n-2;i>=0;i--) suff[i] = min(suff[i+1], v[i]);

        int ans = (int) -1e9;
        for(int i=0;i<n-1;i++) {
            ans = max({ans, pre[i], suff[i+1]});
        }
        cout << ans;
    }

    return 0;
}