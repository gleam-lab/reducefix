#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;

    set<int> rows, cols;
    set<int> diag1, diag2;  // i+j and i-j respectively

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }

    // Total empty squares not attacked
    int ans = (N - rows.size()) * (N - cols.size());

    // Subtract squares attacked on diagonals that are NOT already excluded by row/col attack
    for (int d : diag1) {
        // Count number of cells on diagonal i+j=d that are in unattacked rows and columns
        // Compute valid range for i
        int min_i = max(1LL, d - N);
        int max_i = min(N, d - 1);

        if (min_i > max_i) continue;

        // These are the rows intersected by this diagonal
        set<int> blocked;
        for (int r : rows) {
            int c = d - r;
            if (1 <= c && c <= N)
                blocked.insert(r);
        }
        for (int c : cols) {
            int r = d - c;
            if (1 <= r && r <= N)
                blocked.insert(r);
        }

        ans -= (max_i - min_i + 1) - blocked.size();
    }

    for (int d : diag2) {
        // Count number of cells on diagonal i-j=d => i = j + d
        int min_j, max_j;
        if (d >= 0) {
            // i = j + d <= N => j <= N - d
            min_j = 1;
            max_j = N - d;
        } else {
            // i = j + d >= 1 => j >= 1 - d
            min_j = 1 - d;
            max_j = N;
        }

        if (min_j > max_j) continue;

        int min_i = min_j + d;
        int max_i = max_j + d;

        // These are the rows intersected by this diagonal
        set<int> blocked;
        for (int r : rows) {
            int c = r - d;
            if (1 <= c && c <= N)
                blocked.insert(r);
        }
        for (int c : cols) {
            int r = d + c;
            if (1 <= r && r <= N)
                blocked.insert(r);
        }

        ans -= (max_j - min_j + 1) - blocked.size();
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
}