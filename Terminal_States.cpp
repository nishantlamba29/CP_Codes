#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

class Fenwick{
    public:
    int n;
    vector<int> bit;
    Fenwick(int n) {
        this->n = n;
        bit.resize(n + 1);
    }
    int query(int ind) {
        int res = 0;
        while(ind) {
            res += bit[ind];
            ind -= ind & -ind;
        }
        return res;
    }
    void update(int id, int val) {
        while(id <= n) {
            bit[id] += val;
            id += id & -id;
        }
    }
};
/*
dividing the array in partitions
3214 | 9765 | .. | ..
these partitions are independent i.e. no inversions among them
as max of first partition < min of other partition
and each individual partition after applying given operation can 
be reduced to any increasing subsequence
so multiplying count of all such subsequences

DOUBT !!!
3214 | 9765 | .. | ..
we taking only pre < suff (prefix max < suffix min)
how sure that it is only min or max of that partition
since minimum is greater than maximum of prefix means that all elements contributing 
in max are from that segment only



*/

void solve() {
    int n;
    cin >> n;
    vector<int> v(n+1);
    for(int i=0;i<n;i++) cin >> v[i+1];
    
    vector<int> pre(n + 1), suff(n + 2);

    for(int i=1;i<=n;i++) pre[i] = max(pre[i-1], v[i]);
    suff[n] = v[n];
    for(int i=n-1;i>0;i--) suff[i] = min(suff[i+1], v[i]);
    
    vector<int> dp(n + 1);
    Fenwick f(n + 1);
    
    vector<vector<int>> temp;
    vector<int> t1;
    for(int i=1;i<=n;i++) {
        t1.push_back(v[i]);
        if(pre[i] < suff[i+1]) {
            temp.push_back(t1);
            t1.clear();
        }
    }
    if(!t1.empty()) temp.push_back(t1);
    
    
    int res = 1;
    for(auto arr : temp) {
            
        int ans = 0;
        for(auto ele : arr) {
            int sum = f.query(ele);
            dp[ele] = (1 + sum) % mod;
            f.update(ele, dp[ele]);
            (ans += dp[ele]) %= mod;
        }
        
        for(auto ele : arr) {
            f.update(ele, -dp[ele]);
            dp[ele] = 0;
        }
        
        res = (res * ans) % mod;
        
    }
    
    cout << res << "\n";
    
    
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
