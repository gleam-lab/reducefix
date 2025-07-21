#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> h(n);
    rep(i, n) cin >> h[i];

    ll T = 0;
    ll cumulative_time = 0;

    rep(i, n) {
        h[i] -= cumulative_time;
        if (h[i] <= 0) continue;

        ll full_cycles = h[i] / 5;
        ll remaining = h[i] % 5;

        T += full_cycles * 3;
        cumulative_time += full_cycles * 3;

        if (remaining > 0) {
            if (remaining <= 1) {
                T += 1;
                cumulative_time += 1;
            } else if (remaining <= 3) {
                T += 2;
                cumulative_time += 2;
            } else {
                T += 3;
                cumulative_time += 3;
            }
        }
    }

    cout << T << endl;
    return 0;
}