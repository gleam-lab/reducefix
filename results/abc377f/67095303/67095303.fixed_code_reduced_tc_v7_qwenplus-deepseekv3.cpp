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

    int unsafe = 0;

    // Rows and columns contribution
    unsafe += rows.size() * N;
    unsafe += cols.size() * N;
    unsafe -= rows.size() * cols.size();

    // Diagonals contribution
    for (auto d : diag1) {
        int min_x = max(1LL, d - N);
        int max_x = min(N, d - 1);
        int len = max_x - min_x + 1;
        unsafe += len;
    }

    for (auto d : diag2) {
        int min_x = max(1LL, 1 + d);
        int max_x = min(N, N + d);
        int len = max_x - min_x + 1;
        unsafe += len;
    }

    // Subtract intersections between rows/columns and diagonals
    for (auto d : diag1) {
        // Intersection with rows
        for (auto r : rows) {
            int c = d - r;
            if (1 <= c && c <= N) {
                unsafe--;
            }
        }
        // Intersection with columns
        for (auto c : cols) {
            int r = d - c;
            if (1 <= r && r <= N) {
                unsafe--;
            }
        }
    }

    for (auto d : diag2) {
        // Intersection with rows
        for (auto r : rows) {
            int c = r - d;
            if (1 <= c && c <= N) {
                unsafe--;
            }
        }
        // Intersection with columns
        for (auto c : cols) {
            int r = d + c;
            if (1 <= r && r <= N) {
                unsafe--;
            }
        }
    }

    // Add back double subtracted intersections (rows, columns, and diagonals)
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            int i = (d1 + d2) / 2;
            int j = (d1 - d2) / 2;
            if ((d1 + d2) % 2 == 0 && (d1 - d2) % 2 == 0 && 1 <= i && i <= N && 1 <= j && j <= N) {
                if (rows.count(i) && cols.count(j)) {
                    unsafe++;
                }
            }
        }
    }

    int total = N * N - M;
    int safe = total - unsafe;
    cout << safe << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int _ = 1;
    while (_--) {
        solve();
    }
    
    return 0;
}