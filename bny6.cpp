#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

const lli mod = 1000007;

const int mx = 1000000;
const int S = sqrt(mx) + 1;
int prime[mx], np = 0;
bool isnp[mx + 10];

// Sieve of Eratosthenes to find all primes up to mx
void siv(void) {
    int i, j, k;
    np = 0;
    isnp[1] = isnp[0] = true;
    prime[np++] = 2;
    for (i = 3; i <= S; i += 2)
        if (!isnp[i])
            for (prime[np++] = i, j = i * i, k = (i << 1); j <= mx; j += k)
                isnp[j] = true;
    for (; i <= mx; i += 2)
        if (!isnp[i])
            prime[np++] = i;
}

// Function to find the power of prime p in n!
lli pinf(int p, int n) {
    int ans = 0;
    while (n) {
        ans += (n / p);
        n /= p;
    }
    return ans;
}

// Function to find the number of divisors of (n!)^2
lli ArithmaticEquation(int n) {
    int i = 0;
    lli ans = 1;
    while (prime[i] <= n) {
        ans *= (pinf(prime[i], n) * 2) + 1;
        ans %= mod;
        i++;
    }
    return ans;
}

int main() {
    siv();
    int n;
    cin >> n;   //32327  ->    656502
    cout << ArithmaticEquation(n) << endl;
    return 0;
}

// arithmatic equation  