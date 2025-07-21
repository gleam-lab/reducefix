#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;
    set<ll> rows, cols, diag1, diag2;
    for (ll i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
    }

    ll unsafe = 0;
    
    // Squares attacked by rows or columns
    unsafe += rows.size() * N + cols.size() * N - rows.size() * cols.size();
    
    // Squares attacked by diagonals (a - b)
    for (auto d : diag1) {
        ll a_minus_b = d;
        // The line is a - b = d, which translates to a = b + d
        // Constraints: 1 <= a <= N and 1 <= b <= N
        // => 1 <= b + d <= N and 1 <= b <= N
        // => 1 - d <= b <= N - d and 1 <= b <= N
        // So b ranges from max(1, 1 - d) to min(N, N - d)
        ll lower_b = max(1LL, 1 - a_minus_b);
        ll upper_b = min(N, N - a_minus_b);
        if (lower_b > upper_b) continue;
        unsafe += (upper_b - lower_b + 1);
    }
    
    // Squares attacked by diagonals (a + b)
    for (auto s : diag2) {
        ll a_plus_b = s;
        // The line is a + b = s
        // Constraints: 1 <= a <= N and 1 <= b <= N
        // => a = s - b, so 1 <= s - b <= N => s - N <= b <= s - 1
        // And 1 <= b <= N
        // So b ranges from max(1, s - N) to min(N, s - 1)
        ll lower_b = max(1LL, s - N);
        ll upper_b = min(N, s - 1);
        if (lower_b > upper_b) continue;
        unsafe += (upper_b - lower_b + 1);
    }
    
    // Now, subtract overlaps between rows/cols and diagonals
    // For each existing piece (a, b), it lies at the intersection of row a, column b, diag1 (a-b), diag2 (a+b)
    // These intersections have been counted multiple times, so we need to subtract them appropriately
    // For each piece, it's been counted in rows (+1), cols (+1), diag1 (a-b) (+1), diag2 (a+b) (+1)
    // So initially, each piece is counted 4 times, but it should be counted once (as it's one square)
    // So subtract 3 for each existing piece
    unsafe -= 3 * M;
    
    // Also, some squares may be attacked by multiple conditions (e.g., row and diag1)
    // These squares have been counted twice in unsafe, but should be counted once
    // So we need to find all such squares and adjust unsafe accordingly
    
    // However, calculating these overlaps precisely is complex, so we'll use an alternative approach:
    // The total safe squares = total squares (N^2) - (squares attacked by rows or columns or diag1 or diag2)
    // Using inclusion-exclusion:
    // |A ∪ B ∪ C ∪ D| = |A| + |B| + |C| + |D| - |A ∩ B| - |A ∩ C| - |A ∩ D| - |B ∩ C| - |B ∩ D| - |C ∩ D| + |A ∩ B ∩ C| + |A ∩ B ∩ D| + |A ∩ C ∩ D| + |B ∩ C ∩ D| - |A ∩ B ∩ C ∩ D|
    // Where A: attacked by rows, B: attacked by columns, C: attacked by diag1, D: attacked by diag2
    
    // Recomputing unsafe with inclusion-exclusion
    unsafe = 0;
    ll A = rows.size() * N;
    ll B = cols.size() * N;
    ll C = 0;
    for (auto d : diag1) {
        ll a_minus_b = d;
        ll lower_b = max(1LL, 1 - a_minus_b);
        ll upper_b = min(N, N - a_minus_b);
        if (lower_b > upper_b) continue;
        C += (upper_b - lower_b + 1);
    }
    ll D = 0;
    for (auto s : diag2) {
        ll a_plus_b = s;
        ll lower_b = max(1LL, a_plus_b - N);
        ll upper_b = min(N, a_plus_b - 1);
        if (lower_b > upper_b) continue;
        D += (upper_b - lower_b + 1);
    }
    
    unsafe = A + B + C + D;
    
    // A ∩ B: squares attacked by both a row and a column = number of existing pieces (M)
    unsafe -= M;
    
    // A ∩ C: squares attacked by a row and diag1 (a - b)
    for (auto a : rows) {
        for (auto d : diag1) {
            ll b = a - d;
            if (b >= 1 && b <= N) {
                unsafe--;
            }
        }
    }
    
    // A ∩ D: squares attacked by a row and diag2 (a + b)
    for (auto a : rows) {
        for (auto s : diag2) {
            ll b = s - a;
            if (b >= 1 && b <= N) {
                unsafe--;
            }
        }
    }
    
    // B ∩ C: squares attacked by a column and diag1 (a - b)
    for (auto b : cols) {
        for (auto d : diag1) {
            ll a = b + d;
            if (a >= 1 && a <= N) {
                unsafe--;
            }
        }
    }
    
    // B ∩ D: squares attacked by a column and diag2 (a + b)
    for (auto b : cols) {
        for (auto s : diag2) {
            ll a = s - b;
            if (a >= 1 && a <= N) {
                unsafe--;
            }
        }
    }
    
    // C ∩ D: squares attacked by both diag1 and diag2
    // For a square (a,b): a - b = d1 and a + b = d2 => a = (d1 + d2)/2, b = (d2 - d1)/2
    // So a and b must be integers, and within [1, N]
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            if ((d1 + d2) % 2 != 0) continue;
            ll a = (d1 + d2) / 2;
            ll b = (d2 - d1) / 2;
            if (a >= 1 && a <= N && b >= 1 && b <= N) {
                unsafe--;
            }
        }
    }
    
    // Now, triple intersections: A ∩ B ∩ C, A ∩ B ∩ D, A ∩ C ∩ D, B ∩ C ∩ D
    // Each existing piece (a,b) is in all four sets, so it's been added 4 times, subtracted 6 times (from pairwise intersections), needs to be added back 4 times (from triple intersections), then subtracted 1 time (from quadruple intersection)
    // So for each piece, net count is 4 - 6 + 4 - 1 = +1 (correct)
    // So, total added in triple intersections is M (since each triple intersection for existing pieces is counted once)
    unsafe += M;
    
    // For A ∩ B ∩ C: squares that are in a row, a column, and diag1 (a - b) = existing pieces where a - b is in diag1
    for (auto a : rows) {
        for (auto b : cols) {
            if (diag1.count(a - b)) {
                unsafe++;
            }
        }
    }
    
    // Similarly for A ∩ B ∩ D: existing pieces where a + b is in diag2
    for (auto a : rows) {
        for (auto b : cols) {
            if (diag2.count(a + b)) {
                unsafe++;
            }
        }
    }
    
    // For A ∩ C ∩ D: squares attacked by row a, diag1 (a - b), diag2 (a + b)
    // So a is fixed by row, then b must satisfy a - b = d1 and a + b = d2 => b = (d2 - d1)/2
    // So for each a in rows, and for each d1 in diag1 and d2 in diag2 where (d2 - d1) is even and b is between 1 and N
    for (auto a : rows) {
        for (auto d1 : diag1) {
            for (auto d2 : diag2) {
                if ((d2 - d1) % 2 != 0) continue;
                ll b = (d2 - d1) / 2;
                if (b >= 1 && b <= N) {
                    if (a - b == d1 && a + b == d2) {
                        unsafe++;
                    }
                }
            }
        }
    }
    
    // For B ∩ C ∩ D: squares attacked by column b, diag1 (a - b), diag2 (a + b)
    // So b is fixed by column, then a = b + d1 and a + b = d2 => a = (d2 + d1)/2 and b = (d2 - d1)/2
    // But b is fixed, so d2 - d1 must be 2*b, and (d2 + d1)/2 = b + d1 must be between 1 and N
    for (auto b : cols) {
        for (auto d1 : diag1) {
            ll d2 = 2 * b + d1;
            if (diag2.count(d2)) {
                ll a = b + d1;
                if (a >= 1 && a <= N) {
                    if (a - b == d1 && a + b == d2) {
                        unsafe++;
                    }
                }
            }
        }
    }
    
    // Finally, quadruple intersection A ∩ B ∩ C ∩ D: existing pieces, counted once
    unsafe -= M;
    
    ll total = N * N;
    ll safe = total - unsafe;
    cout << safe << endl;

    return 0;
}