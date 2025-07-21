#include <iostream>
#include <unordered_set>
#include <utility>

using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 N;
    int M;
    cin >> N >> M;

    unordered_multiset<pair<i64, i64>, function<size_t(const pair<i64, i64>&)>> unsafe(4 * M,
        [](const pair<i64, i64>& p) { return hash<i64>{}(p.first) ^ hash<i64>{}(p.second); });

    // Lambda to check if coordinate is within bounds
    auto valid = [&](i64 x, i64 y) {
        return x >= 1 && x <= N && y >= 1 && y <= N;
    };

    for (int _ = 0; _ < M; ++_) {
        i64 a, b;
        cin >> a >> b;

        // Add current piece position
        unsafe.emplace(a, b);

        // All 8 possible attacked positions
        const int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
        const int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

        for (int i = 0; i < 8; ++i) {
            i64 na = a + dx[i];
            i64 nb = b + dy[i];
            if (valid(na, nb)) {
                unsafe.emplace(na, nb);
            }
        }
    }

    // Total cells - unique unsafe cells = safe empty cells
    cout << (N * N - unsafe.size()) << '\n';

    return 0;
}