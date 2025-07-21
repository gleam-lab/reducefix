#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
#define re(x) cin >> x

bool inBounds(const pll& p, ll n) {
    return p.first >= 1 && p.first <= n && p.second >= 1 && p.second <= n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll N, M;
    re(N >> M);

    vector<pll> pieces(M);
    set<ll> rows, cols;
    set<ll> diag1, diag2; // diag1: i-j, diag2: i+j

    for (auto& [x, y] : pieces) {
        re(x >> y);
        rows.insert(x);
        cols.insert(y);
        diag1.insert(x - y);
        diag2.insert(x + y);
    }

    ll total = N * N;

    // Subtract attacked squares due to rows and columns using inclusion-exclusion
    ll row_attacks = rows.size() * N;
    ll col_attacks = cols.size() * N;
    ll overlap_row_col = 0;

    // Count overlaps where (r, c) exists such that r in rows and c in cols
    // Only M^2 combinations possible at max
    set<pll> seen;
    for (ll r : rows) {
        for (ll c : cols) {
            seen.emplace(r, c);
        }
    }
    overlap_row_col = seen.size();

    total -= (row_attacks + col_attacks - overlap_row_col);

    // Now subtract attacked squares due to diagonals
    set<pll> blocked;

    // Process diag1: i - j
    for (ll d : diag1) {
        seen.clear();
        for (ll r : rows) {
            ll c = r - d;
            if (inBounds({r, c}, N)) {
                seen.emplace(r, c);
            }
        }
        for (ll c : cols) {
            ll r = c + d;
            if (inBounds({r, c}, N)) {
                seen.emplace(r, c);
            }
        }
        // Add intersection points already covered
        for (auto p : seen) blocked.insert(p);
    }

    // Process diag2: i + j
    for (ll d : diag2) {
        seen.clear();
        for (ll r : rows) {
            ll c = d - r;
            if (inBounds({r, c}, N)) {
                seen.emplace(r, c);
            }
        }
        for (ll c : cols) {
            ll r = d - c;
            if (inBounds({r, c}, N)) {
                seen.emplace(r, c);
            }
        }
        // Also check intersections of diag1 and diag2
        for (ll od : diag1) {
            ll i = (d + od) / 2;
            ll j = (d - od) / 2;
            if ((d + od) % 2 == 0 && (d - od) % 2 == 0 && inBounds({i, j}, N)) {
                seen.emplace(i, j);
            }
        }
        for (auto p : seen) blocked.insert(p);
    }

    // Remove overlaps from diagonals
    ll diag_overlap = blocked.size();

    // Count total squares attacked by diagonals
    ll diag_count = 0;
    for (ll d : diag1) {
        ll cnt = N - abs(d);
        diag_count += cnt;
    }
    for (ll d : diag2) {
        if (d <= N)
            diag_count += d - 1;
        else
            diag_count += 2 * N - d + 1;
    }

    // Inclusion-Exclusion: subtract diagonal attacks but add back overlaps
    total -= (diag_count - diag_overlap);

    // Finally, remove the positions already occupied by pieces
    total -= M;

    cout << total << "\n";

    return 0;
}