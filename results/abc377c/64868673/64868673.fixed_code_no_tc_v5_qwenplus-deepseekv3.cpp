#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    set<pair<long long, long long>> forbidden;
    vector<pair<long long, long long>> pieces(M);
    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
    }
    
    vector<int> dx = {2, 2, -2, -2, 1, 1, -1, -1};
    vector<int> dy = {1, -1, 1, -1, 2, -2, 2, -2};
    
    for (auto [a, b] : pieces) {
        for (int i = 0; i < 8; ++i) {
            long long x = a + dx[i];
            long long y = b + dy[i];
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                forbidden.insert({x, y});
            }
        }
    }
    
    // The answer is total squares minus occupied squares minus forbidden squares
    // But occupied squares may overlap with forbidden squares, so we need to subtract only unique squares
    long long total_forbidden = forbidden.size();
    for (auto [a, b] : pieces) {
        if (forbidden.count({a, b})) {
            total_forbidden--;
        }
    }
    
    long long ans = N * N - M - total_forbidden;
    cout << ans << endl;
    
    return 0;
}