#include <bits/stdc++.h>
using namespace std;
// First you make it work, then you can always make it beautiful
struct manacher {
    int n;
    string t;
    vector<int> p;
    void build(string s) {
        t.clear();
        for(auto ch : s) {
            t += '#';
            t += ch;
        }
        t += '#';
        compute(t);
    }

    void compute(string t) {
        n = t.size();
        p.assign(n, 1);
        int l = 1, r = 1;
        for(int i=1;i<n;i++) {
            // mirror pos of i in l to r is l+r-i
            p[i] = max(1, min(r - i, p[l + r - i]));
            while(i + p[i] < n && i - p[i] >= 0 && t[i - p[i]] == t[i + p[i]]) {
                p[i]++;
            }
            if(i + p[i] > r) {
                l = i - p[i];
                r = i + p[i];
            }
        }
    }

    // for even length palindrome it check (i-1, i) as centre
    int getlen(int pos, bool isOdd) {
        int ind = 2 * pos + 1 + (!isOdd);
        return p[ind] - 1;
    }

    bool ispal(int l, int r) {
        int len = r - l + 1;
        return (len <= getlen((l + r) / 2, (len & 1)));
    }
};

void solve() {
    string s;
    cin >> s;

    int n = s.size();
    manacher m;
    m.build(s);

    string ans;
    for(int i=n-1;i>=0;i--) {
        if(m.ispal(0, i)) {
            ans = s.substr(0, i + 1);
            break;
        }
    }
    for(int i=0;i<n;i++) {
        if(m.ispal(i, n - 1) && ans.size() < n - i) {
            ans = s.substr(i);
            break;
        }
    }

    int l = 0, r = n - 1;
    while(l < n/2 && s[l] == s[n-l-1]) l++;
    if(2*l > n) {
        cout << s << "\n";
        return;
    }
    int ptr = -1;
    for(int i=l;i<n-l-1;i++) {
        if(m.ispal(l, i)) {
            ptr = i;
        }
    }
    if(ptr != -1 && ptr + l + 1 > ans.size()) {
        ans = s.substr(0, ptr + 1) + s.substr(n-l);
    }
    ptr = -1;
    for(int i=n-l-1;i>l;i--) {
        if(m.ispal(i, n - l - 1)) {
            ptr = i;
        }
    }
    if(ptr != - 1 && l + n - ptr > ans.size()) {
        ans = s.substr(0, l) + s.substr(ptr);
    }

    cout << ans << "\n";

}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int _;
    cin >> _;
    while (_-->0) {
        solve();
    }

    return 0;
}