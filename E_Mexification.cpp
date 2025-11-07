#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void n_lamba_29() {

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    sort(v.begin(), v.end());

    vector<int> prev;
    vector<int> temp;

    while(k-- && v != prev) {

        temp = prev;
        prev = v;

        vector<int> cnt(n + 1, 0);
        for(int ele : v) cnt[ele]++;

        int mex = 0;
        while(mex <= n && cnt[mex]) mex++;
        
        vector<int> v2;
        int mm = 0;
        for(int ele : v) {
            if(cnt[ele] > 1) {
                v2.push_back(mex);
            }
            else v2.push_back(mm);
            if(ele == mm) mm++;
        }
        sort(v2.begin(), v2.end());

        v.swap(v2);
        if(temp == v) {
            k &= 1;
        }

    }

    int ans = accumulate(v.begin(), v.end(), 0LL);
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