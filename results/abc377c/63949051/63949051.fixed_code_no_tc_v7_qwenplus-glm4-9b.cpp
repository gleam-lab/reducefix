#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define MAXN 1000000000

int main() {
    int N;
    long long M;
    cin >> N >> M;

    vector<pair<int, int>> pieces(M);
    for (int i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    // Use a set to track the coordinates that are attacked by the pieces
    set<pair<int, int>> attacked;
    for (const auto& p : pieces) {
        int x = p.first;
        int y = p.second;

        // Calculate the coordinates that can be attacked by the piece at (x, y)
        vector<pair<int, int>> can_attack = {
            {x + 2, y + 1}, {x + 1, y + 2}, {x - 1, y + 2},
            {x - 2, y + 1}, {x - 2, y - 1}, {x - 1, y - 2},
            {x + 1, y - 2}, {x + 2, y - 1}
        };

        // Insert the coordinates into the set
        for (const auto& a : can_attack) {
            if (a.first >= 1 && a.first <= N && a.second >= 1 && a.second <= N) {
                attacked.insert(a);
            }
        }
    }

    // Calculate the number of safe cells
    long long total_cells = N * N;
    long long attacked_cells = attacked.size();
    long long safe_cells = total_cells - attacked_cells;

    cout << safe_cells << endl;

    return 0;
}