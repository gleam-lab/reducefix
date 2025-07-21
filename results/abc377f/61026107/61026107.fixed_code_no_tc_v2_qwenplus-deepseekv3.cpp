#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    ll N, M;
    cin >> N >> M;
    unordered_set<ll> rows, cols, diag1, diag2;
    unordered_set<string> pieces;

    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
        pieces.insert(to_string(a) + "," + to_string(b));
    }

    ll total = N * N - M;
    ll attacked = 0;

    // Rows
    attacked += rows.size() * N;
    // Columns
    attacked += cols.size() * N;
    // Diagonals (a - b = constant)
    for (auto d : diag1) {
        ll cnt;
        if (d >= 0) {
            cnt = N - d;
        } else {
            cnt = N + d;
        }
        attacked += cnt;
    }
    // Anti-diagonals (a + b = constant)
    for (auto d : diag2) {
        ll cnt;
        if (d <= N + 1) {
            cnt = d - 1;
        } else {
            cnt = 2 * N - d + 1;
        }
        attacked += cnt;
    }

    // Subtract intersections: row and column
    for (auto r : rows) {
        for (auto c : cols) {
            if (pieces.find(to_string(r) + "," + to_string(c)) == pieces.end()) {
                attacked--;
            }
        }
    }

    // Subtract intersections: row and diagonal (a - b)
    for (auto r : rows) {
        for (auto d : diag1) {
            ll c = r - d;
            if (c >= 1 && c <= N && pieces.find(to_string(r) + "," + to_string(c)) == pieces.end()) {
                attacked--;
            }
        }
    }

    // Subtract intersections: row and anti-diagonal (a + b)
    for (auto r : rows) {
        for (auto d : diag2) {
            ll c = d - r;
            if (c >= 1 && c <= N && pieces.find(to_string(r) + "," + to_string(c)) == pieces.end()) {
                attacked--;
            }
        }
    }

    // Subtract intersections: column and diagonal (a - b)
    for (auto c : cols) {
        for (auto d : diag1) {
            ll r = d + c;
            if (r >= 1 && r <= N && pieces.find(to_string(r) + "," + to_string(c)) == pieces.end()) {
                attacked--;
            }
        }
    }

    // Subtract intersections: column and anti-diagonal (a + b)
    for (auto c : cols) {
        for (auto d : diag2) {
            ll r = d - c;
            if (r >= 1 && r <= N && pieces.find(to_string(r) + "," + to_string(c)) == pieces.end()) {
                attacked--;
            }
        }
    }

    // Subtract intersections: diagonal (a - b) and anti-diagonal (a + b)
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            if ((d1 + d2) % 2 != 0) continue;
            ll r = (d1 + d2) / 2;
            ll c = (d2 - d1) / 2;
            if (r >= 1 && r <= N && c >= 1 && c <= N && pieces.find(to_string(r) + "," + to_string(c)) == pieces.end()) {
                attacked--;
            }
        }
    }

    // Add triple intersections (row, column, diagonal or anti-diagonal)
    for (auto r : rows) {
        for (auto c : cols) {
            string key = to_string(r) + "," + to_string(c);
            if (pieces.find(key) != pieces.end()) continue;
            bool in_diag1 = (diag1.find(r - c) != diag1.end());
            bool in_diag2 = (diag2.find(r + c) != diag2.end());
            if (in_diag1 && in_diag2) {
                attacked += 2;
            } else if (in_diag1 || in_diag2) {
                attacked += 1;
            }
        }
    }

    ll safe = total - attacked;
    cout << safe << "\n";

    return 0;
}