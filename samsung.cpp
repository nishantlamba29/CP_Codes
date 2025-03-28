// #include <bits/stdc++.h>
// using namespace std;

// vector<int> oil;
// int ans;
// map<tuple<int, int, int, int, int>, int> memo; // Memoization table with more states

// int solve(int curposition, int companyleft, int reservesleft, int n, int m , int mini, int maxi) {
//     if (companyleft == 0 && reservesleft == 0) {
//         return maxi - mini;
//     }
//     if (companyleft <= 0 || reservesleft <= 0) return INT_MAX;

//     // Check memoization table
//     auto key = make_tuple(curposition, companyleft, reservesleft, mini, maxi);
//     if (memo.find(key) != memo.end()) {
//         return memo[key];
//     }

//     int current_sum = 0;
//     int res = INT_MAX;
//     for (int i = curposition; i < curposition + reservesleft; i++) {
//         current_sum += oil[i % m];
//         int new_mini = min(mini, current_sum);
//         int new_maxi = max(maxi, current_sum);
//         res = min(res, solve((i + 1) % m, companyleft - 1, reservesleft - (i - curposition + 1), n, m, new_mini, new_maxi));
//     }
//     memo[key] = res;
//     return res;
// }

// int main() {
//     int t;
//     cin >> t;
//     while (t--) {
//         ans = INT_MAX;
//         memo.clear();
//         int n, m;
//         cin >> n >> m;
//         oil.resize(m);
//         for (int i = 0; i < m; i++) {
//             cin >> oil[i];
//         }
//         for (int i = 0; i < m; i++) {
//             ans = min(ans, solve(i, n, m, n, m, INT_MAX, INT_MIN));
//         }
//         cout << ans << endl;
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int countStudents(vector<int> &arr, int pages, int si)
{
    int n = arr.size() / 2; // size of array.
    int students = 1;
    long long pagesStudent = 0;
    for (int i = si; i < si + n; i++)
    {
        // cout<<arr[i]<<" arr[i] "<<endl;
        if (pagesStudent + arr[i] <= pages)
        {
            // add pages to current student
            pagesStudent += arr[i];
        }
        else
        {
            // add pages to next student
            students++;
            pagesStudent = arr[i];
        }
    }
    return students;
}
int findPages(vector<int> &arr, int n, int m, int si)
{
    // book allocation impossible:
    if (m > n)
        return -1;

    int low = *max_element(arr.begin(), arr.begin() + n);
    int high = accumulate(arr.begin(), arr.begin() + n, 0);
    // cout<<low<<" low "<<high<<" high "<<endl;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int students = countStudents(arr, mid, si);
        if (students > m)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}

int main()
{
    vector<int> arr = {12345, 67890, 23456, 98765, 34567, 87654, 45678, 76543, 56789,
                       65432, 6789, 54321, 7890, 43210, 8901, 32109, 9012, 21098, 123, 10987, 234, 9876,
                       345, 8765, 456, 7654, 567, 6543, 678, 5432, 789, 4321, 890, 3210, 901, 2109, 12,
                       1098, 23, 987, 34, 876, 45, 765, 56, 654, 67, 543, 78, 432, 89, 321, 90};
    vector<int> narr = arr;
    // for(int i=0;i<n;i++){
    //     narr.push_back()
    // }
    int final = INT_MAX;
    int n = 50;
    for (int i = 0; i < n; i++)
    {
        narr.push_back(arr[i]);
    }
    // for(auto x:narr) cout<<x<<" ";
    // cout<<endl;
    int m = 25;
    for (int i = 0; i < n; i++)
    {
        int ans = findPages(narr, n, m, i);
        int maxi = INT_MIN;
        int mini = INT_MAX;
        int acc = 0;
        // cout<<ans<<" limit "<<endl;
        for (int j = i; j < i + n; j++)
        {
            if (acc + narr[j] > ans)
            {
                maxi = max(maxi, acc);
                mini = min(mini, acc);
                acc = narr[j];
            }
            else
            {
                acc += narr[j];
            }
        }
        maxi = max(maxi, acc);
        mini = min(mini, acc);
        final = min(final, maxi - mini);
    }
    cout << final << " final " << endl;
    return 0;
}