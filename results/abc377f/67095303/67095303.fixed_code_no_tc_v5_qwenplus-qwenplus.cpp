#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;

    set<int> rows, cols;
    set<int> diag1, diag2;  // diag1: i+j, diag2: i-j

    for (int i = 0; i < M; ++i) {
        int r, c;
        cin >> r >> c;
        rows.insert(r);
        cols.insert(c);
        diag1.insert(r + c);
        diag2.insert(r - c);
    }

    // Start with total number of cells not in any attacked row or column
    int ans = (N - rows.size()) * (N - cols.size());

    // Subtract squares attacked by diagonal constraints that are not already counted in rows or cols
    for (int d : diag1) {
        // Count how many attacked positions on this diagonal are not already excluded by row or col
        int count = 0;

        // The diagonal is i + j = d
        // We iterate over possible i values where 1 <= i <= N and 1 <= d-i <= N
        // That means max(1, d-N) <= i <= min(N, d-1)
        int i_min = max(1LL, d - N);
        int i_max = min(N, d - 1);

        for (int i = i_min; i <= i_max; ++i) {
            int j = d - i;
            if (j < 1 || j > N) continue;
            if (rows.count(i) == 0 && cols.count(j) == 0) {
                count++;
            }
        }

        ans -= count;
    }

    for (int d : diag2) {
        // Count how many attacked positions on this diagonal are not already counted in rows or cols
        int count = 0;

        // The diagonal is i - j = d
        // We iterate over possible i values where 1 <= i <= N and 1 <= i-d <= N
        // That means max(1, 1+d) <= i <= min(N, N+d)
        int i_min = max(1LL, d + 1);
        int i_max = min(N, N + d);

        for (int i = i_min; i <= i_max; ++i) {
            int j = i - d;
            if (j < 1 || j > N) continue;
            if (rows.count(i) == 0 && cols.count(j) == 0) {
                count++;
            }
        }

        ans -= count;
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();

    return 0;
}