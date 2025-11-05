#include <bits/stdc++.h>
using namespace std;

inline void n_lamba_29() {
    int n;
    string s;
    cin >> n >> s;
    
    vector<int> freq(26, 0);
    for(auto ch : s) freq[ch - 'a']++;
    vector<vector<int>> pos(26);
    for(int i=0;i<n;i++) {
        pos[s[i] - 'a'].push_back(i);
    }

    // assuming that string has i distinct characters only
    int best = -1; // maximum matchings
    string res = "";
    for(int i=1;i<=26;i++) {
        if(n % i != 0) continue;
        int req = n / i;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // cnt denotes itni positions to same rhegi
        int cnt = 0;
        for(int j=0;j<26;j++) {
            cnt += min(freq[j], req);
            pq.push({freq[j], j});
            if(pq.size() > i) {
                cnt -= min(pq.top().first, req);
                pq.pop();
            }
        }
        if(cnt <= best) continue;
        best = cnt;
        res = string(n, ' ');
        vector<int> temp;
        while(pq.size()) {
            int it = pq.top().second;
            pq.pop();
            for(int j=0;j<req;j++) {
                if(j < pos[it].size()) {
                    // no change s wali position pe jo tha vhi res m h
                    res[pos[it][j]] = (char)('a' + it);
                }
                else {
                    // it add krna pdega , as req > freq[it]
                    temp.push_back(it);
                }
            }
        }
        for(auto &ch : res) {
            if(ch == ' ') {
                ch = (char)('a' + temp.back());
                temp.pop_back();
            }
        }
    }

    cout << n - best << "\n";
    cout << res << "\n";

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