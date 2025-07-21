#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long N, M;
    cin >> N >> M;

    set<long long> rows, cols, diag1, diag2;

    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }

    // Total safe positions excluding rows and columns
    long long ans = (N - rows.size()) * (N - cols.size());

    // Subtract the number of points threatened only by diagonals (excluding rows and columns overlap)

    // Process anti-diagonals: i + j = d
    for (long long d : diag1) {
        long long low = max(1LL, d - N);
        long long high = min(N, d - 1);

        if (low > high) continue;

        long long count = high - low + 1;
        // Now remove those already excluded by rows or cols
        long long effective = 0;
        for (long long x : rows) {
            long long y = d - x;
            if (y >= 1 && y <= N && cols.find(y) == cols.end()) {
                effective++;
            }
        }
        ans -= (count - effective);
    }

    // Process main diagonals: i - j = d
    for (long long d : diag2) {
        long long low_x = max(1LL, 1 + d);
        long long high_x = min(N, N + d);
        if (low_x > high_x) continue;

        long long count = high_x - low_x + 1;
        long long effective = 0;
        for (long long x : rows) {
            long long y = x - d;
            if (y >= 1 && y <= N && cols.find(y) == cols.end()) {
                effective++;
            }
        }
        ans -= (count - effective);
    }

    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}