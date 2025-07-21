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

    unordered_set<ll> rows, cols, diag1, diag2;
    for (auto &q : queens) {
        ll i = q.first;
        ll j = q.second;
        rows.insert(i);
        cols.insert(j);
        diag1.insert(i - j);
        diag2.insert(i + j);
    }

    ll unsafe = 0;

    // Rows and columns
    unsafe += rows.size() * N;
    unsafe += cols.size() * N;
    unsafe -= rows.size() * cols.size();

    // Diagonals i-j = d
    for (ll d : diag1) {
        ll cnt = N - abs(d);
        unsafe += cnt;
    }

    // Diagonals i+j = d
    for (ll d : diag2) {
        ll cnt;
        if (d <= N + 1) {
            cnt = d - 1;
        } else {
            cnt = 2 * N - d + 1;
        }
        unsafe += cnt;
    }

    // Subtract intersections between rows/columns and diagonals
    // Also subtract intersections between diagonals
    set<pll> intersections;

    // Intersections between rows and diag1 (i-j = d)
    for (ll r : rows) {
        for (ll d : diag1) {
            ll j = r - d;
            if (1 <= j && j <= N) {
                intersections.insert({r, j});
            }
        }
    }

    // Intersections between columns and diag1 (i-j = d)
    for (ll c : cols) {
        for (ll d : diag1) {
            ll i = c + d;
            if (1 <= i && i <= N) {
                intersections.insert({i, c});
            }
        }
    }

    // Intersections between rows and diag2 (i+j = d)
    for (ll r : rows) {
        for (ll d : diag2) {
            ll j = d - r;
            if (1 <= j && j <= N) {
                intersections.insert({r, j});
            }
        }
    }

    // Intersections between columns and diag2 (i+j = d)
    for (ll c : cols) {
        for (ll d : diag2) {
            ll i = d - c;
            if (1 <= i && i <= N) {
                intersections.insert({i, c});
            }
        }
    }

    // Intersections between diag1 and diag2
    for (ll d1 : diag1) {
        for (ll d2 : diag2) {
            ll i = (d1 + d2) / 2;
            ll j = (d2 - d1) / 2;
            if ((d1 + d2) % 2 == 0 && (d2 - d1) % 2 == 0) {
                if (1 <= i && i <= N && 1 <= j && j <= N) {
                    intersections.insert({i, j});
                }
            }
        }
    }

    unsafe -= intersections.size();

    // Total safe squares
    ll total = N * N - unsafe - M; // Subtract M for the squares already occupied by queens
    cout << total << '\n';

    return 0;
}