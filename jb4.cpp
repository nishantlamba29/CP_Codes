#include <iostream>
#include <vector>
#include <unordered_map>
#define MOD 1000000007
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> A(n);
    for(int i = 0; i < n; i++) cin >> A[i];
    int k = 316; // Since sqrt(1e5) ≈ 316
    unordered_map<int, vector<long long>> sum_mod_jump;

    // Precompute sums for small jumps
    for(int jump = 1; jump <= k; jump++) {
        vector<long long> sums(jump, 0);
        for(int i = 0; i < n; i++) {
            sums[i % jump] += A[i];
        }
        sum_mod_jump[jump] = sums;
    }

    long long total = 0;
    while(q--) {
        int start, jump;
        cin >> start >> jump;
        long long ans = 0;
        if(jump <= k) {
            ans = sum_mod_jump[jump][start % jump];
        } else {
            // For large jumps compute individually
            for(int i = start; i < n; i += jump) {
                ans += A[i];
            }
        }
        ans %= MOD;
        total = (total + ans) % MOD;
    }
    cout << total << endl;
    return 0;
}