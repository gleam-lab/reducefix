#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }

    ll t = 0;
    for (ll h : h) {
        if (h % 3 == 0) {
            t += (h / 3);
        } else {
            t += (h / 3) + 2;  // When health % 3 != 0, it will need two attacks
        }
    }

    cout << t << endl;

    return 0;
}