#include <iostream>
#include <vector>
#include <set>
#include <utility>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    cin >> N >> M;

    set<pair<long long, long long>> knights;
    vector<pair<int, int>> directions = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

    for (long long i = 0; i < M; ++i) {
        long long x, y;
        cin >> x >> y;
        knights.insert({x, y});
    }

    for (const auto& knight : knights) {
        for (const auto& dir : directions) {
            long long nx = knight.first + dir.first;
            long long ny = knight.second + dir.second;
            if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
                knights.insert({nx, ny});
            }
        }
    }

    cout << N * N - knights.size() << endl;

    return 0;
}