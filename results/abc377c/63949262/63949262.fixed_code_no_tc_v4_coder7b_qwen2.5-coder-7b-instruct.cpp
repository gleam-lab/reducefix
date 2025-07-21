#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>

using namespace std;

typedef uint64_t u64;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    u64 N;
    cin >> N;

    u64 M;
    cin >> M;

    unordered_set<u64> pieces;
    for (u64 i = 0; i < M; ++i) {
        u64 x, y;
        cin >> x >> y;
        
        u64 pos = (x - 1) * N + y - 1;
        pieces.insert(pos);

        auto check_and_add = [&](u64 dx, u64 dy) {
            u64 nx = x + dx, ny = y + dy;
            if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
                pieces.insert((nx - 1) * N + ny - 1);
            }
        };

        check_and_add(2, 1);
        check_and_add(1, 2);
        check_and_add(-1, 2);
        check_and_add(-2, 1);
        check_and_add(-2, -1);
        check_and_add(-1, -2);
        check_and_add(1, -2);
        check_and_add(2, -1);
    }

    u64 total_positions = N * N;
    u64 empty_positions = total_positions - pieces.size();

    cout << empty_positions << endl;

    return 0;
}