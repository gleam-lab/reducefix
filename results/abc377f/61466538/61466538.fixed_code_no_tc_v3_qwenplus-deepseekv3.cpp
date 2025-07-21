#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

int main() {
    ll N, M;
    cin >> N >> M;
    vector<pll> queens(M);
    unordered_set<ll> rows, cols, diag1, diag2;
    for (ll i = 0; i < M; ++i) {
        cin >> queens[i].first >> queens[i].second;
        rows.insert(queens[i].first);
        cols.insert(queens[i].second);
        diag1.insert(queens[i].first - queens[i].second);
        diag2.insert(queens[i].first + queens[i].second);
    }

    ll total_attacked = 0;

    // Rows and columns
    total_attacked += rows.size() * N;
    total_attacked += cols.size() * N;
    total_attacked -= rows.size() * cols.size();

    // Diagonals (i - j = d1)
    for (ll d : diag1) {
        ll cnt;
        if (d >= 0) {
            cnt = N - d;
        } else {
            cnt = N + d;
        }
        total_attacked += cnt;
    }

    // Diagonals (i + j = d2)
    for (ll d : diag2) {
        ll cnt;
        if (d <= N + 1) {
            cnt = d - 1;
        } else {
            cnt = 2 * N - d + 1;
        }
        total_attacked += cnt;
    }

    // Subtract intersections between rows/columns and diagonals
    for (ll d : diag1) {
        unordered_set<pll> intersections;
        // Intersection with rows
        for (ll r : rows) {
            ll c = r - d;
            if (c >= 1 && c <= N) {
                intersections.insert({r, c});
            }
        }
        // Intersection with columns
        for (ll c : cols) {
            ll r = c + d;
            if (r >= 1 && r <= N) {
                intersections.insert({r, c});
            }
        }
        total_attacked -= intersections.size();
    }

    for (ll d : diag2) {
        unordered_set<pll> intersections;
        // Intersection with rows
        for (ll r : rows) {
            ll c = d - r;
            if (c >= 1 && c <= N) {
                intersections.insert({r, c});
            }
        }
        // Intersection with columns
        for (ll c : cols) {
            ll r = d - c;
            if (r >= 1 && r <= N) {
                intersections.insert({r, c});
            }
        }
        total_attacked -= intersections.size();
    }

    // Add back intersections between both diagonals (squares attacked by both diagonals)
    unordered_set<pll> diag_intersections;
    for (ll d1 : diag1) {
        for (ll d2 : diag2) {
            ll x = (d1 + d2) / 2;
            ll y = (d2 - d1) / 2;
            if ((d1 + d2) % 2 == 0 && (d2 - d1) % 2 == 0) {
                if (x >= 1 && x <= N && y >= 1 && y <= N) {
                    diag_intersections.insert({x, y});
                }
            }
        }
    }
    total_attacked += diag_intersections.size();

    // Subtract the squares where queens are already placed (since they are not empty)
    total_attacked -= M;

    ll total_safe = N * N - total_attacked;
    cout << total_safe << endl;

    return 0;
}