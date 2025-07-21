#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll num_attacks(ll t, ll h) {
    ll cycles = h / 5;
    ll remaining = h % 5;
    ll total = cycles * 3;
    t += total;
    while (remaining > 0) {
        t++;
        if (t % 3 == 0) {
            remaining -= 3;
        } else {
            remaining -= 1;
        }
    }
    return t;
}

int main() {
    int n;
    cin >> n;
    vector<ll> H(n);
    for (int i = 0; i < n; ++i) {
        cin >> H[i];
    }
    ll t = 0;
    for (int i = 0; i < n; ++i) {
        t = num_attacks(t, H[i]);
    }
    cout << t << endl;
    return 0;
}