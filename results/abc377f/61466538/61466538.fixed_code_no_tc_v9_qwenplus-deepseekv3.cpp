#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;
    vector<pair<ll, ll>> queens(M);
    set<ll> rows, cols, diag1, diag2;
    for (ll i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        queens[i] = {a, b};
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
    }

    ll total = N * N;
    ll attacked = 0;

    // Rows and columns
    ll rowCount = rows.size();
    ll colCount = cols.size();
    attacked += rowCount * N;
    attacked += colCount * N;
    attacked -= rowCount * colCount; // Intersection of rows and columns

    // Diagonals (type 1: a - b = constant)
    for (ll d : diag1) {
        ll minX, maxX;
        if (d >= 0) {
            minX = 1 + d;
            maxX = N;
        } else {
            minX = 1;
            maxX = N + d;
        }
        ll cnt = maxX - minX + 1;
        if (cnt > 0) {
            attacked += cnt;
            // Subtract intersections with rows and columns
            for (ll r : rows) {
                ll c = r - d;
                if (c >= 1 && c <= N) {
                    attacked--;
                }
            }
            for (ll c : cols) {
                ll r = c + d;
                if (r >= 1 && r <= N) {
                    attacked--;
                }
            }
            // Add back intersections of both rows and columns (already subtracted twice)
            for (ll r : rows) {
                ll c = r - d;
                if (c >= 1 && c <= N && cols.count(c)) {
                    attacked++;
                }
            }
        }
    }

    // Diagonals (type 2: a + b = constant)
    for (ll d : diag2) {
        ll minX = max(1LL, d - N);
        ll maxX = min(N, d - 1);
        ll cnt = maxX - minX + 1;
        if (cnt > 0) {
            attacked += cnt;
            // Subtract intersections with rows and columns
            for (ll r : rows) {
                ll c = d - r;
                if (c >= 1 && c <= N) {
                    attacked--;
                }
            }
            for (ll c : cols) {
                ll r = d - c;
                if (r >= 1 && r <= N) {
                    attacked--;
                }
            }
            // Add back intersections of both rows and columns (already subtracted twice)
            for (ll r : rows) {
                ll c = d - r;
                if (c >= 1 && c <= N && cols.count(c)) {
                    attacked++;
                }
            }
            // Subtract intersections with type 1 diagonals
            for (ll d1 : diag1) {
                ll x = (d + d1) / 2;
                ll y = (d - d1) / 2;
                if (x >= 1 && x <= N && y >= 1 && y <= N && (x - y == d1) && (x + y == d)) {
                    attacked--;
                }
            }
        }
    }

    // Add back intersections of diagonals type 1 and type 2 (subtracted twice)
    for (ll d1 : diag1) {
        for (ll d2 : diag2) {
            ll x = (d2 + d1) / 2;
            ll y = (d2 - d1) / 2;
            if ((x + y == d2) && (x - y == d1) && x >= 1 && x <= N && y >= 1 && y <= N) {
                attacked++;
            }
        }
    }

    ll safe = total - attacked + M; // M squares are already occupied
    cout << safe << endl;
    return 0;
}