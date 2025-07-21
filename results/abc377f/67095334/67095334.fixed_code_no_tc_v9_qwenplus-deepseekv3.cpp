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

    // Rows and columns
    unsafe += rows.size() * N;
    unsafe += cols.size() * N;
    unsafe -= rows.size() * cols.size(); // Intersection of rows and columns

    // Diagonals (i+j)
    for (auto d : diag1) {
        int min_i = max(1LL, d - N);
        int max_i = min(N, d - 1);
        if (min_i > max_i) continue;
        unsafe += (max_i - min_i + 1);
    }

    // Diagonals (i-j)
    for (auto d : diag2) {
        int min_i = max(1LL, 1 + d);
        int max_i = min(N, N + d);
        if (min_i > max_i) continue;
        unsafe += (max_i - min_i + 1);
    }

    // Subtract intersections of rows and diag1
    for (auto r : rows) {
        for (auto d : diag1) {
            int c = d - r;
            if (1 <= c && c <= N) {
                unsafe--;
            }
        }
    }

    // Subtract intersections of cols and diag1
    for (auto c : cols) {
        for (auto d : diag1) {
            int r = d - c;
            if (1 <= r && r <= N) {
                unsafe--;
            }
        }
    }

    // Subtract intersections of rows and diag2
    for (auto r : rows) {
        for (auto d : diag2) {
            int c = r - d;
            if (1 <= c && c <= N) {
                unsafe--;
            }
        }
    }

    // Subtract intersections of cols and diag2
    for (auto c : cols) {
        for (auto d : diag2) {
            int r = d + c;
            if (1 <= r && r <= N) {
                unsafe--;
            }
        }
    }

    // Add back intersections of rows, cols, and diag1 or diag2 (triple intersections)
    for (auto r : rows) {
        for (auto c : cols) {
            if (diag1.find(r + c) != diag1.end()) {
                unsafe++;
            }
            if (diag2.find(r - c) != diag2.end()) {
                unsafe++;
            }
        }
    }

    int total = N * N;
    int safe = total - unsafe + M; // Adding M because the existing pieces' squares are already counted in unsafe but they are not empty
    cout << safe << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}