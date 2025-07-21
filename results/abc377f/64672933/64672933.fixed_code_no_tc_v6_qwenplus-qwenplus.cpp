#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 N;
    int M;
    cin >> N >> M;

    set<i64> rowSet, colSet;
    set<i64> diag1SumSet, diag2DiffSet;

    for (int i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        rowSet.insert(a);
        colSet.insert(b);
        diag1SumSet.insert(a + b);
        diag2DiffSet.insert(a - b);
    }

    i64 totalCovered = 0;

    // Rows
    totalCovered += (i64)rowSet.size() * N;
    // Columns
    totalCovered += (i64)colSet.size() * N;

    // Diagonals of type x + y = c
    for (i64 s : diag1SumSet) {
        i64 low = max(1LL, s - N);
        i64 high = min(N, s - 1);
        if (low <= high)
            totalCovered += high - low + 1;
    }

    // Diagonals of type x - y = d
    for (i64 d : diag2DiffSet) {
        i64 low = max(1LL, d + 1);
        i64 high = min(N, N + d);
        if (low <= high)
            totalCovered += high - low + 1;
    }

    // Subtract overcounted cells where lines intersect

    // Intersections between rows and columns
    totalCovered -= (i64)rowSet.size() * colSet.size();

    // Intersections between rows and diagonal sums (x + y = s)
    for (i64 r : rowSet) {
        for (i64 s : diag1SumSet) {
            i64 c = s - r;
            if (1 <= c && c <= N)
                totalCovered--;
        }
    }

    // Intersections between rows and diagonal diffs (x - y = d)
    for (i64 r : rowSet) {
        for (i64 d : diag2DiffSet) {
            i64 c = r - d;
            if (1 <= c && c <= N)
                totalCovered--;
        }
    }

    // Intersections between columns and diagonal sums (x + y = s)
    for (i64 c : colSet) {
        for (i64 s : diag1SumSet) {
            i64 r = s - c;
            if (1 <= r && r <= N)
                totalCovered--;
        }
    }

    // Intersections between columns and diagonal diffs (x - y = d)
    for (i64 c : colSet) {
        for (i64 d : diag2DiffSet) {
            i64 r = d + c;
            if (1 <= r && r <= N)
                totalCovered--;
        }
    }

    // Intersections between diagonal sums and diagonal diffs
    for (i64 s : diag1SumSet) {
        for (i64 d : diag2DiffSet) {
            if ((s + d) % 2 == 0) {
                i64 r = (s + d) / 2;
                i64 c = s - r;
                if (1 <= r && r <= N && 1 <= c && c <= N)
                    totalCovered--;
            }
        }
    }

    i64 ans = N * N - totalCovered;

    cout << ans << "\n";

    return 0;
}