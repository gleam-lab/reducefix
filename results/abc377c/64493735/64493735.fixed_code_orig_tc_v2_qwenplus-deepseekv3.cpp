#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    int M;
    cin >> N >> M;

    set<pair<int, int>> occupied;
    set<pair<int, int>> under_attack;

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        occupied.insert({a, b});

        // All 8 possible attack positions
        vector<pair<int, int>> directions = {
            {a+2, b+1}, {a+1, b+2}, {a-1, b+2}, {a-2, b+1},
            {a-2, b-1}, {a-1, b-2}, {a+1, b-2}, {a+2, b-1}
        };

        for (const auto& [x, y] : directions) {
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                under_attack.insert({x, y});
            }
        }
    }

    // Total squares under attack or occupied
    long long total_under_attack_or_occupied = under_attack.size();
    for (const auto& pos : occupied) {
        if (under_attack.find(pos) == under_attack.end()) {
            total_under_attack_or_occupied++;
        }
    }

    long long safe_squares = N * N - total_under_attack_or_occupied;
    cout << safe_squares << '\n';

    return 0;
}