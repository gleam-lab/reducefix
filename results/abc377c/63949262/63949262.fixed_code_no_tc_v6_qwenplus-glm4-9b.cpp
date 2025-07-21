#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define NMAX 1000000000

int main() {
    long long N, M;
    cin >> N >> M;

    // We will use a set to store the coordinates of occupied cells.
    set<pair<int, int>> occupied;
    for (long long i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        occupied.insert({x, y});
    }

    // We need to count all the cells that are not under attack by any of the occupied cells.
    long long free_cells = N * N;
    for (const auto& cell : occupied) {
        int x = cell.first;
        int y = cell.second;
        free_cells -= (x + 2 <= N && y + 1 <= N) + (x + 1 <= N && y + 2 <= N) +
                       (x - 1 >= 1 && y + 2 <= N) + (x - 2 >= 1 && y + 1 <= N) +
                       (x - 2 >= 1 && y - 1 >= 1) + (x - 1 >= 1 && y - 2 >= 1) +
                       (x + 1 <= N && y - 2 >= 1) + (x + 2 <= N && y - 1 >= 1);
    }

    cout << free_cells << endl;

    return 0;
}