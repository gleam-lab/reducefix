#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    i64 N, M;
    cin >> N >> M;
    vector<array<i64, 2>> pieces(M);
    for(int i = 0; i < M; ++i){
        cin >> pieces[i][0] >> pieces[i][1];
    }

    set<pair<i64, i64>> occupied;
    unordered_set<i64> sums, differences;
    for(auto &p : pieces){
        occupied.insert({p[0], p[1]});
        sums.insert(p[0] + p[1]);
        differences.insert(p[0] - p[1]);
    }

    i64 ans = 0;
    for(i64 i = 1; i <= N; ++i){
        for(i64 j = 1; j <= N; ++j){
            if(!occupied.count({i, j}) && !sums.count(i + j) && !differences.count(i - j)){
                ++ans;
            }
        }
    }

    cout << ans << '\n';
    return 0;
}