#include <bits/stdc++.h>
using namespace std;

const int B = 30;
struct node {
    node *child[2];
    node() {
        child[0] = 0;
        child[1] = 0;
    }

    void insert(int x) {
        node *curr = this;
        for(int i=B-1;i>=0;i--) {
            int xb = (x >> i) & 1;
            if(!curr->child[xb]) curr->child[xb] = new node();
            curr = curr->child[xb];
        }
    }

    int get(int x) {
        node *curr = this;
        int ans = 0;
        for(int i=B-1;i>=0;i--) {
            if(!curr) break;
            int xb = (x >> i) & 1;
            if(curr->child[xb ^ 1]) {
                ans |= (1 << i);
                curr = curr->child[xb ^ 1];
            }
            else {
                curr = curr->child[xb];
            }
        }
        return ans;
    }

};

int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    int ans = 0;
    int pref = 0;

    node *trie = new node();
    trie->insert(pref);

    for(int i=0;i<n;i++) {
        pref ^= v[i];
        ans = max(ans, trie->get(pref));
        trie->insert(pref);
    }

    cout << ans << "\n";


    return 0;
}