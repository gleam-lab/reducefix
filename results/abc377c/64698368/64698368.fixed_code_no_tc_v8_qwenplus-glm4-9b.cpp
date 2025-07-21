#include <iostream>
#include <vector>
#include <set>
using namespace std;

#define rep(i, n) for (int i = 1; i <= n; i++)
#define all(x) begin(x), end(x)

int N, M;
vector<pair<int, int>> pieces;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    pieces.resize(M);
    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        --x, --y; // Convert 1-based index to 0-based
        pieces[i] = {x, y};
    }

    // Directions that a piece can capture
    vector<pair<int, int>> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    set<pair<int, int>> occupied;
    for (auto& p : pieces) {
        occupied.insert(p);
        for (auto& dir : directions) {
            int nx = p.first + dir.first;
            int ny = p.second + dir.second;
            if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                occupied.insert({nx, ny});
            }
        }
    }

    // Calculate the number of empty cells
    long long total_cells = N * N;
    long long occupied_cells = occupied.size();
    cout << total_cells - occupied_cells << '\n';

    return 0;
}