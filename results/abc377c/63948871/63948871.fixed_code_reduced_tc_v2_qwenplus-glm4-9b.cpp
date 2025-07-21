#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

#define INF 1000000000

vector<pair<int, int>> threatened_cells(int x, int y) {
    vector<pair<int, int>> threats = {
        {x + 2, y + 1}, {x + 1, y + 2}, {x - 1, y + 2}, {x - 2, y + 1},
        {x - 2, y - 1}, {x - 1, y - 2}, {x + 1, y - 2}, {x + 2, y - 1}
    };
    return threats;
}

int main() {
    int N, M;
    cin >> N >> M;
    set<pair<int, int>, greater<pair<int, int>>> occupied; // Use a multiset with custom comparator for decreasing order
    vector<pair<int, int>> occupied_cells;

    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        occupied.insert({x, y});
        occupied_cells.push_back({x, y});
    }

    set<pair<int, int>, greater<pair<int, int>>> occupied_cells_unique(occupied.begin(), occupied.end());
    set<pair<int, int>, greater<pair<int, int>>> threatened_cells_set;

    for (const auto& cell : occupied_cells_unique) {
        for (const auto& threat : threatened_cells(cell.first, cell.second)) {
            if (occupied.find(threat) == occupied.end()) {
                threatened_cells_set.insert(threat);
            }
        }
    }

    int total_cells = N * N;
    int unoccupied_cells = total_cells;
    for (const auto& cell : threatened_cells_set) {
        --unoccupied_cells;
    }

    cout << unoccupied_cells << endl;

    return 0;
}