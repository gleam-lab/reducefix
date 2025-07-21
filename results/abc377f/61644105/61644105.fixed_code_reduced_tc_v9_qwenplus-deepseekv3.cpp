#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;
    
    unordered_set<ll> rows, cols, diag1, diag2;
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
    
    // Attacked by rows and columns
    attacked += rows.size() * N + cols.size() * N - rows.size() * cols.size();
    
    // Attacked by diagonals (a + b)
    for (ll d : diag1) {
        ll cnt = 0;
        if (d <= N + 1) {
            cnt = d - 1;
        } else {
            cnt = 2 * N - d + 1;
        }
        attacked += cnt;
    }
    
    // Attacked by anti-diagonals (a - b)
    for (ll d : diag2) {
        ll cnt = 0;
        if (d >= 0) {
            cnt = N - d;
        } else {
            cnt = N + d;
        }
        attacked += cnt;
    }
    
    // Adjust for intersections between diagonals and anti-diagonals
    for (ll d1 : diag1) {
        for (ll d2 : diag2) {
            if ((d1 + d2) % 2 != 0) continue;
            ll a = (d1 + d2) / 2;
            ll b = (d1 - d2) / 2;
            if (a >= 1 && a <= N && b >= 1 && b <= N) {
                if (rows.count(a) || cols.count(b)) continue;
                attacked--;
            }
        }
    }
    
    // Adjust for intersections between rows and diagonals/anti-diagonals
    for (ll r : rows) {
        for (ll d : diag1) {
            ll b = d - r;
            if (b >= 1 && b <= N) {
                if (cols.count(b)) continue;
                attacked--;
            }
        }
        for (ll d : diag2) {
            ll b = r - d;
            if (b >= 1 && b <= N) {
                if (cols.count(b)) continue;
                attacked--;
            }
        }
    }
    
    // Adjust for intersections between columns and diagonals/anti-diagonals
    for (ll c : cols) {
        for (ll d : diag1) {
            ll a = d - c;
            if (a >= 1 && a <= N) {
                if (rows.count(a)) continue;
                attacked--;
            }
        }
        for (ll d : diag2) {
            ll a = c + d;
            if (a >= 1 && a <= N) {
                if (rows.count(a)) continue;
                attacked--;
            }
        }
    }
    
    ll safe = total - attacked;
    cout << safe << endl;
    
    return 0;
}