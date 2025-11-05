#include <bits/stdc++.h>
using namespace std;

int sz;
int basis[30];
void insert(int mask) {
    for(int i=29;i>=0;i--) {
        if(mask >> i & 1) {
            if(!basis[i]) {
                basis[i] = mask;
                sz++;
                return;
            }
            mask ^= basis[i];
        }
    }
}

void dfs(int curr, int ind, int taken, int limit, vector<int> &ans) {

    if(taken >= limit) {
        ans.push_back(curr);
        return;
    }

    if(basis[ind]) {
        dfs(curr ^ basis[ind], ind + 1, taken * 2, limit, ans);
        dfs(curr, ind + 1, taken * 2, limit, ans);
    }
    else {
        dfs(curr, ind + 1, taken, limit, ans);
    }
}

int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin >> v[i];
        insert(v[i]);
    }

    // total uniques = 2^sz
    // 2^(n - sz) times these uniques appears 
    // thus making 2^n all xors

    // we need to find these 2^sz then writing each 2^(n-sz) times till k
    // all these 2*sz can be generated through dfs or bfs

    // i need  ceil(k / (2 ^ (n - sz))) 
    // int repeat = min(k, 2 ^ (n - sz));
    int repeat = 1 << (min(19, n - sz));

    vector<int> ans;
    dfs(0, 0, 1, k, ans);
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());

    for(auto it : ans) {
        for(int j=0;j<repeat && k > 0;j++, k--) {
            cout << it << " ";
        }
    }

    

    return 0;
}