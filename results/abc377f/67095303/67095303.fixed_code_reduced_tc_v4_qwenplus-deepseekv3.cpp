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

    int forbidden = 0;
    forbidden += rows.size() * N;
    forbidden += cols.size() * N;
    forbidden -= rows.size() * cols.size();

    for (auto d : diag1) {
        int min_x_plus_y = max(1LL, d - N);
        int max_x_plus_y = min(N, d - 1);
        int length = max_x_plus_y - min_x_plus_y + 1;
        forbidden += length;
    }

    for (auto d : diag2) {
        int min_x_minus_y = max(1LL, 1 - d);
        int max_x_minus_y = min(N, N - d);
        int length = max_x_minus_y - min_x_minus_y + 1;
        forbidden += length;
    }

    for (auto r : rows) {
        for (auto d1 : diag1) {
            int c = d1 - r;
            if (cols.count(c)) {
                forbidden--;
            }
        }
        for (auto d2 : diag2) {
            int c = r - d2;
            if (cols.count(c)) {
                forbidden--;
            }
        }
    }

    for (auto c : cols) {
        for (auto d1 : diag1) {
            int r = d1 - c;
            if (rows.count(r)) {
                forbidden--;
            }
        }
        for (auto d2 : diag2) {
            int r = d2 + c;
            if (rows.count(r)) {
                forbidden--;
            }
        }
    }

    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            if ((d1 + d2) % 2 == 0) {
                int r = (d1 + d2) / 2;
                int c = (d1 - d2) / 2;
                if (rows.count(r) && cols.count(c)) {
                    forbidden++;
                }
            }
        }
    }

    int total = N * N - M;
    int safe = total - forbidden;
    cout << safe << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}