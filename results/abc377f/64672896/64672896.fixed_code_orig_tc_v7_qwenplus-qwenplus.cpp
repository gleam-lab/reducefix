#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 N, M;
    cin >> N >> M;

    set<pair<i64, i64>> occupied;
    set<i64> rows, cols, diag1, diag2;

    for (int i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        occupied.insert({a, b});
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }

    // Total number of cells: N*N
    // Number of cells under threat:
    i64 threatened = 0;

    vector<i64> r(rows.begin(), rows.end());
    vector<i64> c(cols.begin(), cols.end());
    vector<i64> d1(diag1.begin(), diag1.end());
    vector<i64> d2(diag2.begin(), diag2.end());

    // Inclusion-exclusion
    auto size = [&](vector<i64>& v) { return v.size(); };

    // Single sets
    threatened += N * size(r);
    threatened += N * size(c);
    threatened += N * size(d1);
    threatened += N * size(d2);

    // Pairwise intersections
    auto count_row_col = [&](const vector<i64>& A, const vector<i64>& B) {
        set<pair<i64, i64>> s;
        for (auto x : A)
            for (auto y : B)
                s.insert({x, y});
        return (i64)s.size();
    };
    auto count_row_diag1 = [&](const vector<i64>& R, const vector<i64>& D) {
        set<pair<i64, i64>> s;
        for (auto r : R)
            for (auto d : D) {
                i64 c = d - r;
                if (1 <= c && c <= N)
                    s.insert({r, c});
            }
        return (i64)s.size();
    };
    auto count_row_diag2 = [&](const vector<i64>& R, const vector<i64>& D) {
        set<pair<i64, i64>> s;
        for (auto r : R)
            for (auto d : D) {
                i64 c = r - d;
                if (1 <= c && c <= N)
                    s.insert({r, c});
            }
        return (i64)s.size();
    };
    auto count_col_diag1 = [&](const vector<i64>& C, const vector<i64>& D) {
        set<pair<i64, i64>> s;
        for (auto c : C)
            for (auto d : D) {
                i64 r = d - c;
                if (1 <= r && r <= N)
                    s.insert({r, c});
            }
        return (i64)s.size();
    };
    auto count_col_diag2 = [&](const vector<i64>& C, const vector<i64>& D) {
        set<pair<i64, i64>> s;
        for (auto c : C)
            for (auto d : D) {
                i64 r = d + c;
                if (1 <= r && r <= N)
                    s.insert({r, c});
            }
        return (i64)s.size();
    };
    auto count_diag1_diag2 = [&](const vector<i64>& D1, const vector<i64>& D2) {
        set<pair<i64, i64>> s;
        for (auto d1 : D1)
            for (auto d2 : D2) {
                i64 r = (d1 + d2) / 2;
                i64 c = (d1 - d2) / 2;
                if ((d1 + d2) % 2 == 0 && 1 <= r && r <= N && 1 <= c && c <= N)
                    s.insert({r, c});
            }
        return (i64)s.size();
    };

    threatened -= N * size(r) * size(c);
    threatened -= count_row_diag1(r, d1);
    threatened -= count_row_diag2(r, d2);
    threatened -= count_col_diag1(c, d1);
    threatened -= count_col_diag2(c, d2);
    threatened -= count_diag1_diag2(d1, d2);

    // Triple intersections
    threatened += count_row_diag1(r, d1);
    threatened += count_row_diag2(r, d2);
    threatened += count_col_diag1(c, d1);
    threatened += count_col_diag2(c, d2);
    threatened += count_diag1_diag2(d1, d2);

    // Four-way intersection (subtract again)
    threatened -= count_row_col(r, c);

    // Now remove duplicates counted multiple times
    set<pair<i64, i64>> all_threatened_cells;

    for (auto x : r)
        for (i64 y = 1; y <= N; ++y)
            all_threatened_cells.insert({x, y});
    for (auto y : c)
        for (i64 x = 1; x <= N; ++x)
            all_threatened_cells.insert({x, y});
    for (auto d : d1)
        for (i64 x = max(1LL, d - N); x <= min(N, d - 1); ++x)
            all_threatened_cells.insert({x, d - x});
    for (auto d : d2)
        for (i64 x = max(1LL, d + 1); x <= min(N, N + d); ++x)
            all_threatened_cells.insert({x, x - d});

    i64 total_threatened = all_threatened_cells.size();

    // Remove occupied cells from total threatened
    i64 occupied_count = 0;
    for (auto p : occupied)
        if (all_threatened_cells.count(p))
            occupied_count++;

    i64 ans = N * N - total_threatened + occupied_count;
    cout << ans << "\n";

    return 0;
}