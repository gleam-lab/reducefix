#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll N, M;
    cin >> N >> M;
    
    set<ll> rows, cols, diag1, diag2;
    set<pair<ll, ll>> pieces;
    
    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
        pieces.insert({a, b});
    }
    
    ll unsafe = 0;
    
    // Rows and columns
    unsafe += rows.size() * N;
    unsafe += cols.size() * N;
    unsafe -= rows.size() * cols.size(); // Subtract intersections counted twice
    
    // Diagonals (a - b = constant)
    for (auto d : diag1) {
        ll count = 0;
        if (d >= 0) {
            count = N - d;
        } else {
            count = N + d;
        }
        unsafe += count;
    }
    
    // Anti-diagonals (a + b = constant)
    for (auto d : diag2) {
        ll count = 0;
        if (d <= N + 1) {
            count = d - 1;
        } else {
            count = 2 * N - d + 1;
        }
        unsafe += count;
    }
    
    // Subtract intersections between rows/cols and diagonals/anti-diagonals
    for (auto a : rows) {
        for (auto d : diag1) {
            ll b = a - d;
            if (b >= 1 && b <= N) {
                unsafe--;
            }
        }
        for (auto d : diag2) {
            ll b = d - a;
            if (b >= 1 && b <= N) {
                unsafe--;
            }
        }
    }
    
    for (auto b : cols) {
        for (auto d : diag1) {
            ll a = d + b;
            if (a >= 1 && a <= N) {
                unsafe--;
            }
        }
        for (auto d : diag2) {
            ll a = d - b;
            if (a >= 1 && a <= N) {
                unsafe--;
            }
        }
    }
    
    // Subtract intersections between diagonals and anti-diagonals
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            ll a = (d1 + d2) / 2;
            ll b = (d2 - d1) / 2;
            if ((d1 + d2) % 2 == 0 && (d2 - d1) % 2 == 0 && a >= 1 && a <= N && b >= 1 && b <= N) {
                unsafe--;
            }
        }
    }
    
    // Add back the squares that are attacked by multiple lines and were subtracted multiple times
    // But in reality, we need inclusion-exclusion; however, for simplicity, the above steps might suffice for small M
    
    // The total squares is N*N, subtract the unsafe squares, then add back the pieces (since they were counted as unsafe but are not empty)
    ll total = N * N - unsafe + M - pieces.size();
    
    // However, the correct approach is to compute the total number of squares attacked by at least one piece, then subtract those occupied by pieces
    // Recompute unsafe correctly
    set<pair<ll, ll>> attacked;
    
    for (auto a : rows) {
        for (ll b = 1; b <= N; ++b) {
            attacked.insert({a, b});
        }
    }
    
    for (auto b : cols) {
        for (ll a = 1; a <= N; ++a) {
            attacked.insert({a, b});
        }
    }
    
    for (auto d : diag1) {
        ll a_start = max(1LL, 1 + d);
        ll b_start = max(1LL, 1 - d);
        ll a_end = min(N, N + d);
        ll b_end = min(N, N - d);
        for (ll a = a_start; a <= a_end; ++a) {
            ll b = a - d;
            attacked.insert({a, b});
        }
    }
    
    for (auto d : diag2) {
        ll a_start = max(1LL, d - N);
        ll b_start = max(1LL, d - N);
        ll a_end = min(N, d - 1);
        ll b_end = min(N, d - 1);
        for (ll a = a_start; a <= a_end; ++a) {
            ll b = d - a;
            if (b >= 1 && b <= N) {
                attacked.insert({a, b});
            }
        }
    }
    
    // The number of safe squares is total squares (N*N) minus the attacked squares (attacked.size()) minus the existing pieces (M) plus the squares that are both attacked and have pieces (which is M, since all pieces are in attacked squares)
    ll safe = N * N - attacked.size() - (M - M);
    
    // But N can be up to 1e9, and M up to 1e3, so the above approach is not feasible due to memory constraints
    
    // Hence, we need a mathematical approach to compute the number of unique squares attacked by at least one piece
    
    // The inclusion-exclusion principle is needed to compute the size of the union of all attacked squares
    
    // Let's compute the total attacked squares using inclusion-exclusion
    
    ll A = rows.size() * N;
    ll B = cols.size() * N;
    ll C = 0;
    for (auto d : diag1) {
        if (d >= 0) {
            C += N - d;
        } else {
            C += N + d;
        }
    }
    ll D = 0;
    for (auto d : diag2) {
        if (d <= N + 1) {
            D += d - 1;
        } else {
            D += 2 * N - d + 1;
        }
    }
    
    // Intersections
    ll AB = 0;
    for (auto a : rows) {
        for (auto b : cols) {
            AB++;
        }
    }
    
    ll AC = 0;
    for (auto a : rows) {
        for (auto d : diag1) {
            ll b = a - d;
            if (b >= 1 && b <= N) {
                AC++;
            }
        }
    }
    
    ll AD = 0;
    for (auto a : rows) {
        for (auto d : diag2) {
            ll b = d - a;
            if (b >= 1 && b <= N) {
                AD++;
            }
        }
    }
    
    ll BC = 0;
    for (auto b : cols) {
        for (auto d : diag1) {
            ll a = d + b;
            if (a >= 1 && a <= N) {
                BC++;
            }
        }
    }
    
    ll BD = 0;
    for (auto b : cols) {
        for (auto d : diag2) {
            ll a = d - b;
            if (a >= 1 && a <= N) {
                BD++;
            }
        }
    }
    
    ll CD = 0;
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            if ((d1 + d2) % 2 == 0 && (d2 - d1) % 2 == 0) {
                ll a = (d1 + d2) / 2;
                ll b = (d2 - d1) / 2;
                if (a >= 1 && a <= N && b >= 1 && b <= N) {
                    CD++;
                }
            }
        }
    }
    
    ll ABC = 0;
    for (auto a : rows) {
        for (auto b : cols) {
            ll d1 = a - b;
            if (diag1.find(d1) != diag1.end()) {
                ABC++;
            }
        }
    }
    
    ll ABD = 0;
    for (auto a : rows) {
        for (auto b : cols) {
            ll d2 = a + b;
            if (diag2.find(d2) != diag2.end()) {
                ABD++;
            }
        }
    }
    
    ll ACD = 0;
    for (auto a : rows) {
        for (auto d1 : diag1) {
            ll b = a - d1;
            if (b >= 1 && b <= N) {
                ll d2 = a + b;
                if (diag2.find(d2) != diag2.end()) {
                    ACD++;
                }
            }
        }
    }
    
    ll BCD = 0;
    for (auto b : cols) {
        for (auto d1 : diag1) {
            ll a = d1 + b;
            if (a >= 1 && a <= N) {
                ll d2 = a + b;
                if (diag2.find(d2) != diag2.end()) {
                    BCD++;
                }
            }
        }
    }
    
    ll ABCD = 0;
    for (auto a : rows) {
        for (auto b : cols) {
            ll d1 = a - b;
            ll d2 = a + b;
            if (diag1.find(d1) != diag1.end() && diag2.find(d2) != diag2.end()) {
                ABCD++;
            }
        }
    }
    
    // Inclusion-exclusion
    ll total_attacked = A + B + C + D - (AC + AD + BC + BD + CD) + (ABC + ABD + ACD + BCD) - ABCD;
    
    safe = N * N - total_attacked;
    
    // Now, subtract the squares already occupied by pieces (since they are not empty)
    safe -= M;
    
    cout << max(0LL, safe) << endl;
    
    return 0;
}