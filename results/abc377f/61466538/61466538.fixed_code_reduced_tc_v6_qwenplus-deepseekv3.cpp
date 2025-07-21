#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll N, M;
    cin >> N >> M;
    set<ll> rows, cols, diag1, diag2;
    set<pll> pieces;

    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
        pieces.insert({a, b});
    }

    ll total = N * N;
    ll blocked = 0;

    // Blocked by rows and columns
    blocked += rows.size() * N;
    blocked += cols.size() * N;
    blocked -= rows.size() * cols.size();

    // Blocked by diagonals (i-j)
    for (auto d : diag1) {
        ll cnt;
        if (d >= 0) {
            cnt = N - d;
        } else {
            cnt = N + d;
        }
        blocked += cnt;
    }

    // Blocked by anti-diagonals (i+j)
    for (auto d : diag2) {
        ll cnt;
        if (d <= N + 1) {
            cnt = d - 1;
        } else {
            cnt = 2 * N - d + 1;
        }
        blocked += cnt;
    }

    // Subtract intersections between rows and diagonals
    for (auto r : rows) {
        for (auto d : diag1) {
            ll c = r - d;
            if (1 <= c && c <= N) {
                blocked--;
            }
        }
        for (auto d : diag2) {
            ll c = d - r;
            if (1 <= c && c <= N) {
                blocked--;
            }
        }
    }

    // Subtract intersections between columns and diagonals
    for (auto c : cols) {
        for (auto d : diag1) {
            ll r = d + c;
            if (1 <= r && r <= N) {
                blocked--;
            }
        }
        for (auto d : diag2) {
            ll r = d - c;
            if (1 <= r && r <= N) {
                blocked--;
            }
        }
    }

    // Add back intersections between rows, columns, and diagonals
    for (auto r : rows) {
        for (auto c : cols) {
            if (diag1.count(r - c) || diag2.count(r + c)) {
                blocked++;
            }
        }
    }

    // Add back intersections between diagonals and anti-diagonals
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            ll x = (d1 + d2) / 2;
            ll y = (d2 - d1) / 2;
            if (x + y == d2 && x - y == d1 && 1 <= x && x <= N && 1 <= y && y <= N) {
                blocked--;
            }
        }
    }

    // Subtract the squares already occupied by existing pieces
    blocked -= M;

    ll safe = total - blocked;
    cout << safe << endl;

    return 0;
}