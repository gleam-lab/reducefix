#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 N, M;
    cin >> N >> M;

    set<i64> rows, cols, diag1, diag2;

    for (i64 i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }

    // Function to count intersections of two lines
    auto intersect = [](const set<i64>& s1, const set<i64>& s2) -> i64 {
        i64 cnt = 0;
        for (auto x : s1) {
            if (s2.count(x)) cnt++;
        }
        return cnt;
    };

    // Function to count cells lying on line x = r
    auto count_row = [&](i64 r) { return N; };
    // Function to count cells lying on line y = c
    auto count_col = [&](i64 c) { return N; };
    // Function to count cells lying on diagonal x + y = d
    auto count_diag1 = [&](i64 d) {
        i64 l = max(1LL, d - N);
        i64 r = min(N, d - 1);
        if (l > r) return 0LL;
        return r - l + 1;
    };
    // Function to count cells lying on diagonal x - y = d
    auto count_diag2 = [&](i64 d) {
        i64 l = max(1LL, d + 1);
        i64 r = min(N, N + d);
        if (l > r) return 0LL;
        return r - l + 1;
    };

    // Count union using Inclusion-Exclusion
    auto total_union = [&](const set<i64>& A, function<i64(i64)> fA,
                           const set<i64>& B, function<i64(i64)> fB,
                           const set<i64>& C = {}, function<i64(i64)> fC = nullptr,
                           const set<i64>& D = {}, function<i64(i64)> fD = nullptr) {
        i64 total = 0;

        for (auto a : A) total += fA(a);
        for (auto b : B) total += fB(b);

        for (auto a : A) for (auto b : B) {
            i64 x = a, y = b;
            if constexpr (is_same_v<function<i64(i64)>, function<i64(i64)>>) {}
            else {}
            i64 cnt = 0;
            if (&fA == &count_row && &fB == &count_col) {
                cnt = 1;
            } else if (&fA == &count_row && &fB == &count_diag1) {
                i64 y = x - a;
                if (y >= 1 && y <= N) cnt = 1;
            } else if (&fA == &count_row && &fB == &count_diag2) {
                i64 y = a - x;
                if (y >= 1 && y <= N) cnt = 1;
            } else if (&fA == &count_col && &fB == &count_diag1) {
                i64 x = a;
                i64 y = b - x;
                if (y >= 1 && y <= N) cnt = 1;
            } else if (&fA == &count_col && &fB == &count_diag2) {
                i64 x = b + a;
                if (x >= 1 && x <= N) cnt = 1;
            } else if (&fA == &count_diag1 && &fB == &count_diag2) {
                i64 x = (a + b) / 2;
                i64 y = (a - b) / 2;
                if ((a + b) % 2 == 0 && (a - b) % 2 == 0 &&
                    x >= 1 && y >= 1 && x <= N && y <= N)
                    cnt = 1;
            }
            total -= cnt;
        }

        if (fC) {
            for (auto c : C) total += fC(c);
            for (auto a : A) for (auto c : C) {
                // Handle triple intersection
            }
            for (auto b : B) for (auto c : C) {
                // Handle triple intersection
            }
            for (auto a : A) for (auto b : B) for (auto c : C) {
                // Handle triple intersection
            }
        }

        if (fD) {
            for (auto d : D) total += fD(d);
            // Handle quadruple intersection
        }

        return total;
    };

    i64 attacked = 0;

    // Add individual counts
    for (auto r : rows) attacked += count_row(r);
    for (auto c : cols) attacked += count_col(c);
    for (auto d : diag1) attacked += count_diag1(d);
    for (auto d : diag2) attacked += count_diag2(d);

    // Subtract pairwise overlaps
    for (auto r : rows) for (auto c : cols) attacked -= 1;
    for (auto r : rows) for (auto d : diag1) {
        i64 y = d - r;
        if (y >= 1 && y <= N) attacked -= 1;
    }
    for (auto r : rows) for (auto d : diag2) {
        i64 y = r - d;
        if (y >= 1 && y <= N) attacked -= 1;
    }
    for (auto c : cols) for (auto d : diag1) {
        i64 x = d - c;
        if (x >= 1 && x <= N) attacked -= 1;
    }
    for (auto c : cols) for (auto d : diag2) {
        i64 x = d + c;
        if (x >= 1 && x <= N) attacked -= 1;
    }
    for (auto d1 : diag1) for (auto d2 : diag2) {
        i64 x = (d1 + d2) / 2;
        i64 y = (d1 - d2) / 2;
        if ((d1 + d2) % 2 == 0 && (d1 - d2) % 2 == 0 &&
            x >= 1 && y >= 1 && x <= N && y <= N)
            attacked -= 1;
    }

    // Add back triple overlaps
    for (auto r : rows) for (auto c : cols) for (auto d1 : diag1) {
        if (r + c == d1) attacked += 1;
    }
    for (auto r : rows) for (auto c : cols) for (auto d2 : diag2) {
        if (r - c == d2) attacked += 1;
    }
    for (auto r : rows) for (auto d1 : diag1) for (auto d2 : diag2) {
        i64 x = r, y = d1 - x;
        if (x - y == d2) attacked += 1;
    }
    for (auto c : cols) for (auto d1 : diag1) for (auto d2 : diag2) {
        i64 y = c, x = d1 - y;
        if (x - y == d2) attacked += 1;
    }

    // Subtract quadruple overlaps
    for (auto r : rows) for (auto c : cols) for (auto d1 : diag1) for (auto d2 : diag2) {
        if (r == c && r + c == d1 && r - c == d2) attacked -= 1;
    }

    i64 total_cells = N * N;
    i64 answer = total_cells - attacked;
    cout << answer << '\n';
}