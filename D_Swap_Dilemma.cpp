#include <bits/stdc++.h>
using namespace std;

int64_t merge(vector<int> &v, int l, int mid, int r) {
    int n1 = mid - l + 1, n2 = r - mid;
    vector<int> left, right;
    for(int i=0;i<n1;i++) {
        left.push_back(v[l+i]);
    }
    for(int i=0;i<n2;i++) {
        right.push_back(v[mid + i + 1]);
    }

    int i = 0, j = 0, k = l;
    int64_t res = 0;
    while(i < n1 && j < n2) {
        if(left[i] <= right[j]) {
            v[k++] = left[i++];
        }
        else {
            v[k++] = right[j++];
            res += (n1 - i);
        }
    }
    while(i < n1) {
        v[k++] = left[i++];
    }
    while(j < n2) {
        v[k++] = right[j++];
    }

    return res;
}

int64_t countInv(vector<int> &v, int l, int r) {
    int64_t res = 0;
    if(l >= r) return 0;
    int mid = (l + r) >> 1LL;
    res += countInv(v, l, mid);
    res += countInv(v, mid + 1, r);
    res += merge(v, l, mid, r);
    return res;
}

int parity(vector<int> &v) {
    int64_t cnt = countInv(v, 0, (int)v.size() - 1);
    return cnt % 2;
}

inline void n_lamba_29() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];

    int p1 = parity(a), p2 = parity(b);
    
    if(a == b) {
        if(p1 == p2) cout << "YES\n";
        else cout << "NO\n";
    }
    else cout << "NO\n";

}


int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int _;
    cin >> _;
    while (_-->0) {
        n_lamba_29();
    }


    return 0;
}