#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll N, M;
    cin >> N >> M;
    vector<pll> queens(M);
    for (int i = 0; i < M; ++i) {
        cin >> queens[i].first >> queens[i].second;
    }

    set<ll> rows, cols, diag1, diag2;
    for (auto &queen : queens) {
        ll i = queen.first;
        ll j = queen.second;
        rows.insert(i);
        cols.insert(j);
        diag1.insert(i - j);
        diag2.insert(i + j);
    }

    ll total = N * N;
    ll attacked = 0;

    // Rows and columns
    attacked += rows.size() * N;
    attacked += cols.size() * N;
    // Subtract intersections of rows and columns
    attacked -= rows.size() * cols.size();

    // Diagonals (i - j)
    for (auto &d : diag1) {
        ll count;
        if (d >= 0) {
            count = N - d;
        } else {
            count = N + d;
        }
        attacked += count;
    }

    // Anti-diagonals (i + j)
    for (auto &d : diag2) {
        ll count;
        if (d <= N + 1) {
            count = d - 1;
        } else {
            count = 2 * N - d + 1;
        }
        attacked += count;
    }

    // Subtract intersections of diagonals and anti-diagonals
    set<pll> intersections;
    for (auto &d1 : diag1) {
        for (auto &d2 : diag2) {
            ll i = (d1 + d2) / 2;
            ll j = (d2 - d1) / 2;
            if ((d1 + d2) % 2 == 0 && i >= 1 && i <= N && j >= 1 && j <= N) {
                intersections.insert({i, j});
            }
        }
    }
    attacked -= intersections.size();

    // Add back intersections of rows/columns with diagonals/anti-diagonals
    set<pll> row_col_diag;
    for (auto &i : rows) {
        for (auto &d : diag1) {
            ll j = i - d;
            if (j >= 1 && j <= N) {
                row_col_diag.insert({i, j});
            }
        }
        for (auto &d : diag2) {
            ll j = d - i;
            if (j >= 1 && j <= N) {
                row_col_diag.insert({i, j});
            }
        }
    }
    for (auto &j : cols) {
        for (auto &d : diag1) {
            ll i = j + d;
            if (i >= 1 && i <= N) {
                row_col_diag.insert({i, j});
            }
        }
        for (auto &d : diag2) {
            ll i = d - j;
            if (i >= 1 && i <= N) {
                row_col_diag.insert({i, j});
            }
        }
    }
    attacked -= row_col_diag.size();

    // Add back intersections counted in row_col_diag and intersections
    set<pll> triple_intersections;
    for (auto &p : row_col_diag) {
        if (intersections.find(p) != intersections.end()) {
            triple_intersections.insert(p);
        }
    }
    attacked += triple_intersections.size();

    // Subtract the squares occupied by queens
    attacked -= M;

    ll safe = total - attacked;
    cout << safe << endl;

    return 0;
}