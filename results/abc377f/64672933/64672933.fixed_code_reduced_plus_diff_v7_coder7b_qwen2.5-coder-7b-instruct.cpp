#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    i64 N, M;
    cin >> N >> M;
    vector<array<i64, 2>> g(M);
    set<pair<i64, i64>> occupied;
    
    for (int i = 0; i < M; i++) {
        i64 a, b;
        cin >> a >> b;
        g[i] = {a, b};
        occupied.insert({a, b});
    }
    
    vector<i64> sums(N + N, 0);
    vector<i64> diffs(N + N, 0);
    vector<i64> cols(N + 1, 0);
    vector<i64> rows(N + 1, 0);
    
    for (const auto& [a, b] : g) {
        sums[a + b]++;
        diffs[a - b]++;
        rows[a]++;
        cols[b]++;
    }
    
    i64 ans = 0;
    
    for (i64 r = 1; r <= N; ++r) {
        for (i64 c = 1; c <= N; ++c) {
            if (!occupied.count({r, c}) &&
                sums[r + c] == 1 && diffs[r - c] == 1 && rows[r] == 1 && cols[c] == 1) {
                ans++;
            }
        }
    }
    
    cout << ans << "\n";
    return 0;
}