#include <bits/stdc++.h>
using namespace std;

vector<vector<vector<double>>> dp1, dp2, dp3;

double solve1(int r, int s, int p) {
    if(r == 0) return 0;
    if(p == 0 && s == 0)  return 1;
    if(dp1[r][s][p] != -1) return dp1[r][s][p];

    double total = r * s + s * p + p * r;

    double ans = 0;
    if(r > 0 && s > 0) ans += (r * s / total) * solve1(r, s - 1, p);
    if(s > 0 && p > 0) ans += (p * s / total) * solve1(r, s, p - 1);
    if(p > 0 && r > 0) ans += (p * r / total) * solve1(r - 1, s, p);

    return dp1[r][s][p] = ans;
}

double solve2(int r, int s, int p) {
    if(s == 0) return 0;
    if(p == 0 && r == 0)  return 1;
    if(dp2[r][s][p] != -1) return dp2[r][s][p];

    double total = r * s + s * p + p * r;

    double ans = 0;
    if(r > 0 && s > 0) ans += (r * s / total) * solve2(r, s - 1, p);
    if(s > 0 && p > 0) ans += (p * s / total) * solve2(r, s, p - 1);
    if(p > 0 && r > 0) ans += (p * r / total) * solve2(r - 1, s, p);

    return dp2[r][s][p] = ans;
}

double solve3(int r, int s, int p) {
    if(p == 0) return 0;
    if(r == 0 && s == 0)  return 1;
    if(dp3[r][s][p] != -1) return dp3[r][s][p];

    double total = r * s + s * p + p * r;

    double ans = 0;
    if(r > 0 && s > 0) ans += (r * s / total) * solve3(r, s - 1, p);
    if(s > 0 && p > 0) ans += (p * s / total) * solve3(r, s, p - 1);
    if(p > 0 && r > 0) ans += (p * r / total) * solve3(r - 1, s, p);

    return dp3[r][s][p] = ans;
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int r, s, p;
    cin >> r >> s >> p;

    dp1.resize(r+1, vector<vector<double>>(s+1, vector<double>(p+1, -1)));
    dp2.resize(r+1, vector<vector<double>>(s+1, vector<double>(p+1, -1)));
    dp3.resize(r+1, vector<vector<double>>(s+1, vector<double>(p+1, -1)));

    cout << fixed << setprecision(12) << solve1(r, s, p) << " " << solve2(r, s, p) << " " << solve3(r, s, p);


    return 0;
}