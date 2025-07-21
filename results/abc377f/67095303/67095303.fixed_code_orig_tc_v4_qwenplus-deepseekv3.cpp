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

    int total_forbidden = 0;

    // Rows and columns
    total_forbidden += rows.size() * N;
    total_forbidden += cols.size() * N;
    total_forbidden -= rows.size() * cols.size();

    // Diagonals
    for (int d : diag1) {
        int min_i = max(1LL, d - N);
        int max_i = min(N, d - 1);
        int cnt = max_i - min_i + 1;
        total_forbidden += cnt;

        // Subtract intersections with rows and columns
        for (int a : rows) {
            int b = d - a;
            if (1 <= b && b <= N) {
                total_forbidden--;
            }
        }
        for (int b : cols) {
            int a = d - b;
            if (1 <= a && a <= N) {
                total_forbidden--;
            }
        }
    }

    for (int d : diag2) {
        int min_i = max(1LL, 1 - d);
        int max_i = min(N, N - d);
        int cnt = max_i - min_i + 1;
        total_forbidden += cnt;

        // Subtract intersections with rows and columns
        for (int a : rows) {
            int b = a - d;
            if (1 <= b && b <= N) {
                total_forbidden--;
            }
        }
        for (int b : cols) {
            int a = d + b;
            if (1 <= a && a <= N) {
                total_forbidden--;
            }
        }
    }

    // Subtract intersections between diag1 and diag2
    for (int d1 : diag1) {
        for (int d2 : diag2) {
            if ((d1 + d2) % 2 == 0 && (d1 - d2) % 2 == 0) {
                int i = (d1 + d2) / 2;
                int j = (d1 - d2) / 2;
                if (1 <= i && i <= N && 1 <= j && j <= N) {
                    total_forbidden--;
                }
            }
        }
    }

    // Add back the occupied squares which were subtracted multiple times
    total_forbidden += M;

    int total_squares = N * N;
    int answer = total_squares - total_forbidden;
    cout << answer << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}