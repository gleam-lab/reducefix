#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N, M;
    cin >> N >> M;
    unordered_set<ll> rows, cols, diag1, diag2;
    for (ll i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }

    ll safe_rows = N - rows.size();
    ll safe_cols = N - cols.size();
    ll initial_safe = safe_rows * safe_cols;

    ll subtract = 0;

    // For diag1 (i + j = d)
    for (ll d : diag1) {
        ll i_min = max(1LL, d - N);
        ll i_max = min(N, d - 1);
        if (i_min > i_max) continue;
        ll diag_length = i_max - i_min + 1;

        ll count = diag_length;
        for (ll i = i_min; i <= i_max; ++i) {
            ll j = d - i;
            if (rows.count(i) || cols.count(j)) {
                --count;
            }
        }
        subtract += count;
    }

    // For diag2 (i - j = d)
    for (ll d : diag2) {
        ll i_min = max(1LL, 1 + d);
        ll i_max = min(N, N + d);
        if (i_min > i_max) continue;
        ll diag_length = i_max - i_min + 1;

        ll count = diag_length;
        for (ll i = i_min; i <= i_max; ++i) {
            ll j = i - d;
            if (rows.count(i) || cols.count(j)) {
                --count;
            }
        }
        subtract += count;
    }

    // Remove squares counted in both diag1 and diag2
    ll overlap = 0;
    for (ll d1 : diag1) {
        for (ll d2 : diag2) {
            if ((d1 + d2) % 2 != 0) continue;
            ll i = (d1 + d2) / 2;
            ll j = (d1 - d2) / 2;
            if (i >= 1 && i <= N && j >= 1 && j <= N) {
                if (!rows.count(i) && !cols.count(j)) {
                    ++overlap;
                }
            }
        }
    }
    subtract -= overlap;

    ll total_safe = initial_safe - subtract;
    cout << total_safe << endl;

    return 0;
}