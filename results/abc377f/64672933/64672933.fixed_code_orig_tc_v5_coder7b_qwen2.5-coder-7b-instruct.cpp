#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    i64 N, M;
    cin >> N >> M;
    
    vector<pair<i64, i64>> g(M);
    set<pair<i64, i64>> occupied;
    set<i64> rows, cols, diagonals1, diagonals2;
    
    for (int i = 0; i < M; i++) {
        i64 a, b;
        cin >> a >> b;
        g[i] = {a, b};
        occupied.insert({a, b});
        rows.insert(a);
        cols.insert(b);
        diagonals1.insert(a + b);
        diagonals2.insert(a - b);
    }
    
    i64 ans = 0;
    
    for (i64 r = 1; r <= N; r++) {
        if (!rows.count(r)) {
            for (i64 c = 1; c <= N; c++) {
                if (!cols.count(c) && !diagonals1.count(r + c) && !diagonals2.count(r - c)) {
                    ans++;
                }
            }
        }
    }
    
    cout << ans << '\n';
    
    return 0;
}