#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;
    
    set<ll> rows, cols, diag1, diag2;
    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }
    
    ll total = N * N;
    ll attacked = 0;
    
    // Rows and columns
    attacked += rows.size() * N;
    attacked += cols.size() * N;
    attacked -= rows.size() * cols.size();
    
    // Diagonals (i + j = constant)
    for (const auto &d : diag1) {
        ll start_i = max(1LL, d - N);
        ll end_i = min(N, d - 1);
        if (start_i > end_i) continue;
        attacked += (end_i - start_i + 1);
    }
    
    // Anti-diagonals (i - j = constant)
    for (const auto &d : diag2) {
        ll start_i = max(1LL, 1 + d);
        ll end_i = min(N, N + d);
        if (start_i > end_i) continue;
        attacked += (end_i - start_i + 1);
    }
    
    // Subtract intersections between rows/columns and diagonals
    for (const auto &d : diag1) {
        for (const auto &r : rows) {
            ll c = d - r;
            if (c >= 1 && c <= N) {
                attacked--;
            }
        }
        for (const auto &c : cols) {
            ll r = d - c;
            if (r >= 1 && r <= N) {
                attacked--;
            }
        }
    }
    
    for (const auto &d : diag2) {
        for (const auto &r : rows) {
            ll c = r - d;
            if (c >= 1 && c <= N) {
                attacked--;
            }
        }
        for (const auto &c : cols) {
            ll r = c + d;
            if (r >= 1 && r <= N) {
                attacked--;
            }
        }
    }
    
    // Add back intersections between diagonals and anti-diagonals
    // But only if they are part of the existing pieces
    set<pair<ll, ll>> existing_pieces;
    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        existing_pieces.insert({a, b});
    }
    
    for (const auto &d1 : diag1) {
        for (const auto &d2 : diag2) {
            ll i = (d1 + d2) / 2;
            ll j = (d1 - d2) / 2;
            if (i >= 1 && i <= N && j >= 1 && j <= N && (d1 + d2) % 2 == 0 && (d1 - d2) % 2 == 0) {
                if (existing_pieces.count({i, j})) {
                    attacked++;
                }
            }
        }
    }
    
    // The total safe squares is total - attacked + existing pieces (since they are already occupied)
    ll safe = total - attacked;
    cout << safe << endl;
    
    return 0;
}