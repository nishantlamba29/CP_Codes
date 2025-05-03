#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
vector<int> precompute_steps(int max_value) {
    vector<int> steps(max_value + 1, 0);
    for (int i = 2; i <= max_value; i++) {
        steps[i] = steps[__builtin_popcount(i)] + 1;
    }
    return steps;
}
int solve(string N, int K) {
    if (K == 0) {
        return 1;
    }
    int len = N.size();
    vector<int> steps = precompute_steps(1000);
    vector<vector<vector<int>>> f(len + 1, vector<vector<int>>(len + 1, vector<int>(2, 0)));
    f[0][0][0] = 1;
    for (int pos = 0; pos < len; pos++) {
        for (int set_bits = 0; set_bits <= pos; set_bits++) {
            for (int is_smaller = 0; is_smaller < 2; is_smaller++) {
                for (int bit = 0; bit <= (is_smaller ? 1 : (N[pos] - '0')); bit++) {
                    f[pos + 1][set_bits + bit][is_smaller | (bit < (N[pos] - '0'))] =
                        (f[pos + 1][set_bits + bit][is_smaller | (bit < (N[pos] - '0'))] + f[pos][set_bits][is_smaller]) % MOD;
                }
            }
        }
    }
    int result = 0;
    for (int set_bits = 1; set_bits <= len; set_bits++) {
        if (steps[set_bits] == K - 1) {
            result = (result + f[len][set_bits][0]) % MOD;
            result = (result + f[len][set_bits][1]) % MOD;
        }
    }
    if (K == 1) {
        result = (result + MOD - 1) % MOD;
    }
    return result;
}

int main() {
    string N;
    int K;
    cin >> N >> K;
    cout << solve(N, K) << endl;
    
    return 0;
}
