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

    // Total empty squares not in any attacked row or column
    ll total = (N - (ll)rows.size()) * (N - (ll)cols.size());

    // Now subtract squares that are on the same diagonal and intersect with attacked rows/columns
    set<pair<ll, ll>> attacked;

    // Process diag1: i - j = d
    for (ll d : diag1) {
        // All points on this diagonal are (i, i-d)
        for (ll i : rows) {
            ll j = i - d;
            if (1 <= j && j <= N) {
                attacked.insert({i, j});
            }
        }
        for (ll j : cols) {
            ll i = j + d;
            if (1 <= i && i <= N) {
                attacked.insert({i, j});
            }
        }
    }

    // Process diag2: i + j = s
    for (ll s : diag2) {
        // All points on this diagonal are (i, s-i)
        for (ll i : rows) {
            ll j = s - i;
            if (1 <= j && j <= N) {
                attacked.insert({i, j});
            }
        }
        for (ll j : cols) {
            ll i = s - j;
            if (1 <= i && i <= N) {
                attacked.insert({i, j});
            }
        }
    }

    // Subtract the number of attacked positions on diagonals that are otherwise safe
    total -= (ll)attacked.size();

    cout << total << "\n";
    return 0;
}