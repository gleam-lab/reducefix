#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cout.precision(12);

    ll N, M;
    cin >> N >> M;

    if (M == 0) {
        cout << N * N << "\n";
        return 0;
    }

    set<ll> rows, cols, diag1, diag2;
    vector<pair<ll, ll>> pieces(M);

    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
    }

    ll forbidden = 0;

    // Squares forbidden by rows
    forbidden += rows.size() * N;

    // Squares forbidden by columns
    forbidden += cols.size() * N;

    // Squares forbidden by diagonals (a - b = constant)
    for (auto d : diag1) {
        ll x_min = max(1LL, 1 + d);
        ll x_max = min(N, N + d);
        ll count = x_max - x_min + 1;
        forbidden += count;
    }

    // Squares forbidden by anti-diagonals (a + b = constant)
    for (auto d : diag2) {
        ll x_min = max(1LL, d - N);
        ll x_max = min(N, d - 1);
        ll count = x_max - x_min + 1;
        forbidden += count;
    }

    // Now, subtract overlaps counted multiple times.
    // Intersections between rows and columns
    for (auto r : rows) {
        for (auto c : cols) {
            if (diag1.count(r - c) && diag2.count(r + c)) {
                forbidden -= 3;
            } else if (diag1.count(r - c) || diag2.count(r + c)) {
                forbidden -= 2;
            } else {
                forbidden -= 1;
            }
        }
    }

    // Intersections between rows and diagonals (a - b)
    for (auto r : rows) {
        for (auto d : diag1) {
            ll b = r - d;
            if (b >= 1 && b <= N) {
                forbidden -= 1;
                if (cols.count(b) && diag2.count(r + b)) {
                    forbidden += 1;
                }
            }
        }
    }

    // Intersections between rows and anti-diagonals (a + b)
    for (auto r : rows) {
        for (auto d : diag2) {
            ll b = d - r;
            if (b >= 1 && b <= N) {
                forbidden -= 1;
                if (cols.count(b) && diag1.count(r - b)) {
                    forbidden += 1;
                }
            }
        }
    }

    // Intersections between columns and diagonals (a - b)
    for (auto c : cols) {
        for (auto d : diag1) {
            ll a = c + d;
            if (a >= 1 && a <= N) {
                forbidden -= 1;
                if (rows.count(a) && diag2.count(a + c)) {
                    forbidden += 1;
                }
            }
        }
    }

    // Intersections between columns and anti-diagonals (a + b)
    for (auto c : cols) {
        for (auto d : diag2) {
            ll a = d - c;
            if (a >= 1 && a <= N) {
                forbidden -= 1;
                if (rows.count(a) && diag1.count(a - c)) {
                    forbidden += 1;
                }
            }
        }
    }

    // Intersections between diagonals and anti-diagonals
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            if ((d1 + d2) % 2 != 0) continue;
            ll a = (d1 + d2) / 2;
            ll b = (d2 - d1) / 2;
            if (a >= 1 && a <= N && b >= 1 && b <= N) {
                forbidden -= 1;
                if (rows.count(a) && cols.count(b)) {
                    forbidden += 1;
                }
            }
        }
    }

    ll safe = N * N - forbidden;
    cout << safe << "\n";

    return 0;
}