#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;
    set<ll> rows, cols, diag1, diag2;
    set<pair<ll, ll>> queens;

    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        queens.insert({a, b});
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
    }

    ll total = N * N;
    ll unsafe = 0;

    // Rows and columns
    unsafe += rows.size() * N;
    unsafe += cols.size() * N;
    unsafe -= rows.size() * cols.size();

    // Diagonals (a - b)
    for (auto d : diag1) {
        ll cnt;
        if (d >= 0) {
            cnt = N - d;
        } else {
            cnt = N + d;
        }
        unsafe += cnt;

        // Subtract intersections with rows and columns
        set<pair<ll, ll>> intersections;
        for (auto r : rows) {
            ll c = r - d;
            if (1 <= c && c <= N) {
                intersections.insert({r, c});
            }
        }
        for (auto c : cols) {
            ll r = c + d;
            if (1 <= r && r <= N) {
                intersections.insert({r, c});
            }
        }
        unsafe -= intersections.size();
    }

    // Anti-diagonals (a + b)
    for (auto d : diag2) {
        ll cnt;
        if (d <= N + 1) {
            cnt = d - 1;
        } else {
            cnt = 2 * N - d + 1;
        }
        unsafe += cnt;

        // Subtract intersections with rows and columns
        set<pair<ll, ll>> intersections;
        for (auto r : rows) {
            ll c = d - r;
            if (1 <= c && c <= N) {
                intersections.insert({r, c});
            }
        }
        for (auto c : cols) {
            ll r = d - c;
            if (1 <= r && r <= N) {
                intersections.insert({r, c});
            }
        }
        unsafe -= intersections.size();
    }

    // Add back squares that are in both diagonals and anti-diagonals of the same queen
    for (auto q : queens) {
        ll a = q.first, b = q.second;
        ll d1 = a - b;
        ll d2 = a + b;
        
        // Check if this square is in both diag1 and diag2 sets
        if (diag1.find(d1) != diag1.end() && diag2.find(d2) != diag2.end()) {
            unsafe++;
        }
    }

    // Subtract the squares where queens are already placed since they are not empty
    unsafe -= M;

    ll safe = total - unsafe;
    cout << safe << endl;

    return 0;
}