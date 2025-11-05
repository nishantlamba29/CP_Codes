#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;
vector<int> arr;
const int B = 20;

struct node {
    node *child[2];
    int freq;
    node() {
        child[0] = child[1] = 0;
        freq = 0;
    }
    void insert(int x) {
        node *cur = this;
        cur->freq += 1;
        for (int b = B - 1; b >= 0; --b) {
            int bit = (x >> b) & 1;
            if (!cur->child[bit]) cur->child[bit] = new node();
            cur = cur->child[bit];
            cur->freq += 1;
        }
    }
    int count_le(int x, int limit) {
        node *cur = this;
        int res = 0;
        for (int b = B - 1; b >= 0; --b) {
            if (!cur) break; 
            int xb = (x >> b) & 1;
            int kb = (limit >> b) & 1;

            if (kb == 1) {
                if (cur->child[xb]) {
                    res += cur->child[xb]->freq;
                }
                cur = cur->child[xb ^ 1];
            } else {
                cur = cur->child[xb];
            }
        }
        if (cur) res += cur->freq;
        return res;
    }

};

int count_max(int l, int mid, int r) {
    int n1 = mid - l + 1;
    int n2 = r - mid;

    vector<int> suff(n1), pre(n2);
    suff[n1 - 1] = arr[mid];
    for(int i=n1-2;i>=0;i--) {
        suff[i] = max(suff[i+1], arr[l+i]);
    }
    pre[0] = arr[mid + 1];
    for(int i=1;i<n2;i++) {
        pre[i] = max(pre[i-1], arr[mid + 1 + i]);
    }

    vector<array<int, 3>> Events;

    for(int i=0;i<n1;i++) {
        Events.push_back({suff[i], arr[l + i], 0});
    }
    for(int i=0;i<n2;i++) {
        Events.push_back({pre[i], arr[mid + 1 + i], 1});
    }
    sort(Events.begin(), Events.end());

    int cnt = 0;
    node *left = new node(); // l to mid part
    node *right = new node(); // mid + 1 to r

    for(auto &[limit, val, type] : Events) {
        if(type == 0) {
            cnt += right->count_le(val, limit);
            left->insert(val);
        }
        else {
            cnt += left->count_le(val, limit);
            right->insert(val);
        }
    }

    return cnt;

}

int count_min(int l, int mid, int r) {
    int n1 = mid - l + 1;
    int n2 = r - mid;

    vector<int> suff(n1), pre(n2);
    suff[n1 - 1] = arr[mid];
    for(int i=n1-2;i>=0;i--) {
        suff[i] = min(suff[i+1], arr[l+i]);
    }
    pre[0] = arr[mid + 1];
    for(int i=1;i<n2;i++) {
        pre[i] = min(pre[i-1], arr[mid + 1 + i]);
    }

    vector<array<int, 3>> Events;

    for(int i=0;i<n1;i++) {
        Events.push_back({suff[i], arr[l + i], 0});
    }
    for(int i=0;i<n2;i++) {
        Events.push_back({pre[i], arr[mid + 1 + i], 1});
    }
    sort(Events.rbegin(), Events.rend());

    int cnt = 0;
    node *left = new node();
    node *right = new node();

    for(auto &[limit, val,type] : Events) {
        if(type == 0) {
            cnt += right->count_le(val, limit - 1);
            left->insert(val);
        }
        else {
            cnt += left->count_le(val, limit - 1);
            right->insert(val);
        }
    }

    return cnt;
}

int ans;
void rec(int l, int r) {
    if(l == r) {
        if(arr[l] == 0) ans++;
        return;
    }
    int mid = (l + r) >> 1;
    rec(l, mid);
    rec(mid + 1, r);
    
    // mini <= temp <= maxi
    // t1 -> count of all such <= maxi
    // t2 -> count of all such < mini
    // so ans = t1 - t2;
    int t1 = count_max(l, mid, r);
    int t2 = count_min(l, mid, r);

    ans += t1 - t2;
    
}

int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    arr.resize(n);
    for(int i=0;i<n;i++) cin >> arr[i];

    ans = 0;
    rec(0, n - 1);

    cout << ans << "\n";

    return 0;
}
