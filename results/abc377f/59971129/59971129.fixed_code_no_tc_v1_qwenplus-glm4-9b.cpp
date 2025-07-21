#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define N 1005

ll n, m, a[N], b[N], ans;

set<ll> rows, cols, diag1, diag2;

int main() {
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= m; ++i) {
        scanf("%lld%lld", &a[i], &b[i]);
        rows.insert(a[i]);
        cols.insert(b[i]);
        diag1.insert(a[i] + b[i]);
        diag2.insert(a[i] - b[i]);
    }
    
    // Start with total number of squares minus occupied by rows, cols, diag1, diag2
    ans = n * n - rows.size() * n - cols.size() * n - diag1.size() * n - diag2.size() * n;
    
    // Subtract overlaps in rows and cols
    for (auto row : rows) {
        for (auto col : cols) {
            ans -= (row == col) * (diag1.find(row + col) != diag1.end()) * n;
        }
    }
    
    // Subtract overlaps in diag1 and diag2
    for (auto diag : diag1) {
        ans -= (diag - n < diag2.begin()) * (diag2.end() <= diag + n);
    }
    
    printf("%lld\n", ans);
    return 0;
}