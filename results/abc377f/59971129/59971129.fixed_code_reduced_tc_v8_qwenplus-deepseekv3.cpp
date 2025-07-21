#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

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
    
    ll unsafe_rows = rows.size() * N;
    ll unsafe_cols = cols.size() * N;
    ll unsafe_diag1 = 0;
    for (auto d : diag1) {
        if (d <= N + 1) {
            unsafe_diag1 += d - 1;
        } else {
            unsafe_diag1 += 2 * N - d + 1;
        }
    }
    ll unsafe_diag2 = 0;
    for (auto d : diag2) {
        ll lower = 1 - d;
        ll upper = N - d;
        if (lower <= 0) {
            lower = 1;
            upper = min(upper, N);
        } else {
            upper = min(upper, N);
        }
        unsafe_diag2 += upper - lower + 1;
    }
    
    ll unsafe_rows_cols = rows.size() * cols.size();
    
    ll unsafe_rows_diag1 = 0;
    for (auto r : rows) {
        for (auto d : diag1) {
            ll b = d - r;
            if (b >= 1 && b <= N) {
                unsafe_rows_diag1++;
            }
        }
    }
    
    ll unsafe_rows_diag2 = 0;
    for (auto r : rows) {
        for (auto d : diag2) {
            ll b = r - d;
            if (b >= 1 && b <= N) {
                unsafe_rows_diag2++;
            }
        }
    }
    
    ll unsafe_cols_diag1 = 0;
    for (auto c : cols) {
        for (auto d : diag1) {
            ll a = d - c;
            if (a >= 1 && a <= N) {
                unsafe_cols_diag1++;
            }
        }
    }
    
    ll unsafe_cols_diag2 = 0;
    for (auto c : cols) {
        for (auto d : diag2) {
            ll a = d + c;
            if (a >= 1 && a <= N) {
                unsafe_cols_diag2++;
            }
        }
    }
    
    ll unsafe_diag1_diag2 = 0;
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            if ((d1 + d2) % 2 == 0) {
                ll a = (d1 + d2) / 2;
                ll b = (d1 - d2) / 2;
                if (a >= 1 && a <= N && b >= 1 && b <= N) {
                    unsafe_diag1_diag2++;
                }
            }
        }
    }
    
    ll unsafe_rows_cols_diag1 = 0;
    for (auto r : rows) {
        for (auto c : cols) {
            if (diag1.count(r + c)) {
                unsafe_rows_cols_diag1++;
            }
        }
    }
    
    ll unsafe_rows_cols_diag2 = 0;
    for (auto r : rows) {
        for (auto c : cols) {
            if (diag2.count(r - c)) {
                unsafe_rows_cols_diag2++;
            }
        }
    }
    
    ll unsafe_rows_diag1_diag2 = 0;
    for (auto r : rows) {
        for (auto d1 : diag1) {
            for (auto d2 : diag2) {
                if ((d1 + d2) % 2 == 0) {
                    ll a = (d1 + d2) / 2;
                    ll b = (d1 - d2) / 2;
                    if (a == r && b >= 1 && b <= N) {
                        unsafe_rows_diag1_diag2++;
                    }
                }
            }
        }
    }
    
    ll unsafe_cols_diag1_diag2 = 0;
    for (auto c : cols) {
        for (auto d1 : diag1) {
            for (auto d2 : diag2) {
                if ((d1 + d2) % 2 == 0) {
                    ll a = (d1 + d2) / 2;
                    ll b = (d1 - d2) / 2;
                    if (b == c && a >= 1 && a <= N) {
                        unsafe_cols_diag1_diag2++;
                    }
                }
            }
        }
    }
    
    ll unsafe_all = unsafe_rows_cols_diag1 + unsafe_rows_cols_diag2 - unsafe_rows_cols_diag1_diag2;
    
    ll total_unsafe = unsafe_rows + unsafe_cols + unsafe_diag1 + unsafe_diag2 
                    - unsafe_rows_cols - unsafe_rows_diag1 - unsafe_rows_diag2 - unsafe_cols_diag1 - unsafe_cols_diag2 
                    + unsafe_rows_cols_diag1 + unsafe_rows_cols_diag2 + unsafe_rows_diag1_diag2 + unsafe_cols_diag1_diag2 - unsafe_all;
    
    ll safe = N * N - total_unsafe;
    cout << safe << endl;
    
    return 0;
}