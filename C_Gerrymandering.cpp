#include <bits/stdc++.h>
using namespace std;

bool check(pair<int,int> a, pair<int,int> b, pair<int,int> c, vector<string> &v) {
    int cnt = 0;
    if(v[a.first][a.second] == 'A') cnt++;
    if(v[b.first][b.second] == 'A') cnt++;
    if(v[c.first][c.second] == 'A') cnt++;
    
    return cnt >= 2;
}

map<pair<int,int>, int> mp;


int rec(int i, int j, vector<string> &v) {
    int n = v[0].size();
    if(i == n || j == n) return 0;
    
    if(mp.find({i, j}) != mp.end()) return mp[{i, j}];
    int op1 = 0;
    if(i+2 < n && j+2 < n)
    op1 = check({0, i}, {0, i+1}, {0, i+2}, v) + check({1, j}, {1, j+1}, {1, j+2}, v) + rec(i+3, j+3, v);
    
    int op2 = 0;
    if(i == j) {
        if(i+1 < n)
        op2 = check({0, i}, {0, i+1}, {1, j}, v) + rec(i+2, j+1, v);
        if(j+1 < n)
        op2 = max(op2, check({0, i}, {1, j}, {1, j+1}, v) + rec(i+1, j+2, v));
    }
    int op3 = 0;
    if(i == j+1) {
        if(j+1 < n)
        op3 = check({0, i}, {1, j}, {1, j+1}, v) + rec(i+1, j+2, v);
    }
    int op4 = 0;
    if(i == j-1) {
        if(i+1 < n)
        op4 = check({0, i}, {0, i+1}, {1, j}, v) + rec(i+2, j+1, v);
    }
    
    return mp[{i, j}] = max({op1, op2, op3, op4});
    
}

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--) {
	    mp.clear();
    	int n;
    	cin >> n;
    	vector<string> v(2);
    	for(int i=0;i<2;i++) cin >> v[i];
    	
    	int ans = rec(0, 0, v);
    	cout << ans << "\n";
	}
}
