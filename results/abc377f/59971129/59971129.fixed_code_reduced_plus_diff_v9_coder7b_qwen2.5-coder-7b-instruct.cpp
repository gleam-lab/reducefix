#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m;
    cin >> n >> m;

    set<long long> attacked_rows, attacked_cols, attacked_diag1, attacked_diag2;

    rep(i, m) {
        long long a, b;
        cin >> a >> b;
        attacked_rows.insert(a);
        attacked_cols.insert(b);
        attacked_diag1.insert(a + b);
        attacked_diag2.insert(a - b);
    }

    long long total_squares = n * n;
    long long attacked_squares = attacked_rows.size() + attacked_cols.size()
                                + attacked_diag1.size() + attacked_diag2.size();

    // Subtract intersections (squares counted multiple times)
    for (auto& a : attacked_rows) {
        for (auto& b : attacked_cols) {
            if ((a + b) != (a - b)) {
                attacked_squares--;
            }
        }
    }
    for (auto& a : attacked_rows) {
        for (auto& d1 : attacked_diag1) {
            if (d1 == a + a) {
                attacked_squares--;
            }
        }
    }
    for (auto& b : attacked_cols) {
        for (auto& d2 : attacked_diag2) {
            if (d2 == b - b) {
                attacked_squares--;
            }
        }
    }
    for (auto& d1 : attacked_diag1) {
        for (auto& d2 : attacked_diag2) {
            if (d1 == d2) {
                attacked_squares--;
            }
        }
    }

    cout << total_squares - attacked_squares << endl;

    return 0;
}