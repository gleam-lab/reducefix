#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define PII pair<ll, ll>

void solve() {
    ll N, M;
    cin >> N >> M;

    set<ll> row, col, diag1, diag2; // diag1: i+j, diag2: i-j

    for (ll i = 0; i < M; ++i) {
        ll x, y;
        cin >> x >> y;
        row.insert(x);
        col.insert(y);
        diag1.insert(x + y);
        diag2.insert(x - y);
    }

    ll ans = (N - (ll)row.size()) * (N - (ll)col.size());

    // Process anti-diagonals (i+j = d)
    for (auto d : diag1) {
        ll low = max(1LL, d - N);
        ll high = min(N, d - 1);
        ll len = high - low + 1;

        // Subtract overlapping with attacked rows/cols
        set<ll> blocked;
        for (auto x : row) {
            ll y = d - x;
            if (y >= 1 && y <= N)
                blocked.insert(x); // This square is already counted as blocked
        }
        for (auto y : col) {
            ll x = d - y;
            if (x >= 1 && x <= N)
                blocked.insert(x);
        }

        ans -= (len - (ll)blocked.size());
    }

    // Process main diagonals (i-j = d)
    for (auto d : diag2) {
        ll low = max(1LL, d + 1);
        ll high = min(N, N + d);
        ll len = high - low + 1;

        // Subtract overlapping with attacked rows/cols
        set<ll> blocked;
        for (auto x : row) {
            ll y = x - d;
            if (y >= 1 && y <= N)
                blocked.insert(x);
        }
        for (auto y : col) {
            ll x = y + d;
            if (x >= 1 && x <= N)
                blocked.insert(x);
        }

        ans -= (len - (ll)blocked.size());
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}