#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5;
vector<int> adj[N];
int val[N];

void solve() {
    int n;
    cin >> n;
    for(int i=0;i<=n;i++) {
        adj[i].clear();
    }

    vector<int> missing(n + 1, 1), inv(n + 1), prefix(n + 1);
    vector<pair<int, int>> help(n + 1);
    
    for(int i=1;i<=n;i++) {
        cin >> val[i];
        missing[val[i]] = 0;
        inv[val[i]] = i;
    }
    for(int i=1;i<=n;i++) prefix[i] = prefix[i-1] + missing[i];
    
    for(int i=0;i<n-1;i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        help[u].first = max(help[u].first, val[v]);
        if(val[v] == 0) {
            help[u].second++;
        }
        help[v].first = max(help[v].first, val[u]);
        if(val[u] == 0) {
            help[v].second++;
        }
    }
    vector<pair<int, int>> help1;
    for(int i=1;i<=n;i++) {
        if(val[i] == 0) {
            help1.push_back(help[i]);
        }
    }
    sort(help1.begin(), help1.end());
    int ptr = 0;
    set<int> st;
    
    for(int i=1;i<=n;i++) {
        int node = inv[i];
        if(missing[i]) {
            while(ptr < help1.size() && help1[ptr].first < i) {
                st.insert(help1[ptr].second);
                ptr++;
            }
            if(st.empty()) continue;
            int t1 = prefix[i-1];
            auto it = st.upper_bound(t1);
            if(it == st.begin()) continue;
            
            cout << i << "\n";
            return;
            
        }
        else {
            int maxi = help[node].first;
            int cnt = help[node].second;
            if(maxi > i) continue;
            if(prefix[i-1] >= cnt) {
                cout << i << "\n";
                return;
            }
        }
    }
    
}

int32_t main() {
	// your code goes here
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t;
	cin >> t;
	while(t--) {
	    solve();
	}
    return 0;
}