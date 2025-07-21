#include <bits/stdc++.h>

using namespace std;

int main() {
    long long N;
    int M;
    cin >> N >> M;

    vector<int> row(M), col(M);
    vector<int> diag1(M), diag2(M); // diag1 = x - y; diag2 = x + y

    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        row[i] = x;
        col[i] = y;
        diag1[i] = x - y;
        diag2[i] = x + y;
    }

    // Deduplicate
    sort(row.begin(), row.end());
    row.erase(unique(row.begin(), row.end()), row.end());

    sort(col.begin(), col.end());
    col.erase(unique(col.begin(), col.end()), col.end());

    sort(diag1.begin(), diag1.end());
    diag1.erase(unique(diag1.begin(), diag1.end()), diag1.end());

    sort(diag2.begin(), diag2.end());
    diag2.erase(unique(diag2.begin(), diag2.end()), diag2.end());

    long long ans = N * N;

    // Remove rows and columns
    ans -= 1LL * N * (row.size() + col.size());
    // Add back intersections of row and column
    ans += 1LL * row.size() * col.size();

    // Remove diagonals
    ans -= 1LL * N * (diag1.size() + diag2.size());
    // Add back intersections with rows and cols
    for (int d : diag1) {
        int lo = max(1 - d, 1);
        int hi = min(N - d, N);
        int cnt = hi - lo + 1;
        ans += cnt;
    }
    for (int d : diag2) {
        int lo = max(d - N, 1);
        int hi = min(d - 1, N);
        int cnt = hi - lo + 1;
        ans += cnt;
    }

    // Inclusion-Exclusion for overlaps
    // Overlap between diag1 and diag2
    for (int d1 : diag1) {
        for (int d2 : diag2) {
            if ((d1 + d2) % 2 != 0) continue;
            int x = (d2 - d1) / 2;
            int y = (d2 + d1) / 2;
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                bool in_row = binary_search(row.begin(), row.end(), y);
                bool in_col = binary_search(col.begin(), col.end(), x);
                int overlap = in_row + in_col + 1;
                ans += overlap;
            }
        }
    }

    cout << ans << endl;
}