#include <bits/stdc++.h>
using namespace std;

int n, s;
vector<int> k;
vector<vector<int>> v;
vector<vector<int>> t(n);

int get_lead(int a, int b) {
    set<int> st;
    for(int i=0;i<t[a].size();i++) st.insert(t[a][i]);
    for(int i=0;i<t[b].size();i++) st.insert(t[b][i]);

    vector<int> d;
    int curr = 0, prev = 0;
    int vA = 0, vB = 0;
    int pA = 0, pB = 0; // current segment
    for(auto it : st) {
        curr = it;
        int dist = (vA - vB) * (curr - prev);
        d.push_back(dist);
        prev = curr;

        while(pA + 1 < v[a].size() && t[a][pA+1] <= curr) pA++;
        while(pB + 1 < v[b].size() && t[b][pB+1] <= curr) pB++;

        vA = v[a][pA];
        vB = v[b][pB];

    }

    for(int i=1;i<d.size();i++) d[i] += d[i-1];

    int ans = 0;
    int last_sign = 0;
    for(int i=0;i<d.size();i++) {
        int curr_sign = (d[i] > 0) - (d[i] < 0);
        if(curr_sign == 0) continue;
        if(last_sign != 0 && curr_sign != last_sign) {
            ans++;
        }
        last_sign = curr_sign;
    }

    return ans;

}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, s;
    cin >> n >> s;
    k.resize(n);
    v.resize(n);
    t.resize(n);
    for(int i=0;i<n;i++) {
        cin >> k[i];
        v[i].resize(k[i]);
        t[i].resize(k[i]+1);
        int pre = 0;
        for(int j=0;j<k[i];j++) {
            int speed, tim;
            cin >> speed >> tim;
            t[i][j] = pre;
            v[i][j] = speed;
            pre += tim;
        }
        t[i][k[i]] = pre;
    }

    int ans = 0;
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            ans += get_lead(i, j);
        }
    }

    cout << ans;

    return 0;
}