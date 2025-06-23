/*

given two arrays a and b of size n and m
n, m <= 1e5
a[i], b[i] <= 1e8

score of a number is defined as 2 if num > d
1 if num <= d
0 <= d <= 1e9

where d is any number 

Sa be score of all elements of array a abd Sb for array b
we have to maximise the value of Sa - Sb (not absolute value)

this will be maximised at many d values , print the minimum d among all such d's

Example
a = [1, 2, 3]
b = [5, 8]
at d = 0   Sa = 6 , Sb = 4 and max value is 2


*/



#include <bits/stdc++.h>
using namespace std;
#define int long long

int get_score(vector<int> &a, vector<int> &b) {
    int ans = 0;
    for(auto i : a) {
        if(i > 0) ans += 2;
        else ans += 1;
    }
    for(auto i : b) {
        if(i > 0) ans -= 2;
        else ans -= 1;
    }
    return ans;
}

void solve() {

    int n;
    vector<int> a(n);
    map<int,int> mp;
    multiset<pair<int,int>> st;
    for(int i=0;i<n;i++) {
        cin >> a[i];
        mp[a[i]]++;
        st.insert({a[i], 1});
    }
    int m;
    cin >> m;
    vector<int> b(m);
    for(int i=0;i<m;i++) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for(int i=0;i<m;i++) {
        if(mp[b[i]] > 0) {
            mp[b[i]]--;
            st.erase(st.find({b[i], 1}));
        }
        else st.insert({b[i], 2});
    }
    vector<pair<int,int>> v2(st.begin(), st.end());

    int sz = v2.size();
    vector<pair<int,int>> v;
    for(int i=0;i<sz;i++) {
        v.push_back(v2[i]);
        if(i+1 < sz && v2[i+1].first - v2[i].first > 1) v.push_back({v2[i].first + 1, -1}); 
    }
    sz = v.size();

    vector<int> pre1(sz), pre2(sz);
    if(v[0].second == 1) pre1[0] = 1;
    else pre2[0] = 1;
    for(int i=1;i<sz;i++) {
        if(v[i].second == 1) {
            pre1[i] = 1 + pre1[i-1];
            pre2[i] = pre2[i-1];
        }
        else if(v[i].second == 2) {
            pre2[i] = 1 + pre2[i-1];
            pre1[i] = pre1[i-1];
        }
        else {
            pre1[i] = pre1[i-1];
            pre2[i] = pre2[i-1];
        }
    }

    int zero = get_score(a, b);
    int maxi = 0;
    for(int i=0;i<sz;i++) {
        int c1 = pre1[i], c2 = pre2[i];
        int c3 = pre1[sz-1] - pre1[i], c4 = pre2[sz-1] - pre2[i];
        maxi = max(maxi, c1 - c2 + 2 * (c3 - c4));
    }

    int ind = -1;
    for(int i=0;i<sz;i++) {
        int c1 = pre1[i], c2 = pre2[i];
        int c3 = pre1[sz-1] - pre1[i], c4 = pre2[sz-1] - pre2[i];
        int score = c1 - c2 + 2 * (c3 - c4);
        if(score == maxi) {
            ind = i;
            break;
        }
    }

    if(zero == maxi) cout << "0\n";
    else cout << v[ind].first << "\n";

}


int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    for(int i=1;i<=t;i++) {
        cout << "#" << t << " ";
        solve();
    }


    return 0;
}