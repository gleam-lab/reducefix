#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;
    
    set<ll> rows, cols;
    set<ll> diag1, diag2; // diag1: i - j, diag2: i + j
    
    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
    }
    
    ll unsafe_rows = rows.size();
    ll unsafe_cols = cols.size();
    ll unsafe_diag1 = diag1.size();
    ll unsafe_diag2 = diag2.size();
    
    // Total squares: N*N
    // Safe squares = total - (squares covered by rows, cols, diag1, diag2) + overlaps
    
    // Squares covered by rows: unsafe_rows * N
    // Squares covered by cols: unsafe_cols * N, but overlaps (rows and cols) are already counted once
    // So squares covered by rows or cols: unsafe_rows * N + unsafe_cols * N - unsafe_rows * unsafe_cols
    
    ll covered_row_col = unsafe_rows * N + unsafe_cols * N - unsafe_rows * unsafe_cols;
    
    // Now, squares covered by diag1 or diag2
    // For each diagonal in diag1, count the number of squares (i,j) where i - j = d
    // The number of such squares is N - |d|, provided 1 <= i, j <= N
    // So, total squares covered by diag1: sum (N - |d|) for each d in diag1
    ll covered_diag1 = 0;
    for (ll d : diag1) {
        ll min_ij = max(1LL, 1 + d);
        ll max_ij = min(N, N + d);
        if (min_ij > max_ij) continue;
        covered_diag1 += (max_ij - min_ij + 1);
    }
    
    ll covered_diag2 = 0;
    for (ll s : diag2) {
        ll min_ij = max(1LL, s - N);
        ll max_ij = min(N, s - 1);
        if (min_ij > max_ij) continue;
        covered_diag2 += (max_ij - min_ij + 1);
    }
    
    // Now, overlaps between rows/cols and diag1/diag2
    // Overlap between rows and diag1: for each row r in rows, and each d in diag1, if (r - j) = d → j = r - d. If 1 <= j <= N, then it's covered.
    // Similarly for other overlaps.
    // To avoid complex calculations, we can note that any square (i,j) is covered if i is in rows, or j is in cols, or i-j is in diag1, or i+j is in diag2.
    // So, the total unsafe squares is the union of these four sets.
    // To compute the size of the union, we can use inclusion-exclusion.
    
    // However, for performance (since M is up to 1e3), it's feasible to iterate over all existing pieces and mark the covered squares in a set, then subtract the size of this set from N*N.
    // But since N can be 1e9, we can't store all squares. Instead, we need a mathematical approach.
    
    // Implementation of inclusion-exclusion for the four sets:
    // |A ∪ B ∪ C ∪ D| = |A| + |B| + |C| + |D| - |A ∩ B| - |A ∩ C| - |A ∩ D| - |B ∩ C| - |B ∩ D| - |C ∩ D| + |A ∩ B ∩ C| + |A ∩ B ∩ D| + |A ∩ C ∩ D| + |B ∩ C ∩ D| - |A ∩ B ∩ C ∩ D|
    
    // Here, A is rows, B is cols, C is diag1 (i-j), D is diag2 (i+j)
    
    // Compute |A| = unsafe_rows * N
    // |B| = unsafe_cols * N
    // |C| = covered_diag1
    // |D| = covered_diag2
    
    // Now compute pairwise intersections:
    // |A ∩ B| = number of (i,j) where i is in rows and j is in cols → unsafe_rows * unsafe_cols
    ll AB = unsafe_rows * unsafe_cols;
    
    // |A ∩ C| = number of (i,j) where i is in rows and i-j is in diag1 → for each row r in rows and each d in diag1, j = r - d must be in [1,N]
    ll AC = 0;
    for (ll r : rows) {
        for (ll d : diag1) {
            ll j = r - d;
            if (j >= 1 && j <= N) {
                AC++;
            }
        }
    }
    
    // |A ∩ D| = number of (i,j) where i is in rows and i+j is in diag2 → for each row r in rows and each s in diag2, j = s - r must be in [1,N]
    ll AD = 0;
    for (ll r : rows) {
        for (ll s : diag2) {
            ll j = s - r;
            if (j >= 1 && j <= N) {
                AD++;
            }
        }
    }
    
    // |B ∩ C| = number of (i,j) where j is in cols and i-j is in diag1 → for each col c in cols and each d in diag1, i = d + c must be in [1,N]
    ll BC = 0;
    for (ll c : cols) {
        for (ll d : diag1) {
            ll i = d + c;
            if (i >= 1 && i <= N) {
                BC++;
            }
        }
    }
    
    // |B ∩ D| = number of (i,j) where j is in cols and i+j is in diag2 → for each col c in cols and each s in diag2, i = s - c must be in [1,N]
    ll BD = 0;
    for (ll c : cols) {
        for (ll s : diag2) {
            ll i = s - c;
            if (i >= 1 && i <= N) {
                BD++;
            }
        }
    }
    
    // |C ∩ D| = number of (i,j) where i-j is in diag1 and i+j is in diag2 → solve for i and j: i = (d + s)/2, j = (s - d)/2 must be integers and in [1,N]
    ll CD = 0;
    for (ll d : diag1) {
        for (ll s : diag2) {
            if ((d + s) % 2 != 0) continue;
            if ((s - d) % 2 != 0) continue;
            ll i = (d + s) / 2;
            ll j = (s - d) / 2;
            if (i >= 1 && i <= N && j >= 1 && j <= N) {
                CD++;
            }
        }
    }
    
    // Now compute triple intersections:
    // |A ∩ B ∩ C| = number of (i,j) where i in rows, j in cols, and i-j in diag1 → for each r in rows, c in cols, if (r - c) is in diag1 → increment
    ll ABC = 0;
    for (ll r : rows) {
        for (ll c : cols) {
            if (diag1.count(r - c)) {
                ABC++;
            }
        }
    }
    
    // |A ∩ B ∩ D| = number of (i,j) where i in rows, j in cols, and i+j in diag2 → for each r in rows, c in cols, if (r + c) is in diag2 → increment
    ll ABD = 0;
    for (ll r : rows) {
        for (ll c : cols) {
            if (diag2.count(r + c)) {
                ABD++;
            }
        }
    }
    
    // |A ∩ C ∩ D| = number of (i,j) where i in rows, i-j in diag1, i+j in diag2 → for each r in rows, d in diag1, s in diag2, if j = r - d and j = s - r → s + d = 2r → check if s + d == 2r and then j = r - d must be in [1,N]
    ll ACD = 0;
    for (ll r : rows) {
        for (ll d : diag1) {
            ll s_candidate = 2 * r - d;
            if (diag2.count(s_candidate)) {
                ll j = r - d;
                if (j >= 1 && j <= N) {
                    ACD++;
                }
            }
        }
    }
    
    // |B ∩ C ∩ D| = number of (i,j) where j in cols, i-j in diag1, i+j in diag2 → for each c in cols, d in diag1, s in diag2, if i = d + c and i = s - c → d + c = s - c → s = d + 2c → check if s is in diag2, then i = d + c must be in [1,N]
    ll BCD = 0;
    for (ll c : cols) {
        for (ll d : diag1) {
            ll s_candidate = d + 2 * c;
            if (diag2.count(s_candidate)) {
                ll i = d + c;
                if (i >= 1 && i <= N) {
                    BCD++;
                }
            }
        }
    }
    
    // |A ∩ B ∩ C ∩ D| = number of (i,j) where i in rows, j in cols, i-j in diag1, i+j in diag2 → for each r in rows, c in cols, if (r - c) in diag1 and (r + c) in diag2 → increment
    ll ABCD = 0;
    for (ll r : rows) {
        for (ll c : cols) {
            if (diag1.count(r - c) && diag2.count(r + c)) {
                ABCD++;
            }
        }
    }
    
    ll unsafe_total = (unsafe_rows * N + unsafe_cols * N + covered_diag1 + covered_diag2) 
                    - (AB + AC + AD + BC + BD + CD) 
                    + (ABC + ABD + ACD + BCD) 
                    - ABCD;
    
    ll safe_squares = N * N - unsafe_total;
    
    cout << safe_squares << endl;
    
    return 0;
}