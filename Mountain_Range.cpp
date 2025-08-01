#include <bits/stdc++.h>
using namespace std;
 
class SegTree {
private:
    int len;
    vector<int> t, unprop;
    vector<bool> isLazy;
 
    void apply(int v, int tl, int tr, int val) {
        if(tl != tr) {
            isLazy[v] = 1;
            unprop[v] = max(unprop[v], val);
        }
        t[v] = max(t[v], val);
    }
 
    void push_down(int v, int tl, int tr) {
        if(!isLazy[v]) return;
        isLazy[v] = 0;
        int tm = (tl + tr) >> 1;
        apply(v << 1, tl, tm, unprop[v]);
        apply(v << 1 | 1, tm + 1, tr, unprop[v]);
        unprop[v] = 0;
    }
    
    void build(vector<int> &a, int v, int tl, int tr) {
        if(tl == tr) {
            t[v] = a[tl];
            return;
        }
        int tm = (tl + tr) >> 1;
        build(a, v << 1, tl, tm);
        build(a, v << 1 | 1, tm + 1, tr);
        t[v] = max(t[v << 1], t[v << 1 | 1]);
    }
 
    void update(int v, int tl, int tr, int l, int r, int val) {
        if(r < tl || l > tr) return;
        if(l <= tl && tr <= r) {
            apply(v, tl, tr, val);
            return;
        }
        push_down(v, tl, tr);
        int tm = (tl + tr) >> 1;
        update(v << 1, tl, tm, l, r, val);
        update(v << 1 | 1, tm + 1, tr, l, r, val);
        t[v] = max(t[v << 1], t[v << 1 | 1]);
    }
    
    int query(int v, int tl, int tr, int l, int r) {
        if(r < tl || l > tr) return 0;
        if(l <= tl && tr <= r) {
            return t[v];
        }
        push_down(v, tl, tr);
        int tm = (tl + tr) >> 1;
        int left = query(v << 1, tl, tm, l, r);
        int right = query(v << 1 | 1, tm + 1, tr, l, r);
        return max(left, right);
    }
    
public:
    SegTree(int _n) {
        len = _n;
        t.resize(4 * len);
        unprop.resize(4 * len);
        isLazy.resize(4 * len);
    }
    void build(vector<int> &a) {
        build(a, 1, 0, len - 1);
    }
    void update(int l, int r, int val) {
        if(l > r) return;
        update(1, 0, len - 1, l, r, val);
    }
    int query(int l, int r) {
        return query(1, 0, len - 1, l, r);
    }
};
 
int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
 
    int n;
    cin >> n;
    vector<pair<int,int>> h(n);
    for(int i=0;i<n;i++) {
        cin >> h[i].first;
        h[i].second = i;
    }
    vector<int> nge(n, n), pge(n, -1);
    stack<pair<int,int>>st;
    st.push({INT_MAX,n});
    for(int i=n-1;i>=0;i--){
        while(h[i].first>st.top().first){
            st.pop();
        }
        nge[i]=st.top().second;
        st.push({h[i].first,i});
    }
    while(!st.empty()){
        st.pop();
    }
    st.push({INT_MAX,-1});
    for(int i=0;i<n;i++){
        while(h[i].first>st.top().first){
            st.pop();
        }
        pge[i]=st.top().second;
        st.push({h[i].first,i});
    }

 
    vector<int> dp(n);
    sort(h.rbegin(), h.rend());
 
    for(int i=0;i<n;i++) {
        if(h[i].first == h[0].first) dp[h[i].second] = 1;
    }
 
    SegTree sg(n);
    for(int i=0;i<n;i++) {
        sg.update(i, i, 1);
    }
 
    for(int i=0;i<n;i++) {
        int curr = h[i].second;
        int next = nge[curr];
        int prev = pge[curr];
        dp[curr] = sg.query(curr, curr);
        sg.update(curr + 1, next - 1, dp[curr] + 1);
        sg.update(prev + 1, curr - 1, dp[curr] + 1);
    }
 
    int ans = 0;
    for(int i=0;i<n;i++) {
        ans = max(ans, sg.query(i, i));
    }
 
    cout << ans << "\n";
    
 
 
    return 0;
}
