#include <iostream>
#include <vector>
#include <set>

using namespace std;

const vector<vector<pair<int, int>>> vic = {
    {{0, 0}}, {{2, 1}}, {{1, 2}}, {{-1, 2}}, {{-2, 1}}, {{-2, -1}},
    {{-1, -2}}, {{1, -2}}, {{2, -1}}
};

int main() {
    int N, M;
    cin >> N >> M;

    set<pair<int, int>> valid_cells;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        for (auto &vec : vic) {
            int nx = a + vec[0].first;
            int ny = b + vec[0].second;
            if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                valid_cells.insert({nx, ny});
            }
        }
    }

    int N2 = N * N;
    cout << N2 - valid_cells.size();
    return 0;
}