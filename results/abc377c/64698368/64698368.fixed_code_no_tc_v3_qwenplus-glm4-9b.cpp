#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int dir[8][2] = {
    {0, 0}, {2, 1}, {1, 2}, {-1, 2},
    {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}
};

int main() {
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> positions(M);
    set<pair<int, int>> occupied;
    set<pair<int, int>> safe_spaces;

    for (int i = 0; i < M; ++i) {
        cin >> positions[i].first >> positions[i].second;
        occupied.insert({positions[i].first - 1, positions[i].second - 1});
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (occupied.find({i, j}) == occupied.end()) {
                bool is_safe = true;
                for (const auto& d : dir) {
                    int ni = i + d[0], nj = j + d[1];
                    if (ni >= 0 && ni < N && nj >= 0 && nj < N) {
                        if (occupied.find({ni, nj}) != occupied.end()) {
                            is_safe = false;
                            break;
                        }
                    }
                }
                if (is_safe) {
                    safe_spaces.insert({i, j});
                }
            }
        }
    }

    cout << safe_spaces.size() << endl;
}