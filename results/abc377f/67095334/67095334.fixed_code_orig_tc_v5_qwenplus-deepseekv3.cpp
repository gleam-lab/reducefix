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
    unsafe += rows.size() * N;
    unsafe += cols.size() * N;
    unsafe -= rows.size() * cols.size(); // subtract intersections counted twice

    for (auto d : diag1) {
        int cnt;
        if (d <= N + 1) {
            cnt = d - 1;
        } else {
            cnt = 2 * N - d + 1;
        }
        unsafe += cnt;
    }

    for (auto d : diag2) {
        int cnt;
        if (d >= 0) {
            cnt = N - d;
        } else {
            cnt = N + d;
        }
        unsafe += cnt;
    }

    // Subtract intersections between diag1 and rows/cols
    for (auto d : diag1) {
        for (auto r : rows) {
            if (1 <= d - r && d - r <= N) {
                unsafe--;
            }
        }
        for (auto c : cols) {
            if (1 <= d - c && d - c <= N) {
                unsafe--;
            }
        }
    }

    // Subtract intersections between diag2 and rows/cols
    for (auto d : diag2) {
        for (auto r : rows) {
            if (1 <= r - d && r - d <= N) {
                unsafe--;
            }
        }
        for (auto c : cols) {
            if (1 <= c + d && c + d <= N) {
                unsafe--;
            }
        }
    }

    // Subtract intersections between diag1 and diag2
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            if ((d1 + d2) % 2 == 0 && (d1 - d2) % 2 == 0) {
                int i = (d1 + d2) / 2;
                int j = (d1 - d2) / 2;
                if (1 <= i && i <= N && 1 <= j && j <= N) {
                    unsafe--;
                }
            }
        }
    }

    int total = N * N;
    int safe = total - unsafe;
    cout << safe << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}