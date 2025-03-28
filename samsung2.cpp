#include<bits/stdc++.h>
using namespace std;
#define int long long

int countStudents(vector<int> &arr, int pages, int si){
    int n = arr.size() / 2;
    int students = 1;
    int pagesStudent = 0;
    for (int i = si; i < si + n; i++){
        if (pagesStudent + arr[i] <= pages){
            pagesStudent += arr[i];
        }
        else{
            students++;
            pagesStudent = arr[i];
        }
    }
    return students;
}

int findPages(vector<int> &arr, int n, int m, int si){
    if (m > n) return -1; // n = size, m = companies

    int low = *max_element(arr.begin(), arr.begin() + n);
    int high = accumulate(arr.begin(), arr.begin() + n, 0);
    while (low <= high){
        int mid = (low + high) / 2;
        int students = countStudents(arr, mid, si);
        if (students > m)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}


void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> oil(m);
    for(int i=0;i<m;i++) cin>>oil[i];
    for(int i=0;i<m;i++) oil.push_back(oil[i]);
    int final = INT_MAX;
    for (int i = 0; i < n; i++){
        int ans = findPages(oil, m, n, i);
        int maxi = INT_MIN;
        int mini = INT_MAX;
        int acc = 0;
        for (int j = i; j < i + m; j++){
            if (acc + oil[j] > ans){
                maxi = max(maxi, acc);
                mini = min(mini, acc);
                acc = oil[j];
            }
            else{
                acc += oil[j];
            }
        }
        maxi = max(maxi, acc);
        mini = min(mini, acc);
        final = min(final, maxi - mini);
    }
    cout << final << endl;

}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}