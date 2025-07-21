#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 N, M;
    cin >> N >> M;

    set<i64> rows, cols, diag1, diag2;

    for (int i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }

    // Convert sets to vectors for easy iteration
    vector<i64> R(rows.begin(), rows.end());
    vector<i64> C(cols.begin(), cols.end());
    vector<i64> D1(diag1.begin(), diag1.end());
    vector<i64> D2(diag2.begin(), diag2.end());

    // Total number of cells threatened
    i64 total_threatened = 0;

    // Add all cells on rows, columns, diagonals, anti-diagonals
    total_threatened += N * R.size();
    total_threatened += N * C.size();
    for (auto d : D1) {
        // Number of points on diagonal a+b=d in [1,N]x[1,N]
        if (d <= N + 1)
            total_threatened += min(d - 1, N);
        else
            total_threatened += max(N + N - d + 1, 0LL);
    }
    for (auto d : D2) {
        // Number of points on diagonal a-b=d in [1,N]x[1,N]
        i64 low = max(1LL, d + 1);
        i64 high = min(N + d, N);
        if (low <= high)
            total_threatened += high - low + 1;
    }

    // Subtract intersections: row & col
    for (auto r : R) {
        for (auto c : C) {
            total_threatened -= 1; // cell (r,c)
        }
    }

    // Subtract intersections: row & diag1
    for (auto r : R) {
        for (auto d : D1) {
            i64 c = d - r;
            if (1 <= c && c <= N)
                total_threatened -= 1;
        }
    }

    // Subtract intersections: row & diag2
    for (auto r : R) {
        for (auto d : D2) {
            i64 c = r - d;
            if (1 <= c && c <= N)
                total_threatened -= 1;
        }
    }

    // Subtract intersections: col & diag1
    for (auto c : C) {
        for (auto d : D1) {
            i64 r = d - c;
            if (1 <= r && r <= N)
                total_threatened -= 1;
        }
    }

    // Subtract intersections: col & diag2
    for (auto c : C) {
        for (auto d : D2) {
            i64 r = d + c;
            if (1 <= r && r <= N)
                total_threatened -= 1;
        }
    }

    // Subtract intersections: diag1 & diag2
    for (auto d1 : D1) {
        for (auto d2 : D2) {
            // Solve:
            // x + y = d1
            // x - y = d2
            // => x = (d1 + d2)/2, y = (d1 - d2)/2
            if ((d1 + d2) % 2 == 0 && (d1 - d2) % 2 == 0) {
                i64 x = (d1 + d2) / 2;
                i64 y = (d1 - d2) / 2;
                if (1 <= x && x <= N && 1 <= y && y <= N)
                    total_threatened -= 1;
            }
        }
    }

    // Add back triple overlaps: row & col & diag1
    for (auto r : R) {
        for (auto c : C) {
            i64 d = r + c;
            if (diag1.count(d))
                total_threatened += 1;
        }
    }

    // Add back triple overlaps: row & col & diag2
    for (auto r : R) {
        for (auto c : C) {
            i64 d = r - c;
            if (diag2.count(d))
                total_threatened += 1;
        }
    }

    // Add back triple overlaps: row & diag1 & diag2
    for (auto r : R) {
        for (auto d1 : D1) {
            for (auto d2 : D2) {
                i64 c = d1 - r;
                if (c == r - d2)
                    if (1 <= c && c <= N)
                        total_threatened += 1;
            }
        }
    }

    // Add back triple overlaps: col & diag1 & diag2
    for (auto c : C) {
        for (auto d1 : D1) {
            for (auto d2 : D2) {
                i64 r = d1 - c;
                if (r == d2 + c)
                    if (1 <= r && r <= N)
                        total_threatened += 1;
            }
        }
    }

    // Subtract quadruple overlaps: row & col & diag1 & diag2
    for (auto r : R) {
        for (auto c : C) {
            i64 d1 = r + c;
            i64 d2 = r - c;
            if (diag1.count(d1) && diag2.count(d2))
                total_threatened -= 1;
        }
    }

    i64 total_cells = N * N;
    i64 empty_cells = total_cells - M;
    i64 safe_positions = empty_cells - total_threatened;

    cout << safe_positions << "\n";

    return 0;
}