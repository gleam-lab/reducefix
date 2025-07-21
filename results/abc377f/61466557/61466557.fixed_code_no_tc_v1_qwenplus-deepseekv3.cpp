#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;
    set<ll> rows, cols, diag1, diag2;
    set<pair<ll, ll>> queens;
    
    for (ll i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
        queens.insert({a, b});
    }
    
    ll unsafe = 0;
    
    // Rows and columns
    unsafe += rows.size() * N;
    unsafe += cols.size() * N;
    unsafe -= rows.size() * cols.size(); // compensate for intersections
    
    // Diagonals i-j = d
    for (auto d : diag1) {
        ll cnt;
        if (d >= 0) {
            cnt = N - d;
        } else {
            cnt = N + d;
        }
        unsafe += cnt;
    }
    
    // Diagonals i+j = d
    for (auto d : diag2) {
        ll cnt;
        if (d <= N + 1) {
            cnt = d - 1;
        } else {
            cnt = 2 * N - d + 1;
        }
        unsafe += cnt;
    }
    
    // Compensate for squares counted multiple times
    // Intersections between rows and i-j diagonals
    for (auto r : rows) {
        for (auto d : diag1) {
            ll c = r - d;
            if (c >= 1 && c <= N) {
                if (queens.find({r, c}) == queens.end()) {
                    unsafe--;
                }
            }
        }
    }
    
    // Intersections between columns and i-j diagonals
    for (auto c : cols) {
        for (auto d : diag1) {
            ll r = d + c;
            if (r >= 1 && r <= N) {
                if (queens.find({r, c}) == queens.end()) {
                    unsafe--;
                }
            }
        }
    }
    
    // Intersections between rows and i+j diagonals
    for (auto r : rows) {
        for (auto d : diag2) {
            ll c = d - r;
            if (c >= 1 && c <= N) {
                if (queens.find({r, c}) == queens.end()) {
                    unsafe--;
                }
            }
        }
    }
    
    // Intersections between columns and i+j diagonals
    for (auto c : cols) {
        for (auto d : diag2) {
            ll r = d - c;
            if (r >= 1 && r <= N) {
                if (queens.find({r, c}) == queens.end()) {
                    unsafe--;
                }
            }
        }
    }
    
    // Intersections between i-j and i+j diagonals
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            ll i = (d1 + d2) / 2;
            ll j = (d2 - d1) / 2;
            if ((d1 + d2) % 2 == 0 && (d2 - d1) % 2 == 0) {
                if (i >= 1 && i <= N && j >= 1 && j <= N) {
                    if (queens.find({i, j}) == queens.end()) {
                        unsafe--;
                    }
                }
            }
        }
    }
    
    // The total safe squares
    ll total = N * N - M - unsafe;
    cout << total << endl;
    
    return 0;
}