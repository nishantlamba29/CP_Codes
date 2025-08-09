#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
int n, q;
vector<int> adj[N];
vector<array<int,2>> query[N];
int sz[N], powr[26];
bool ans[N];
string s;

void merge(vector<int> &my, vector<int> &ch) {
    if(my.size() < ch.size()) swap(my, ch);

    int hi = my.size() - 1;
    for(int i=ch.size()-1;i>=0;i--) {
        my[hi] ^= ch[i];
        hi--;
    }
    ch.clear();

}

vector<int> dfs(int node = 1, int p = -1, int d = 1) {
    sz[node] = 1;
    vector<int> my(1, 0);
    for(auto j : adj[node]) {
        if(j != p) {
            vector<int> ch = dfs(j, node, d + 1);
            sz[node] += sz[j];
            ch.push_back(0);
            merge(my, ch);
        }
    }
    int c = s[node] - 'a';
    my[my.size() - 1] = powr[c];
    for(auto [dd, ind] : query[node]) {
        dd -= d;
        if(dd <= 0 || dd >= my.size()) {
            ans[ind] = 1;
            continue;
        }
        int cnt = __builtin_popcount(my[my.size() - dd - 1]);
        if(cnt <= 1) ans[ind] = 1;
    }
    return my;
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    powr[0] = 1;
    for(int i=1;i<26;i++) powr[i] = powr[i-1] * 2;
    cin >> n >> q;
    for(int i=2;i<=n;i++) {
        int p;
        cin >> p;
        adj[p].push_back(i);
        adj[i].push_back(p);
    }
    cin >> s;
    s = '#' + s;

    for(int i=0;i<q;i++) {
        int node, depth;
        cin >> node >> depth;
        query[node].push_back({depth, i});
    }

    dfs();

    for(int i=0;i<q;i++) {
        cout << (ans[i] ? "Yes\n" : "No\n");
    }

    return 0;
}