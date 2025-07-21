#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M;
    cin >> N >> M;

    set<ll> rows, cols, diag1, diag2;
    map<pair<ll, ll>, bool> existing;

    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
        existing[{a, b}] = true;
    }

    ll forbidden_rows = rows.size();
    ll forbidden_cols = cols.size();
    ll forbidden_diag1 = diag1.size();
    ll forbidden_diag2 = diag2.size();

    // Calculate squares forbidden by rows and columns
    ll forbidden_rows_cols = forbidden_rows * N + forbidden_cols * N - forbidden_rows * forbidden_cols;

    // Calculate squares forbidden by diagonals (i+j) and (i-j)
    ll forbidden_diag = 0;
    for (auto d : diag1) {
        // The number of squares on diagonal d = a + b
        // The range is from max(1, d - N) to min(N, d - 1)
        ll lower = max(1LL, d - N);
        ll upper = min(N, d - 1);
        if (lower > upper) continue;
        forbidden_diag += upper - lower + 1;
    }
    for (auto d : diag2) {
        // The number of squares on diagonal d = a - b
        // The range is from max(1, 1 + d) to min(N, N + d)
        ll lower = max(1LL, 1 + d);
        ll upper = min(N, N + d);
        if (lower > upper) continue;
        forbidden_diag += upper - lower + 1;
    }

    // Subtract overlaps between rows/cols and diagonals
    // Squares that are in rows or cols and also in diagonals
    ll overlap_rows_diag1 = 0, overlap_cols_diag1 = 0;
    ll overlap_rows_diag2 = 0, overlap_cols_diag2 = 0;

    for (auto r : rows) {
        for (auto d : diag1) {
            ll c = d - r;
            if (c >= 1 && c <= N) {
                if (existing.find({r, c}) == existing.end()) {
                    overlap_rows_diag1++;
                }
            }
        }
        for (auto d : diag2) {
            ll c = r - d;
            if (c >= 1 && c <= N) {
                if (existing.find({r, c}) == existing.end()) {
                    overlap_rows_diag2++;
                }
            }
        }
    }

    for (auto c : cols) {
        for (auto d : diag1) {
            ll r = d - c;
            if (r >= 1 && r <= N) {
                if (existing.find({r, c}) == existing.end()) {
                    overlap_cols_diag1++;
                }
            }
        }
        for (auto d : diag2) {
            ll r = c + d;
            if (r >= 1 && r <= N) {
                if (existing.find({r, c}) == existing.end()) {
                    overlap_cols_diag2++;
                }
            }
        }
    }

    // Also account for squares that are in both diagonals (i+j) and (i-j)
    // These squares are at the intersections of the two diagonals
    ll overlap_diag1_diag2 = 0;
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            ll a = (d1 + d2) / 2;
            ll b = (d1 - d2) / 2;
            if ((d1 + d2) % 2 == 0 && (d1 - d2) % 2 == 0 && a >= 1 && a <= N && b >= 1 && b <= N) {
                if (existing.find({a, b}) == existing.end()) {
                    overlap_diag1_diag2++;
                }
            }
        }
    }

    // Total forbidden squares
    ll total_forbidden = forbidden_rows_cols 
                       + forbidden_diag 
                       - overlap_rows_diag1 - overlap_rows_diag2 
                       - overlap_cols_diag1 - overlap_cols_diag2 
                       + overlap_diag1_diag2;

    ll answer = N * N - total_forbidden - M;
    cout << answer << endl;

    return 0;
}