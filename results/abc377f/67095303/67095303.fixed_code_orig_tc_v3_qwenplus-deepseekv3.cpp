#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    set<int> rows, cols, diag1, diag2; // diag1: i+j, diag2: i-j
    
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }
    
    int total = N * N;
    int attacked = 0;
    
    // Rows and columns
    attacked += rows.size() * N;
    attacked += cols.size() * N;
    attacked -= rows.size() * cols.size();
    
    // Diagonals (i+j)
    for (auto d : diag1) {
        int cnt = 0;
        if (d <= N + 1) {
            cnt = d - 1;
        } else {
            cnt = 2 * N - d + 1;
        }
        attacked += cnt;
    }
    
    // Diagonals (i-j)
    for (auto d : diag2) {
        int cnt = 0;
        if (d >= 0) {
            cnt = N - d;
        } else {
            cnt = N + d;
        }
        attacked += cnt;
    }
    
    // Subtract intersections between rows/columns and diagonals
    for (auto d : diag1) {
        for (auto r : rows) {
            int c = d - r;
            if (c >= 1 && c <= N) {
                attacked--;
            }
        }
        for (auto c : cols) {
            int r = d - c;
            if (r >= 1 && r <= N) {
                attacked--;
            }
        }
    }
    
    for (auto d : diag2) {
        for (auto r : rows) {
            int c = r - d;
            if (c >= 1 && c <= N) {
                attacked--;
            }
        }
        for (auto c : cols) {
            int r = c + d;
            if (r >= 1 && r <= N) {
                attacked--;
            }
        }
    }
    
    // Add back intersections between diagonals that were subtracted twice
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            if ((d1 + d2) % 2 == 0 && (d1 - d2) % 2 == 0) {
                int i = (d1 + d2) / 2;
                int j = (d1 - d2) / 2;
                if (i >= 1 && i <= N && j >= 1 && j <= N) {
                    attacked++;
                }
            }
        }
    }
    
    int safe = total - attacked;
    cout << safe << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    
    return 0;
}