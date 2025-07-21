#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

bool inBounds(const pll &p, ll n) {
    return 1 <= p.first && p.first <= n && 1 <= p.second && p.second <= n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M;
    cin >> N >> M;

    set<pll> pieces;
    set<ll> rows, cols, diag1, diag2;

    for (ll i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        pieces.insert({a, b});
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
    }

    // Total squares attacked by existing pieces
    set<pll> attacked;

    // Rows and columns
    for (ll r : rows) {
        for (ll j = 1; j <= N; ++j)
            attacked.insert({r, j});
    }
    for (ll c : cols) {
        for (ll i = 1; i <= N; ++i)
            attacked.insert({i, c});
    }

    // Diagonals (i - j = constant)
    for (ll d : diag1) {
        ll start_i = max(1LL, d + 1);
        ll end_i = min(N, N + d);
        for (ll i = start_i; i <= end_i; ++i)
            attacked.insert({i, i - d});
    }

    // Anti-diagonals (i + j = constant)
    for (ll s : diag2) {
        ll start_i = max(1LL, s - N);
        ll end_i = min(N, s - 1);
        for (ll i = start_i; i <= end_i; ++i)
            attacked.insert({i, s - i});
    }

    // Remove the pieces themselves as they are not empty
    for (const auto& p : pieces)
        attacked.erase(p);

    // Total safe positions
    ll totalSafe = N * N - attacked.size() - M;

    cout << totalSafe << "\n";

    return 0;
}