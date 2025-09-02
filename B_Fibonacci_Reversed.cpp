#include <bits/stdc++.h>
using namespace std;
#define int long long

string add(string a, string b) {
    string res;
    int i = a.size() - 1, j = b.size() - 1;
    int carry = 0;
    while(i >= 0 && j >= 0) {
        int x = a[i] - '0', y = b[j] - '0';
        int num = x + y + carry;
        res.push_back(num % 10 + '0');
        carry = num / 10;
        i--;
        j--;
    }
    while(i >= 0) {
        int x = a[i] - '0';
        int num = x + carry;
        res.push_back(num % 10 + '0');
        carry = num / 10;
        i--;
    }
    while(j >= 0) {
        int y = b[j] - '0';
        int num = y + carry;
        res.push_back(num % 10 + '0');
        carry = num / 10;
        j--;
    }
    if(carry != 0)
    res.push_back(carry + '0');

    reverse(res.begin(), res.end());
    return res;
}

int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string x, y;
    cin >> x >> y;

    for(int i=3;i<=10;i++) {

        string temp = add(x, y);

        while(temp.size() > 1 && temp.back() == '0') temp.pop_back();

        reverse(temp.begin(), temp.end());

        x = y;
        y = temp;

    }

    cout << y;

    return 0;
}