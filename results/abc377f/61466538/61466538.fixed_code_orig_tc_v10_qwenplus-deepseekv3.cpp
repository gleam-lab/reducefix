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
    set<ll> rows, cols, diag1, diag2;
    set<pll> queen_positions;
    
    for (ll i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        queens[i] = {a, b};
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
        queen_positions.insert({a, b});
    }
    
    ll unsafe = 0;
    
    // Rows and columns
    unsafe += rows.size() * N;
    unsafe += cols.size() * N;
    unsafe -= rows.size() * cols.size();
    
    // Diagonals (i - j)
    for (auto d : diag1) {
        ll cnt = 0;
        if (d >= 0) {
            cnt = N - d;
        } else {
            cnt = N + d;
        }
        unsafe += cnt;
        
        // Subtract intersections with rows and columns
        for (auto r : rows) {
            ll c = r - d;
            if (c >= 1 && c <= N) {
                if (queen_positions.find({r, c}) == queen_positions.end()) {
                    unsafe--;
                }
            }
        }
        for (auto c : cols) {
            ll r = c + d;
            if (r >= 1 && r <= N) {
                if (queen_positions.find({r, c}) == queen_positions.end()) {
                    unsafe--;
                }
            }
        }
    }
    
    // Diagonals (i + j)
    for (auto d : diag2) {
        ll cnt = 0;
        if (d <= N + 1) {
            cnt = d - 1;
        } else {
            cnt = 2 * N - d + 1;
        }
        unsafe += cnt;
        
        // Subtract intersections with rows and columns
        for (auto r : rows) {
            ll c = d - r;
            if (c >= 1 && c <= N) {
                if (queen_positions.find({r, c}) == queen_positions.end()) {
                    unsafe--;
                }
            }
        }
        for (auto c : cols) {
            ll r = d - c;
            if (r >= 1 && r <= N) {
                if (queen_positions.find({r, c}) == queen_positions.end()) {
                    unsafe--;
                }
            }
        }
        
        // Subtract intersections with diag1 (i - j)
        for (auto d1 : diag1) {
            ll i = (d + d1) / 2;
            ll j = (d - d1) / 2;
            if ((i + j) == d && (i - j) == d1 && i >= 1 && i <= N && j >= 1 && j <= N) {
                if (queen_positions.find({i, j}) == queen_positions.end()) {
                    unsafe--;
                }
            }
        }
    }
    
    ll total = N * N;
    ll safe = total - unsafe - M; // Subtract M because queen positions are initially counted as unsafe but are not empty
    safe = max(safe, 0LL); // Ensure non-negative
    cout << safe << "\n";
    
    return 0;
}