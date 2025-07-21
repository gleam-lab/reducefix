#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 N, M;
    cin >> N >> M;

    set<i64> rows, cols, diag1, diag2;
    vector<pair<i64, i64>> pieces(M);

    for (int i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }

    // Total number of attacked cells
    i64 attacked = 0;

    // Rows and columns contribute N cells each
    attacked += (i64)rows.size() * N;
    attacked += (i64)cols.size() * N;

    // Diagonals also contribute up to N cells each
    attacked += (i64)diag1.size() * N;
    attacked += (i64)diag2.size() * N;

    // Subtract overlaps

    // Row & Column intersections
    for (auto r : rows) {
        if (cols.count(r)) {
            attacked -= 1; // cell (r, r) counted twice
        }
    }

    // Row & Diag1 intersections
    for (auto r : rows) {
        for (auto d : diag1) {
            i64 c = d - r;
            if (1 <= c && c <= N) {
                attacked -= 1;
            }
        }
    }

    // Row & Diag2 intersections
    for (auto r : rows) {
        for (auto d : diag2) {
            i64 c = r - d;
            if (1 <= c && c <= N) {
                attacked -= 1;
            }
        }
    }

    // Col & Diag1 intersections
    for (auto c : cols) {
        for (auto d : diag1) {
            i64 r = d - c;
            if (1 <= r && r <= N) {
                attacked -= 1;
            }
        }
    }

    // Col & Diag2 intersections
    for (auto c : cols) {
        for (auto d : diag2) {
            i64 r = d + c;
            if (1 <= r && r <= N) {
                attacked -= 1;
            }
        }
    }

    // Diag1 & Diag2 intersections
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            i64 x = (d1 + d2) / 2;
            i64 y = (d1 - d2) / 2;
            if ((d1 + d2) % 2 == 0 && (d1 - d2) % 2 == 0 &&
                1 <= x && x <= N && 1 <= y && y <= N) {
                attacked -= 1;
            }
        }
    }

    // Now subtract the exact number of attacked cells from total cells
    cout << N * N - attacked << "\n";

    return 0;
}