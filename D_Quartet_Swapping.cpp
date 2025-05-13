#include <bits/stdc++.h>
using namespace std;

template <typename T>
ostream& operator<<(ostream& out, const vector<T>& v) {
    for (size_t i = 0; i < v.size(); i++) {
        out << v[i] << " ";
    }
    return out;
}

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
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    vector<int> t1, t2;
    for(int i=0;i<n;i++) {
        if((i+1) % 2 == 1) t1.push_back(v[i]);
        else t2.push_back(v[i]);
    }

    int n1 = t1.size(), n2 = t2.size();
    int p1 = parity(t1), p2 = parity(t2);

    if(p1 == p2) {
        int ptr1 = 0, ptr2 = 0;
        for(int i=0;i<n;i++) {
            if(i % 2 == 0) cout << t1[ptr1++] << " ";
            else cout << t2[ptr2++] << " ";
        }
        cout << "\n";
        return;
    }

    vector<int> ff, ss;
    swap(t1[n1-1], t1[n1-2]);
    int ptr1 = 0, ptr2 = 0;
    for(int i=0;i<n;i++) {
        if(i % 2 == 0) ff.push_back(t1[ptr1++]);
        else ff.push_back(t2[ptr2++]);
    }
    ptr1 = 0, ptr2 = 0;
    swap(t1[n1-1], t1[n1-2]);
    swap(t2[n2-1], t2[n2-2]);
    for(int i=0;i<n;i++) {
        if(i % 2 == 0) ss.push_back(t1[ptr1++]);
        else ss.push_back(t2[ptr2++]);
    }

    if(ff < ss) cout << ff << "\n";
    else cout << ss << "\n";

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