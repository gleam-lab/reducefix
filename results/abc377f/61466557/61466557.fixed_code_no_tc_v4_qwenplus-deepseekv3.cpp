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
    
    ll total_attacked = 0;
    
    // Rows and columns
    total_attacked += rows.size() * N;
    total_attacked += cols.size() * N;
    total_attacked -= rows.size() * cols.size(); // Subtract intersections
    
    // Diagonals (d1: i - j, d2: i + j)
    for (ll d : diag1) {
        ll cnt;
        if (d >= 0) {
            cnt = N - d;
        } else {
            cnt = N + d;
        }
        total_attacked += cnt;
    }
    
    for (ll d : diag2) {
        ll cnt;
        if (d <= N + 1) {
            cnt = d - 1;
        } else {
            cnt = 2 * N - d + 1;
        }
        total_attacked += cnt;
    }
    
    // Subtract intersections between diagonals and rows/columns
    for (auto &q : queens) {
        ll i = q.first;
        ll j = q.second;
        // Intersection with rows and d1
        if (diag1.count(i - j)) {
            total_attacked--;
        }
        // Intersection with rows and d2
        if (diag2.count(i + j)) {
            total_attacked--;
        }
        // Intersection with columns and d1
        if (diag1.count(i - j)) {
            total_attacked--;
        }
        // Intersection with columns and d2
        if (diag2.count(i + j)) {
            total_attacked--;
        }
        // Intersection between d1 and d2
        if (diag1.count(i - j) && diag2.count(i + j)) {
            total_attacked++;
        }
    }
    
    // Subtract the M squares that are already occupied
    total_attacked -= M;
    
    ll total_squares = N * N;
    ll safe_squares = total_squares - total_attacked;
    
    cout << safe_squares << "\n";
    
    return 0;
}