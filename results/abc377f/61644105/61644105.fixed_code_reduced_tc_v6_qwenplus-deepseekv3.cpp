#include <bits/stdc++.h>
using namespace std;

#define ll long long

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
    
    attacked += N * rows.size();
    attacked += N * cols.size();
    attacked -= rows.size() * cols.size();
    
    for (auto d : diag1) {
        ll lower = max(1LL, d - N);
        ll upper = min(N, d - 1);
        if (lower <= upper) {
            attacked += (upper - lower + 1);
        }
    }
    
    for (auto d : diag2) {
        ll lower_row = max(1LL, 1 + d);
        ll upper_row = min(N, N + d);
        if (lower_row <= upper_row) {
            attacked += (upper_row - lower_row + 1);
        }
    }
    
    for (auto r : rows) {
        for (auto d : diag1) {
            ll b = d - r;
            if (b >= 1 && b <= N) {
                if (cols.count(b)) {
                    attacked--;
                }
            }
        }
        for (auto d : diag2) {
            ll b = r - d;
            if (b >= 1 && b <= N) {
                if (cols.count(b)) {
                    attacked--;
                }
            }
        }
    }
    
    for (auto c : cols) {
        for (auto d : diag1) {
            ll a = d - c;
            if (a >= 1 && a <= N) {
                if (rows.count(a)) {
                    attacked--;
                }
            }
        }
        for (auto d : diag2) {
            ll a = c + d;
            if (a >= 1 && a <= N) {
                if (rows.count(a)) {
                    attacked--;
                }
            }
        }
    }
    
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            ll a = (d1 + d2) / 2;
            ll b = (d1 - d2) / 2;
            if ((d1 + d2) % 2 == 0 && (d1 - d2) % 2 == 0) {
                if (a >= 1 && a <= N && b >= 1 && b <= N) {
                    if (rows.count(a) && cols.count(b)) {
                        attacked++;
                    }
                }
            }
        }
    }
    
    ll safe = total - attacked;
    cout << safe << endl;
    
    return 0;
}