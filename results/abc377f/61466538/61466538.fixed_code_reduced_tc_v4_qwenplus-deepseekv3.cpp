#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ll N, M;
    cin >> N >> M;
    vector<pii> queens(M);
    set<ll> rows, cols, diag1, diag2;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        queens[i] = {a, b};
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
    }

    ll total = N * N;
    ll attacked = 0;

    // Rows and columns
    attacked += rows.size() * N;
    attacked += cols.size() * N;
    attacked -= rows.size() * cols.size();

    // Diagonals type 1 (i - j = constant)
    for (auto d : diag1) {
        ll lower = max(1 - d, 1LL);
        ll upper = min(N - d, N);
        ll cnt = upper - lower + 1;
        attacked += cnt;
    }

    // Diagonals type 2 (i + j = constant)
    for (auto d : diag2) {
        ll lower = max(d - N, 1LL);
        ll upper = min(d - 1, N);
        ll cnt = upper - lower + 1;
        attacked += cnt;
    }

    // Intersections between rows/columns and diagonals
    set<pii> intersections;
    for (auto r : rows) {
        for (auto d : diag1) {
            int c = r - d;
            if (1 <= c && c <= N) {
                intersections.insert({r, c});
            }
        }
        for (auto d : diag2) {
            int c = d - r;
            if (1 <= c && c <= N) {
                intersections.insert({r, c});
            }
        }
    }
    for (auto c : cols) {
        for (auto d : diag1) {
            int r = c + d;
            if (1 <= r && r <= N) {
                intersections.insert({r, c});
            }
        }
        for (auto d : diag2) {
            int r = d - c;
            if (1 <= r && r <= N) {
                intersections.insert({r, c});
            }
        }
    }
    // Intersections between diagonals
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            if ((d1 + d2) % 2 != 0) continue;
            int r = (d1 + d2) / 2;
            int c = (d2 - d1) / 2;
            if (1 <= r && r <= N && 1 <= c && c <= N) {
                intersections.insert({r, c});
            }
        }
    }
    attacked -= intersections.size();

    // Subtract the original queens positions as they are not empty
    total -= M;

    // Safe squares are total squares minus attacked squares plus intersections
    ll safe = total - (attacked - M);
    cout << safe << endl;

    return 0;
}