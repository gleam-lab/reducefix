#include <iostream>
#include <vector>
#include <set>
using namespace std;

const vector<pair<int, int>> directions = {
    {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, 
    {-2, 1}, {-1, 2}
};

set<pair<int, int>> capture_positions(int a, int b) {
    set<pair<int, int>> capt;
    for (auto dir : directions) {
        int na = a + dir.first * 2, nb = b + dir.second * 2;
        if (1 <= na && na <= N && 1 <= nb && nb <= N) {
            capt.insert({na, nb});
        }
    }
    return capt;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<set<pair<int, int>>>> occupied(N + 1, vector<set<pair<int, int>>>(N + 1));
    for (int i = 1; i <= M; ++i) {
        int a, b;
        cin >> a >> b;
        occupied[a][b] = capture_positions(a, b);
    }

    long long empty_cells = N * N;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (!occupied[i][j].empty()) {
                empty_cells--;
            }
        }
    }

    cout << empty_cells << endl;

    return 0;
}