#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }

    ll T = 0;
    for (int i = 0; i < n; ++i) {
        ll remaining = h[i];
        ll full_cycles = remaining / 5;
        remaining %= 5;
        T += full_cycles * 3;
        if (remaining > 0) {
            if (remaining <= 3) {
                T += 1;
            } else {
                T += 3;
            }
        }
    }

    cout << T << endl;
    return 0;
}