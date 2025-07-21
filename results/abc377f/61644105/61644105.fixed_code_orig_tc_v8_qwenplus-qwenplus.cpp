#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    int M;
    cin >> N >> M;

    set<ll> rows, cols;
    set<ll> diag1, diag2; // i + j and i - j

    vector<pair<ll, ll>> pieces(M);
    for (auto& [x, y] : pieces) {
        cin >> x >> y;
        rows.insert(x);
        cols.insert(y);
        diag1.insert(x + y);
        diag2.insert(x - y);
    }

    // Row and column counts
    ll R = rows.size();
    ll C = cols.size();
    ll D1 = diag1.size();
    ll D2 = diag2.size();

    // Total unoccupied cells
    ll total_empty = N * N - M;

    // Threatened cells
    ll threat_rows = R * N;
    ll threat_cols = C * N;
    ll threat_diag1 = D1 * N;
    ll threat_diag2 = D2 * N;

    // Pairwise overlaps
    ll overlap_row_col = R * C;
    ll overlap_row_diag1 = 0;
    ll overlap_row_diag2 = 0;
    ll overlap_col_diag1 = 0;
    ll overlap_col_diag2 = 0;
    ll overlap_diag1_diag2 = 0;

    // For each row, check which diag1 and diag2 intersect it
    for (ll r : rows) {
        for (ll d1 : diag1) {
            ll c = d1 - r;
            if (1 <= c && c <= N) overlap_row_diag1++;
        }
        for (ll d2 : diag2) {
            ll c = r + d2;
            if (1 <= c && c <= N) overlap_row_diag2++;
        }
    }

    for (ll c : cols) {
        for (ll d1 : diag1) {
            ll r = d1 - c;
            if (1 <= r && r <= N) overlap_col_diag1++;
        }
        for (ll d2 : diag2) {
            ll r = d2 + c;
            if (1 <= r && r <= N) overlap_col_diag2++;
        }
    }

    for (ll d1 : diag1) {
        for (ll d2 : diag2) {
            ll r = (d1 + d2) / 2;
            ll c = (d1 - d2) / 2;
            if ((d1 + d2) % 2 == 0 && 1 <= r && r <= N && 1 <= c && c <= N)
                overlap_diag1_diag2++;
        }
    }

    // Triple overlaps
    ll triple_row_col_diag1 = 0;
    ll triple_row_col_diag2 = 0;
    ll triple_row_diag1_diag2 = 0;
    ll triple_col_diag1_diag2 = 0;

    for (ll r : rows) {
        for (ll c : cols) {
            ll d1 = r + c;
            ll d2 = r - c;
            if (diag1.count(d1) && diag2.count(d2)) triple_row_col_diag1++;
        }
    }

    for (ll r : rows) {
        for (ll d1 : diag1) {
            ll c = d1 - r;
            if (1 <= c && c <= N && cols.count(c))
                triple_row_diag1_diag2++;
        }
    }

    for (ll c : cols) {
        for (ll d2 : diag2) {
            ll r = d2 + c;
            if (1 <= r && r <= N && rows.count(r))
                triple_col_diag1_diag2++;
        }
    }

    // Quadruple overlap
    ll quad = 0;
    for (ll r : rows) {
        for (ll c : cols) {
            ll d1 = r + c;
            ll d2 = r - c;
            if (diag1.count(d1) && diag2.count(d2)) quad++;
        }
    }

    // Inclusion-Exclusion Principle
    ll total_threatened = threat_rows + threat_cols + threat_diag1 + threat_diag2
                        - overlap_row_col - overlap_row_diag1 - overlap_row_diag2
                        - overlap_col_diag1 - overlap_col_diag2 - overlap_diag1_diag2
                        + triple_row_col_diag1 + triple_row_col_diag2 + triple_row_diag1_diag2 + triple_col_diag1_diag2
                        - quad;

    // Now subtract threatened empty cells
    cout << total_empty - total_threatened << "\n";

    return 0;
}