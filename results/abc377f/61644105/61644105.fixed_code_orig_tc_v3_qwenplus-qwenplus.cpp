#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M;
    cin >> N >> M;

    set<pair<ll, ll>> pieces;

    vector<ll> rows, cols;
    vector<ll> diag1, diag2;  // i+j and i-j

    for (ll i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        pieces.emplace(a, b);
        rows.push_back(a);
        cols.push_back(b);
        diag1.push_back(a + b);
        diag2.push_back(a - b);
    }

    sort(rows.begin(), rows.end());
    rows.erase(unique(rows.begin(), rows.end()), rows.end());

    sort(cols.begin(), cols.end());
    cols.erase(unique(cols.begin(), cols.end()), cols.end());

    sort(diag1.begin(), diag1.end());
    diag1.erase(unique(diag1.begin(), diag1.end()), diag1.end());

    sort(diag2.begin(), diag2.end());
    diag2.erase(unique(diag2.begin(), diag2.end()), diag2.end());

    // Total squares under attack
    ll attacked = 0;

    // Rows and columns
    attacked += N * rows.size();
    attacked += N * cols.size();

    // Diagonals
    for (ll d : diag1)
        attacked += max(0LL, min(d - 1, N) - max(d - N, 1LL) + 1);

    for (ll d : diag2)
        attacked += max(0LL, min(N, N + d) - max(1LL, 1 + d) + 1);

    // Subtract overlaps: row-col, row-diag1, row-diag2, col-diag1, col-diag2, diag1-diag2
    for (ll r : rows)
        for (ll c : cols)
            if (pieces.count({r, c}))
                attacked -= 1;

    for (ll r : rows)
        for (ll d : diag1) {
            ll c = d - r;
            if (1 <= c && c <= N && pieces.count({r, c}))
                attacked -= 1;
        }

    for (ll r : rows)
        for (ll d : diag2) {
            ll c = r - d;
            if (1 <= c && c <= N && pieces.count({r, c}))
                attacked -= 1;
        }

    for (ll c : cols)
        for (ll d : diag1) {
            ll r = d - c;
            if (1 <= r && r <= N && pieces.count({r, c}))
                attacked -= 1;
        }

    for (ll c : cols)
        for (ll d : diag2) {
            ll r = d + c;
            if (1 <= r && r <= N && pieces.count({r, c}))
                attacked -= 1;
        }

    for (ll d1 : diag1)
        for (ll d2 : diag2) {
            ll r = (d1 + d2) / 2;
            ll c = (d1 - d2) / 2;
            if (1 <= r && r <= N && 1 <= c && c <= N && pieces.count({r, c}))
                attacked -= 1;
        }

    // Add back triple overlaps: row-col-diag1, row-col-diag2, row-diag1-diag2, col-diag1-diag2
    for (ll r : rows)
        for (ll c : cols) {
            ll d1 = r + c;
            ll d2 = r - c;
            if (binary_search(diag1.begin(), diag1.end(), d1) &&
                binary_search(diag2.begin(), diag2.end(), d2))
                attacked += 1;
        }

    for (ll r : rows)
        for (ll d1 : diag1) {
            ll c = d1 - r;
            if (1 <= c && c <= N) {
                ll d2 = r - c;
                if (binary_search(diag2.begin(), diag2.end(), d2))
                    attacked += 1;
            }
        }

    for (ll c : cols)
        for (ll d1 : diag1) {
            ll r = d1 - c;
            if (1 <= r && r <= N) {
                ll d2 = r - c;
                if (binary_search(diag2.begin(), diag2.end(), d2))
                    attacked += 1;
            }
        }

    for (ll d1 : diag1)
        for (ll d2 : diag2) {
            ll r = (d1 + d2) / 2;
            ll c = (d1 - d2) / 2;
            if (1 <= r && r <= N && 1 <= c && c <= N &&
                binary_search(rows.begin(), rows.end(), r) &&
                binary_search(cols.begin(), cols.end(), c))
                attacked += 1;
        }

    // Subtract quadruple overlaps
    for (ll r : rows)
        for (ll c : cols) {
            ll d1 = r + c;
            ll d2 = r - c;
            if (binary_search(diag1.begin(), diag1.end(), d1) &&
                binary_search(diag2.begin(), diag2.end(), d2))
                attacked -= 1;
        }

    ll total_attacked = attacked;

    // Now subtract the occupied squares from total available
    ll total_available = N * N - M - total_attacked;

    cout << total_available << "\n";

    return 0;
}