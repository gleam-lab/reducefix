#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

long long power(long long base, long long exp, long long mod) {
    if (exp == 0)
        return 1;
    long long halfPower = power(base, exp / 2, mod);
    long long result = (halfPower * halfPower) % mod;
    if (exp % 2 != 0)
        result = (result * base) % mod;
    return result;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    long long n, m;
    cin >> n >> m;
    
    set<long long> rows, cols, diag1, diag2;
    for (int i = 0; i < m; ++i) {
        long long x, y;
        cin >> x >> y;
        rows.insert(x);
        cols.insert(y);
        diag1.insert(x + y);
        diag2.insert(x - y);
    }
    
    long long total_empty_squares = n * n;
    total_empty_squares -= (rows.size() * (n - rows.size())) % mod;
    total_empty_squares -= (cols.size() * (n - cols.size())) % mod;
    total_empty_squares += (diag1.size() * (n - diag1.size())) % mod;
    total_empty_squares += (diag2.size() * (n - diag2.size())) % mod;
    total_empty_squares = (total_empty_squares + mod) % mod;
    
    cout << total_empty_squares << '\n';
    
    return 0;
}