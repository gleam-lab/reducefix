#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;

    set<pair<long long, long long>> invalid;
    set<pair<long long, long long>> occupied;

    vector<pair<int, int>> moves = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        a--; b--;
        occupied.insert({a, b});
        for (auto [dx, dy] : moves) {
            long long x = a + dx;
            long long y = b + dy;
            if (x >= 0 && x < N && y >= 0 && y < N) {
                invalid.insert({x, y});
            }
        }
    }

    // The total invalid positions are the union of 'occupied' and 'invalid'
    for (auto pos : occupied) {
        invalid.insert(pos);
    }

    long long total = N * N;
    long long answer = total - invalid.size();
    cout << answer << endl;

    return 0;
}