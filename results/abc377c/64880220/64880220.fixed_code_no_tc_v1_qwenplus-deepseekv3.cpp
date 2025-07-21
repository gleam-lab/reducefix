#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    set<pair<long long, long long>> pieces;
    set<pair<long long, long long>> unsafe;

    vector<pair<int, int>> moves = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < M; i++) {
        long long a, b;
        cin >> a >> b;
        pieces.insert({a, b});
        unsafe.insert({a, b});

        for (auto [dx, dy] : moves) {
            long long x = a + dx;
            long long y = b + dy;
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                unsafe.insert({x, y});
            }
        }
    }

    long long total_safe = N * N - unsafe.size();
    cout << total_safe << endl;
    return 0;
}