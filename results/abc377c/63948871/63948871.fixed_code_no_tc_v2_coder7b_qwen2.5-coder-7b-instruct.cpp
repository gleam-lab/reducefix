#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int directions[8][2] = {
    {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
    {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int M;
    cin >> M;

    set<pair<int, int>> occupied;
    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        occupied.insert({x, y});

        for (auto& dir : directions) {
            int nx = x + dir[0];
            int ny = y + dir[1];
            if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
                occupied.insert({nx, ny});
            }
        }
    }

    int valid_positions = N * N - occupied.size();
    cout << valid_positions << endl;

    return 0;
}