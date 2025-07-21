#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    cin >> N >> M;

    set<long long> row, col, diag, anti_diag;
    set<pair<long long, long long>> pieces;

    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        row.insert(a);
        col.insert(b);
        diag.insert(a + b);
        anti_diag.insert(a - b);
        pieces.emplace(a, b);
    }

    // Total threatened cells: union of all lines
    map<pair<long long, long long>, int> intersection_count;

    long long total_threatened = 0;

    // Add row threats
    total_threatened += row.size() * N;

    // Add column threats
    total_threatened += col.size() * N;

    // Add diagonal threats
    for (long long d : diag) {
        long long low = max(1LL, d - N);
        long long high = min(N, d - 1);
        if (low <= high) total_threatened += high - low + 1;
    }

    // Add anti-diagonal threats
    for (long long ad : anti_diag) {
        long long low = max(1LL, 1 + ad);
        long long high = min(N, N + ad);
        if (low <= high) total_threatened += high - low + 1;
    }

    // Subtract overlaps between diagonals and anti-diagonals
    for (long long d : diag) {
        for (long long ad : anti_diag) {
            if ((d + ad) % 2 == 0) {
                long long x = (d + ad) / 2;
                long long y = d - x;
                if (x >= 1 && x <= N && y >= 1 && y <= N) {
                    if (intersection_count[{x, y}]++ == 0)
                        total_threatened--;
                }
            }
        }
    }

    // Subtract overlaps between rows and columns
    for (long long r : row) {
        for (long long c : col) {
            if (intersection_count[{r, c}]++ == 0)
                total_threatened--;
        }
    }

    // Subtract overlaps between rows and diagonals
    for (long long r : row) {
        for (long long d : diag) {
            long long c = d - r;
            if (c >= 1 && c <= N) {
                if (intersection_count[{r, c}]++ == 0)
                    total_threatened--;
            }
        }
    }

    // Subtract overlaps between rows and anti-diagonals
    for (long long r : row) {
        for (long long ad : anti_diag) {
            long long c = r - ad;
            if (c >= 1 && c <= N) {
                if (intersection_count[{r, c}]++ == 0)
                    total_threatened--;
            }
        }
    }

    // Subtract overlaps between columns and diagonals
    for (long long c : col) {
        for (long long d : diag) {
            long long r = d - c;
            if (r >= 1 && r <= N) {
                if (intersection_count[{r, c}]++ == 0)
                    total_threatened--;
            }
        }
    }

    // Subtract overlaps between columns and anti-diagonals
    for (long long c : col) {
        for (long long ad : anti_diag) {
            long long r = ad + c;
            if (r >= 1 && r <= N) {
                if (intersection_count[{r, c}]++ == 0)
                    total_threatened--;
            }
        }
    }

    // Subtract overlaps between diagonals and anti-diagonals again (was added twice)
    for (long long d : diag) {
        for (long long ad : anti_diag) {
            if ((d + ad) % 2 == 0) {
                long long x = (d + ad) / 2;
                long long y = d - x;
                if (x >= 1 && x <= N && y >= 1 && y <= N) {
                    if (intersection_count[{x, y}]++ == 0)
                        total_threatened--;
                }
            }
        }
    }

    // Subtract occupied cells
    long long ans = N * N - total_threatened - M;

    cout << ans << "\n";

    return 0;
}