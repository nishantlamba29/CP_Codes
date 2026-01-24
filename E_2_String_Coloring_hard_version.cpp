#include <bits/stdc++.h>
using namespace std;
// First you make it work, then you can always make it beautiful
// LDS Longest decreasing subsequence

void solve() {
    int n;
    string s;
    cin >> n >> s;

    string t = s;
    sort(t.begin(), t.end());
    vector<vector<int>> pos(26);
    for(int i=0;i<n;i++) {
        pos[t[i] - 'a'].push_back(i);
    }
    vector<int> ptr(26);
    vector<int> p(n);

    for(int i=0;i<n;i++) {
        int x = s[i] - 'a';
        p[i] = pos[x][ptr[x]++];
    }
    // p[i] = final position of s[i] in the sorted string

    vector<int> color(n, -1);

    int k = 0;
    set<pair<int, int>> temp; // piles
    // all the elements of LDS must be differently colored 
    for(int i=0;i<n;i++) {
        auto it = temp.lower_bound(make_pair(p[i], INT_MIN));
        if(it == temp.begin()) {
            k++;
            temp.insert({p[i], k});
            color[i] = k;
        }
        else {
            it--;
            color[i] = it->second;
            temp.insert({p[i], it->second});
            temp.erase(it);
        }
    }
    
    cout << k << "\n"; // length of LDS in p
    for(int i=0;i<n;i++) cout << color[i] << " ";
    cout << "\n";

}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // int _;
    // cin >> _;
    // while (_-->0) {
        solve();
    // }

    return 0;
}