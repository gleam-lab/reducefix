#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    long long n, m;
    cin >> n >> m;
    set<pair<long long, long long>> pieces;

    for(long long i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        pieces.insert({a, b});
    }

    long long ans = 0;
    for(long long i = 1; i <= n; ++i) {
        for(long long j = 1; j <= n; ++j) {
            bool valid = true;
            vector<pair<long long, long long>> directions = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
            for(auto [di, dj] : directions) {
                long long ni = i + di, nj = j + dj;
                if(ni >= 1 && ni <= n && nj >= 1 && nj <= n && pieces.find({ni, nj}) != pieces.end()) {
                    valid = false;
                    break;
                }
            }
            if(valid) ++ans;
        }
    }

    cout << ans << '\n';

    return 0;
}