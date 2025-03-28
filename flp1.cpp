
#include <bits/stdc++.h>
#include <unordered_map>
#include <queue>
#include <vector>
#include <string>
#include <list>
using namespace std;

template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

map<string, min_heap<string>> g;
list<string> ans;

void dfs(string& str) {
    auto& q = g[str];
    while (!q.empty()) {
        string temp = q.top();
        q.pop();
        dfs(temp);
    }
    ans.push_front(str);
}
int main() {
    int n,k;
    cin>>n>>k;
    for (int i = 0; i < n; i++) {
        string x, y;
        cin >> x >> y;
        g[x].push(y);
    }
    string src = "ABC";
    dfs(src);

    for(auto &i : ans) cout<<i<<" ";
    return 0;
}