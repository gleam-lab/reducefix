#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    set<int> rows, cols, diag1, diag2;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }

    // Total safe squares: N^2 - M - (forbidden)
    int forbidden = 0;

    // Rows and columns
    forbidden += rows.size() * N;
    forbidden += cols.size() * (N - rows.size());

    // Diagonals: i + j = d and i - j = d
    for (int d : diag1) {
        // Number of squares on i + j = d
        int cnt = min(d - 1, 2 * N - d + 1);
        if (d <= N + 1) cnt = d - 1;
        else cnt = 2 * N - d + 1;
        // Subtract squares already forbidden by rows or columns
        int intersect = 0;
        for (int r : rows) {
            int c = d - r;
            if (1 <= c && c <= N) ++intersect;
        }
        for (int c : cols) {
            int r = d - c;
            if (1 <= r && r <= N) ++intersect;
        }
        cnt -= intersect;
        forbidden += max(0LL, cnt);
    }

    for (int d : diag2) {
        // Number of squares on i - j = d
        int cnt;
        if (d >= 0) cnt = N - d;
        else cnt = N + d;
        // Subtract squares already forbidden by rows or columns
        int intersect = 0;
        for (int r : rows) {
            int c = r - d;
            if (1 <= c && c <= N) ++intersect;
        }
        for (int c : cols) {
            int r = d + c;
            if (1 <= r && r <= N) ++intersect;
        }
        cnt -= intersect;
        forbidden += max(0LL, cnt);
    }

    // Subtract intersections of diag1 and diag2
    for (int d1 : diag1) {
        for (int d2 : diag2) {
            if ((d1 + d2) % 2 != 0) continue;
            int i = (d1 + d2) / 2;
            int j = (d1 - d2) / 2;
            if (1 <= i && i <= N && 1 <= j && j <= N) {
                if (rows.count(i) || cols.count(j)) continue;
                if (diag1.count(i + j) && diag2.count(i - j)) {
                    forbidden--;
                }
            }
        }
    }

    int total_empty = N * N - M;
    int safe = total_empty - forbidden;
    cout << safe << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    while (_--) solve();
    return 0;
}