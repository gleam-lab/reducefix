#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    long long n, m;
    cin >> n >> m;

    vector<vector<bool>> board(n, vector<bool>(n, false));
    unordered_set<long long> pieces;

    for(long long i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        --a, --b; // Adjusting for zero-based indexing
        pieces.insert(a * n + b);
        for(auto [dx, dy] : {{1,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{1,-1}}) {
            long long x = a + dx, y = b + dy;
            if(x >= 0 && x < n && y >= 0 && y < n) {
                pieces.insert(x * n + y);
            }
        }
    }

    long long ans = 0;
    for(long long i = 0; i < n; ++i) {
        for(long long j = 0; j < n; ++j) {
            if(!pieces.count(i * n + j)) {
                ans = (ans + 1) % MOD;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}