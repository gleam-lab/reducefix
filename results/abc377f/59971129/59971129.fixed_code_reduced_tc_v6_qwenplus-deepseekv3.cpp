#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;
    
    set<ll> rows, cols, diags1, diags2; // diags1: i-j, diags2: i+j
    set<pair<ll, ll>> occupied;
    
    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diags1.insert(a - b);
        diags2.insert(a + b);
        occupied.insert({a, b});
    }
    
    ll total_squares = N * N;
    ll threatened = 0;
    
    // Rows and columns: each covers N squares, but overlaps are squares in both row and column
    threatened += rows.size() * N;
    threatened += cols.size() * N;
    threatened -= rows.size() * cols.size();
    
    // Diagonals (i - j = d) and anti-diagonals (i + j = s)
    // For each unique d in diags1, the number of squares is (N - abs(d)) if d is in [-N+1, N-1]
    for (ll d : diags1) {
        ll cnt = N - abs(d);
        if (d > 0) {
            cnt = N - d;
        } else if (d < 0) {
            cnt = N + d;
        } // else d=0, cnt=N
        threatened += cnt;
    }
    
    // For each unique s in diags2, the number of squares is (s <= N+1 ? s-1 : 2*N - s + 1)
    for (ll s : diags2) {
        ll cnt;
        if (s <= N + 1) {
            cnt = s - 1;
        } else {
            cnt = 2 * N - s + 1;
        }
        threatened += cnt;
    }
    
    // Now, subtract overlaps between rows/columns and diagonals/anti-diagonals
    // Also, subtract overlaps between diagonals and anti-diagonals
    // Also, add back squares that were subtracted multiple times (inclusion-exclusion)
    
    // Overlap between rows and diags1 (i - j = d), which is the intersection of row a and diag d = a - b => j = a - d
    for (ll a : rows) {
        for (ll d : diags1) {
            ll j = a - d;
            if (j >= 1 && j <= N) {
                threatened--;
            }
        }
    }
    
    // Overlap between cols and diags1 (i - j = d) => i = j + d
    for (ll b : cols) {
        for (ll d : diags1) {
            ll i = b + d;
            if (i >= 1 && i <= N) {
                threatened--;
            }
        }
    }
    
    // Overlap between rows and diags2 (i + j = s) => j = s - a
    for (ll a : rows) {
        for (ll s : diags2) {
            ll j = s - a;
            if (j >= 1 && j <= N) {
                threatened--;
            }
        }
    }
    
    // Overlap between cols and diags2 (i + j = s) => i = s - b
    for (ll b : cols) {
        for (ll s : diags2) {
            ll i = s - b;
            if (i >= 1 && i <= N) {
                threatened--;
            }
        }
    }
    
    // Overlap between diags1 and diags2: i - j = d and i + j = s => i = (s + d)/2, j = (s - d)/2
    for (ll d : diags1) {
        for (ll s : diags2) {
            if ((s + d) % 2 == 0 && (s - d) % 2 == 0) {
                ll i = (s + d) / 2;
                ll j = (s - d) / 2;
                if (i >= 1 && i <= N && j >= 1 && j <= N) {
                    threatened++;
                }
            }
        }
    }
    
    // Now, subtract the occupied squares, as they were counted in threatened (if not already)
    ll safe_squares = total_squares - threatened - M + occupied.size();
    
    cout << safe_squares << endl;
    
    return 0;
}