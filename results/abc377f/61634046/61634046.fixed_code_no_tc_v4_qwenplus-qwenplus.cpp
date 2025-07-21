#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX_M = 1005;

int N, M;
set<int> rows, cols;
set<ll> diag1, diag2; // y - x, x + y

int main() {
    scanf("%d %d", &N, &M);
    
    for (int i = 0; i < M; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        rows.insert(y);
        cols.insert(x);
        diag1.insert((ll)y - x);
        diag2.insert((ll)x + y);
    }
    
    ll total = (ll)N * N;
    ll blocked = 0;
    
    // Count squares blocked by row, column, and diagonals
    blocked += (ll)rows.size() * N; // Rows
    blocked += (ll)cols.size() * N; // Columns
    
    // Diagonals of the form y - x = k
    blocked += (ll)diag1.size() * N;
    
    // Diagonals of the form x + y = k
    blocked += (ll)diag2.size() * N;
    
    // Inclusion-exclusion: subtract overcounts where two constraints overlap
    
    // Row and column intersections (already counted in both row and column)
    for (int r : rows) {
        for (int c : cols) {
            blocked -= 1; // Overlap at (r,c)
        }
    }
    
    // Row and diagonal1 overlaps (y - x = y_val - x_val => x = y - (y_val - x_val))
    for (int r : rows) {
        for (ll d : diag1) {
            ll c = r - d;
            if (1 <= c && c <= N) {
                blocked -= 1;
            }
        }
    }

    // Row and diagonal2 overlaps (x + y = s => y = s - x)
    for (int r : rows) {
        for (ll s : diag2) {
            ll c = s - r;
            if (1 <= c && c <= N) {
                blocked -= 1;
            }
        }
    }

    // Column and diagonal1 overlaps
    for (int c : cols) {
        for (ll d : diag1) {
            ll r = d + c;
            if (1 <= r && r <= N) {
                blocked -= 1;
            }
        }
    }

    // Column and diagonal2 overlaps
    for (int c : cols) {
        for (ll s : diag2) {
            ll r = s - c;
            if (1 <= r && r <= N) {
                blocked -= 1;
            }
        }
    }

    // Diagonal1 and diagonal2 overlaps
    for (ll d : diag1) {
        for (ll s : diag2) {
            ll c = (s - d) / 2;
            ll r = (s + d) / 2;
            if ((s - d) % 2 == 0 && (s + d) % 2 == 0 && 1 <= c && c <= N && 1 <= r && r <= N) {
                blocked -= 1;
            }
        }
    }

    // Inclusion-exclusion: add back triple overlaps
    // Row, column, and diagonal1/2 overlaps
    for (int r : rows) {
        for (int c : cols) {
            ll d = (ll)r - c;
            ll s = (ll)r + c;
            if (diag1.count(d)) blocked += 1;
            if (diag2.count(s)) blocked += 1;
        }
    }

    // Diagonal1, diagonal2, and row/column
    for (ll d : diag1) {
        for (ll s : diag2) {
            ll c = (s - d) / 2;
            ll r = (s + d) / 2;
            if ((s - d) % 2 == 0 && (s + d) % 2 == 0 && 1 <= c && c <= N && 1 <= r && r <= N) {
                if (rows.count(r)) blocked += 1;
                if (cols.count(c)) blocked += 1;
            }
        }
    }

    // Subtract quadruple overlaps
    for (int r : rows) {
        for (int c : cols) {
            ll d = (ll)r - c;
            ll s = (ll)r + c;
            if (diag1.count(d) && diag2.count(s)) {
                blocked -= 1;
            }
        }
    }

    // Total available positions is total - blocked + already placed pieces (since they're on grid already)
    printf("%lld\n", total - blocked + M);

    return 0;
}