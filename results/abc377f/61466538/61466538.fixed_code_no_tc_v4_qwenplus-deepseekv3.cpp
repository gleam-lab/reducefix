#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;
    vector<pair<ll, ll>> queens(M);
    set<ll> rows, cols, diag1, diag2;
    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        queens[i] = {a, b};
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
    }

    ll unsafe = 0;

    // Rows and columns
    unsafe += rows.size() * N;
    unsafe += cols.size() * N;
    unsafe -= rows.size() * cols.size();

    // Diagonals (i - j)
    for (auto d : diag1) {
        ll cnt;
        if (d >= 0) {
            cnt = N - d;
        } else {
            cnt = N + d;
        }
        unsafe += cnt;
    }

    // Diagonals (i + j)
    for (auto s : diag2) {
        ll cnt;
        if (s <= N + 1) {
            cnt = s - 1;
        } else {
            cnt = 2 * N - s + 1;
        }
        unsafe += cnt;
    }

    // Remove overlaps between rows/columns and diagonals
    set<pair<ll, ll>> intersections;
    for (auto q : queens) {
        intersections.insert(q);
    }
    for (auto d : diag1) {
        for (auto r : rows) {
            ll c = r - d;
            if (c >= 1 && c <= N) {
                intersections.insert({r, c});
            }
        }
        for (auto c : cols) {
            ll r = c + d;
            if (r >= 1 && r <= N) {
                intersections.insert({r, c});
            }
        }
    }
    for (auto s : diag2) {
        for (auto r : rows) {
            ll c = s - r;
            if (c >= 1 && c <= N) {
                intersections.insert({r, c});
            }
        }
        for (auto c : cols) {
            ll r = s - c;
            if (r >= 1 && r <= N) {
                intersections.insert({r, c});
            }
        }
        for (auto d : diag1) {
            ll r = (s + d) / 2;
            ll c = (s - d) / 2;
            if ((s + d) % 2 == 0 && (s - d) % 2 == 0 && r >= 1 && r <= N && c >= 1 && c <= N) {
                intersections.insert({r, c});
            }
        }
    }
    unsafe -= intersections.size();

    ll total = N * N;
    ll safe = total - unsafe;

    cout << safe << endl;

    return 0;
}