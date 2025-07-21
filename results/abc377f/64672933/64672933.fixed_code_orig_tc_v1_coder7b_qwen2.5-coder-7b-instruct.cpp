#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    i64 N, M;
    cin >> N >> M;
    
    vector<pair<i64, i64>> pieces(M);
    for (i64 i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }
    
    set<pair<i64, i64>> occupied;
    for (const auto& [x, y] : pieces) {
        occupied.insert({x, y});
        occupied.insert({x, y + N});
        occupied.insert({x + N, y});
        occupied.insert({x + N, y + N});
    }

    i64 ans = 0;
    for (i64 x = 0; x < N; ++x) {
        for (i64 y = 0; y < N; ++y) {
            if (occupied.find({x, y}) == end(occupied)) {
                ans++;
            }
        }
    }
    
    cout << ans << '\n';
    return 0;
}