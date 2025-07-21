#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    i64 N, M;
    cin >> N >> M;
    vector<pair<i64, i64>> pieces(M);
    set<pair<i64, i64>> occupied;
    set<i64> sum_set, diff_set;
    
    for(i64 i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
        occupied.insert(pieces[i]);
        sum_set.insert(pieces[i].first + pieces[i].second);
        diff_set.insert(pieces[i].first - pieces[i].second);
    }
    
    i64 ans = 0;
    for(i64 i = 1; i <= N; ++i) {
        for(i64 j = 1; j <= N; ++j) {
            if(!occupied.count({i, j})) {
                bool safe = true;
                // Check same row and column
                for(i64 k = 1; k <= N; ++k) {
                    if(k != i && !occupied.count({k, j})) continue;
                    if(k != j && !occupied.count({i, k})) continue;
                    safe = false;
                    break;
                }
                if(safe) {
                    // Check diagonal sums and differences
                    for(auto &s : sum_set) {
                        if(s == i + j && s != i + j - 1) safe = false;
                    }
                    for(auto &d : diff_set) {
                        if(d == i - j && d != i - j + 1) safe = false;
                    }
                }
                if(safe) ++ans;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}