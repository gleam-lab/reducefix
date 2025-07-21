#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;
    
    set<ll> rows, cols, diag1, diag2;
    set<pair<ll, ll>> pieces;
    
    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
        pieces.insert({a, b});
    }
    
    ll unsafe = 0;
    
    // Rows and columns
    unsafe += rows.size() * N;
    unsafe += cols.size() * N;
    unsafe -= rows.size() * cols.size(); // subtract intersections
    
    // Diagonals (a - b)
    for (auto d : diag1) {
        // Calculate the number of squares on the diagonal a - b = d
        ll cnt = 0;
        if (d >= 0) {
            cnt = N - d;
        } else {
            cnt = N + d;
        }
        unsafe += cnt;
    }
    
    // Diagonals (a + b)
    for (auto d : diag2) {
        // Calculate the number of squares on the diagonal a + b = d
        ll cnt = 0;
        if (d <= N + 1) {
            cnt = d - 1;
        } else {
            cnt = 2 * N - d + 1;
        }
        unsafe += cnt;
    }
    
    // Subtract intersections between rows/columns and diagonals
    for (auto a : rows) {
        for (auto d : diag1) {
            ll b = a - d;
            if (b >= 1 && b <= N) {
                if (pieces.find({a, b}) == pieces.end()) {
                    unsafe--;
                }
            }
        }
        for (auto d : diag2) {
            ll b = d - a;
            if (b >= 1 && b <= N) {
                if (pieces.find({a, b}) == pieces.end()) {
                    unsafe--;
                }
            }
        }
    }
    
    for (auto b : cols) {
        for (auto d : diag1) {
            ll a = d + b;
            if (a >= 1 && a <= N) {
                if (pieces.find({a, b}) == pieces.end()) {
                    unsafe--;
                }
            }
        }
        for (auto d : diag2) {
            ll a = d - b;
            if (a >= 1 && a <= N) {
                if (pieces.find({a, b}) == pieces.end()) {
                    unsafe--;
                }
            }
        }
    }
    
    // Subtract intersections between the two diagonals
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            ll a = (d1 + d2) / 2;
            ll b = (d2 - d1) / 2;
            if ((d1 + d2) % 2 == 0 && (d2 - d1) % 2 == 0 && a >= 1 && a <= N && b >= 1 && b <= N) {
                if (pieces.find({a, b}) == pieces.end()) {
                    unsafe--;
                }
            }
        }
    }
    
    // Total safe squares
    ll total = N * N - unsafe;
    cout << total << endl;
    
    return 0;
}