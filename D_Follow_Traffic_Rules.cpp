#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    double a, v, l, d, w;
    cin >> a >> v >> l >> d >> w;
    w = min(w, v);

    double d1 = (w*w) / (2.0*a);
    cout << fixed << setprecision(12);
    
    if(d1 >= d) {
        double d2 = (v*v) / (2.0*a);
        if(d2 >= l) {
            double time = sqrtl(2.0 * l / a);
            cout << time;
        }
        else {
            double time = v / a;
            double dis = l - (v*v) / (2.0*a);
            time += dis / v;
            cout << time;
        }
    }
    else {
        double time = 0;
        double v1 = sqrtl((2*a*d + w*w) / 2.0);
        if(v1 >= v) {
            time = (2.0*v - w) / a;
            double dis = d - (2*v*v - w*w) / (2.0*a);
            time += dis / v;
        }
        else {
            time = (2.0*v1 - w) / a;
        }
        double d2 = (v*v - w*w) / (2.0*a);
        if(l-d <= d2) {
            double v2 = sqrtl(w*w + 2*a*(l-d));
            time += (v2 - w) / a;
        }
        else {
            time += (v - w) / a;
            time += (l - d - d2 ) / v;
        }
        cout << time;
    }

    


    return 0;
}