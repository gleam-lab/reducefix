#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 N, M;
    cin >> N >> M;

    set<i64> row_set, col_set, diag1_set, diag2_set;
    vector<array<i64, 2>> pieces(M);

    for (i64 i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
        row_set.insert(a);
        col_set.insert(b);
        diag1_set.insert(a + b);
        diag2_set.insert(a - b);
    }

    // Total squares that can attack
    i64 attacked = 0;

    // Rows
    attacked += row_set.size() * N;

    // Columns
    attacked += col_set.size() * N;

    // Diagonals (\)
    for (auto d : diag1_set) {
        i64 lo = max(1LL, d - N);
        i64 hi = min(N, d - 1);
        attacked += hi - lo + 1;
    }

    // Anti-diagonals (/)
    for (auto d : diag2_set) {
        i64 x_min = max(1LL, d + 1);
        i64 x_max = min(N, N + d);
        if (x_min <= x_max)
            attacked += x_max - x_min + 1;
    }

    // Subtract overlaps

    // Intersections of rows and columns
    for (auto r : row_set)
        for (auto c : col_set)
            if ((r >= 1 && r <= N) && (c >= 1 && c <= N))
                attacked--;

    // Intersections of rows and diag1
    for (auto r : row_set)
        for (auto d : diag1_set) {
            i64 c = d - r;
            if (c >= 1 && c <= N)
                attacked--;
        }

    // Intersections of rows and diag2
    for (auto r : row_set)
        for (auto d : diag2_set) {
            i64 c = r - d;
            if (c >= 1 && c <= N)
                attacked--;
        }

    // Intersections of cols and diag1
    for (auto c : col_set)
        for (auto d : diag1_set) {
            i64 r = d - c;
            if (r >= 1 && r <= N)
                attacked--;
        }

    // Intersections of cols and diag2
    for (auto c : col_set)
        for (auto d : diag2_set) {
            i64 r = d + c;
            if (r >= 1 && r <= N)
                attacked--;
        }

    // Intersections of diag1 and diag2
    for (auto d1 : diag1_set)
        for (auto d2 : diag2_set) {
            i64 r = (d1 + d2) / 2;
            i64 c = d1 - r;
            if ((r >= 1 && r <= N) && (c >= 1 && c <= N))
                attacked--;
        }

    // Add back triple overlaps
    for (auto r : row_set)
        for (auto c : col_set)
            for (auto d1 : diag1_set) {
                if (r + c == d1)
                    attacked++;
            }

    for (auto r : row_set)
        for (auto c : col_set)
            for (auto d2 : diag2_set) {
                if (r - c == d2)
                    attacked++;
            }

    for (auto r : row_set)
        for (auto d1 : diag1_set)
            for (auto d2 : diag2_set) {
                i64 c = d1 - r;
                i64 check_d2 = r - c;
                if (check_d2 == d2)
                    attacked++;
            }

    for (auto c : col_set)
        for (auto d1 : diag1_set)
            for (auto d2 : diag2_set) {
                i64 r = d1 - c;
                i64 check_d2 = r - c;
                if (check_d2 == d2)
                    attacked++;
            }

    // Subtract quadruple overlaps
    for (auto r : row_set)
        for (auto c : col_set)
            for (auto d1 : diag1_set)
                for (auto d2 : diag2_set) {
                    if (r + c == d1 && r - c == d2)
                        attacked--;
                }

    // Remove already occupied squares
    attacked -= M;

    i64 total_empty = N * N - M;
    i64 ans = total_empty - attacked;

    cout << ans << "\n";

    return 0;
}