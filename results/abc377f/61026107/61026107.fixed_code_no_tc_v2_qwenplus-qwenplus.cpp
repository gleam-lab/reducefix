#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Piece {
    ll x, y;
    ll diag1() const { return x - y; }
    ll diag2() const { return x + y; }
};

void solve() {
    ll N, M;
    cin >> N >> M;
    vector<Piece> pieces(M);
    for (auto& p : pieces) {
        cin >> p.x >> p.y;
    }

    // Sets to store all rows, columns, and diagonals occupied by existing pieces
    set<ll> rows, cols, diag1s, diag2s;
    for (const auto& p : pieces) {
        rows.insert(p.x);
        cols.insert(p.y);
        diag1s.insert(p.diag1());
        diag2s.insert(p.diag2());
    }

    // Total number of unsafe cells: those in attacked lines
    ll totalUnsafe = 0;
    totalUnsafe += rows.size() * N; // All cells in occupied rows
    totalUnsafe += cols.size() * N; // All cells in occupied columns
    for (ll d : diag1s) {
        ll count = min(d + N, N) - max<ll>(d - (N - 1), 1) + 1;
        totalUnsafe += count;
    }
    for (ll d : diag2s) {
        ll count = min(d - 1, N) - max<ll>(d - N, 1) + 1;
        totalUnsafe += count;
    }

    // Now subtract overlaps (cells that were counted multiple times)

    // Intersections between rows and columns
    for (ll r : rows) {
        for (ll c : cols) {
            totalUnsafe--;
        }
    }

    // Intersections between row and diag1
    for (ll r : rows) {
        for (ll d : diag1s) {
            ll c = r - d;
            if (1 <= c && c <= N) {
                totalUnsafe--;
            }
        }
    }

    // Intersections between row and diag2
    for (ll r : rows) {
        for (ll d : diag2s) {
            ll c = d - r;
            if (1 <= c && c <= N) {
                totalUnsafe--;
            }
        }
    }

    // Intersections between column and diag1
    for (ll c : cols) {
        for (ll d : diag1s) {
            ll r = d + c;
            if (1 <= r && r <= N) {
                totalUnsafe--;
            }
        }
    }

    // Intersections between column and diag2
    for (ll c : cols) {
        for (ll d : diag2s) {
            ll r = d - c;
            if (1 <= r && r <= N) {
                totalUnsafe--;
            }
        }
    }

    // Intersections between diag1 and diag2
    for (ll d1 : diag1s) {
        for (ll d2 : diag2s) {
            if ((d1 + d2) % 2 == 0) {
                ll r = (d1 + d2) / 2;
                ll c = d2 - r;
                if (1 <= r && r <= N && 1 <= c && c <= N) {
                    totalUnsafe--;
                }
            }
        }
    }

    // Subtract cells with existing pieces (already occupied)
    ll occupiedCells = M;
    // Final answer
    ll totalCells = N * N;
    ll safeCells = totalCells - totalUnsafe + occupiedCells;
    cout << safeCells << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}