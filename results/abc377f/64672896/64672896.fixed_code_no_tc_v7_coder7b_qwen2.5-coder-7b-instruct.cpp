#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 N, M;
    cin >> N >> M;
    
    vector<pair<i64, i64>> positions(M);
    set<pair<i64, i64>> occupied;

    for (i64 i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        positions[i] = {a, b};
        occupied.insert({a, b});
        occupied.insert({a + b, a - b});
    }

    i64 count = 0;
    for (i64 i = 1; i <= N; ++i) {
        for (i64 j = 1; j <= N; ++j) {
            bool can_place = true;
            for (const auto& pos : positions) {
                if (pos.first == i || pos.second == j || pos.first + pos.second == i + j || pos.first - pos.second == i - j) {
                    can_place = false;
                    break;
                }
            }
            if (can_place && !occupied.count({i, j})) {
                ++count;
            }
        }
    }

    cout << count << "\n";

    return 0;
}