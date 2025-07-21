#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;
    vector<pair<ll, ll>> pieces(M);
    set<ll> rows, cols, diag1, diag2;
    for (int i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
        rows.insert(pieces[i].first);
        cols.insert(pieces[i].second);
        diag1.insert(pieces[i].first - pieces[i].second);
        diag2.insert(pieces[i].first + pieces[i].second);
    }

    ll unsafe = 0;

    // Rows and columns
    unsafe += rows.size() * N;
    unsafe += cols.size() * N;
    unsafe -= rows.size() * cols.size(); // subtract intersections

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
    for (auto d : diag2) {
        ll cnt;
        if (d <= N + 1) {
            cnt = d - 1;
        } else {
            cnt = 2 * N - d + 1;
        }
        unsafe += cnt;
    }

    // Subtract intersections between rows/columns and diagonals
    set<pair<ll, ll>> intersections;
    for (auto r : rows) {
        for (auto d1 : diag1) {
            ll c = r - d1;
            if (1 <= c && c <= N) {
                intersections.insert({r, c});
            }
        }
        for (auto d2 : diag2) {
            ll c = d2 - r;
            if (1 <= c && c <= N) {
                intersections.insert({r, c});
            }
        }
    }
    for (auto c : cols) {
        for (auto d1 : diag1) {
            ll r = c + d1;
            if (1 <= r && r <= N) {
                intersections.insert({r, c});
            }
        }
        for (auto d2 : diag2) {
            ll r = d2 - c;
            if (1 <= r && r <= N) {
                intersections.insert({r, c});
            }
        }
    }
    unsafe -= intersections.size();

    // Subtract intersections between the two diagonals
    set<pair<ll, ll>> diag_intersections;
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            ll i = (d1 + d2) / 2;
            ll j = (d2 - d1) / 2;
            if ((d1 + d2) % 2 == 0 && (d2 - d1) % 2 == 0) {
                if (1 <= i && i <= N && 1 <= j && j <= N) {
                    diag_intersections.insert({i, j});
                }
            }
        }
    }
    unsafe -= diag_intersections.size();

    // Add back intersections counted in both previous steps
    set<pair<ll, ll>> all_intersections;
    for (auto p : intersections) {
        all_intersections.insert(p);
    }
    for (auto p : diag_intersections) {
        all_intersections.insert(p);
    }
    unsafe += all_intersections.size();

    // Ensure we don't count existing pieces again
    unsafe -= M;

    ll total_squares = N * N;
    ll safe_squares = total_squares - unsafe;
    cout << max(safe_squares, 0LL) << endl;

    return 0;
}