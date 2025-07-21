#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M;
    cin >> N >> M;

    set<ll> rows, cols;
    set<ll> diag1, diag2; // diag1: i-j, diag2: i+j

    for (ll i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
    }

    ll total_safe = (N - rows.size()) * (N - cols.size());

    set<pair<ll, ll>> blocked;

    // For each diagonal of type i-j
    for (ll d : diag1) {
        // All cells on this diagonal satisfy x - y = d
        // So x = y + d
        for (ll y = max(1LL, 1 - d); y <= min(N, N - d); ++y) {
            ll x = y + d;
            blocked.insert({x, y});
        }
    }

    // For each diagonal of type i+j
    for (ll s : diag2) {
        // All cells on this diagonal satisfy x + y = s
        // y = s - x
        for (ll x = max(1LL, s - N); x <= min(N, s - 1); ++x) {
            ll y = s - x;
            blocked.insert({x, y});
        }
    }

    // Remove already placed pieces from blocked set
    for (ll i = 0; i < M; ++i) {
        blocked.erase({rows.find(*next(rows.begin(), i)), cols.find(*next(cols.begin(), i))}});
    }

    total_safe -= blocked.size();

    cout << total_safe << endl;

    return 0;
}