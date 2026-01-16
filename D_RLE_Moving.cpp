#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    map<char, int> mp;
    mp['L'] = 0, mp['U'] = 1, mp['R'] = 2, mp['D'] = 3;
    
    int x0, y0, x1, y1;
    cin >> x0 >> y0 >> x1 >> y1;
    int n, m, L;
    cin >> n >> m >> L;

    vector<pair<int, int>> v1(m), v2(L);
    for(int i=0;i<m;i++) {
        char ch;
        int val;
        cin >> ch >> val;
        v1[i] = {mp[ch], val};
    }

    for(int i=0;i<L;i++) {
        char ch;
        int val;
        cin >> ch >> val;
        v2[i] = {mp[ch], val};
    }

    vector<int> t = {0};
    vector<pair<int, int>> t1, t2;
    for(int i=0;i<m;i++) {
        int j = i, sum = 0;
        while(j < m && v1[i].first == v1[j].first) {
            sum += v1[j].second;
            j++;
        }
        t1.push_back({v1[i].first, sum});
        t.push_back(t.back() + sum);
        i = j - 1;
    }

    int prev = 0;
    for(int i=0;i<L;i++) {
        int j = i, sum = 0;
        while(j < L && v2[i].first == v2[j].first) {
            sum += v2[j].second;
            j++;
        }
        t2.push_back({v2[i].first, sum});
        t.push_back(prev + sum);
        prev += sum;
        i = j - 1;
    }


    sort(t.begin(), t.end());

    int ans = 0;

    int i = 0, j = 0;
    int p1 = 0, p2 = 0;
    for(int tim : t) {

        while(i < t1.size()) {
            if(p1 > tim) break;
            p1 += t1[i].second;
        }

        while(j < t2.size()) {
            
        }


    }

    cout << ans << "\n";

    return 0;
}