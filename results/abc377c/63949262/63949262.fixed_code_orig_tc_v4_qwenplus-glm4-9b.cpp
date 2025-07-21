#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int attack_directions[8][2] = {
    {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
    {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
};

int main() {
    int N, M;
    cin >> N >> M;

    set<pair<int, int>> attackable_cells;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        for (int j = 0; j < 8; ++j) {
            int dx = attack_directions[j][0] + a - 1;
            int dy = attack_directions[j][1] + b - 1;
            if (dx >= 0 && dx < N && dy >= 0 && dy < N) {
                attackable_cells.insert({dx, dy});
            }
        }
    }

    int result = N * N;
    for (const auto& cell : attackable_cells) {
        --result;
    }

    cout << result << endl;

    return 0;
}