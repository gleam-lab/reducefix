#include <iostream>
#include <set>
#include <vector>

using namespace std;

using i64 = long long;
using Pii = pair<i64, i64>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 N, M;
    cin >> N >> M;

    set<Pii> blocked;
    vector<Pii> pieces(M);

    for (i64 i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
        blocked.insert({a, b});
    }

    // Define all possible attacked positions relative to a piece
    const vector<Pii> attack_offsets = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (const auto& [a, b] : pieces) {
        for (const auto& [dx, dy] : attack_offsets) {
            i64 x = a + dx;
            i64 y = b + dy;
            if (1 <= x && x <= N && 1 <= y && y <= N) {
                blocked.insert({x, y});
            }
        }
    }

    // Total squares - blocked squares
    cout << (N * N - (i64)blocked.size()) << '\n';

    return 0;
}