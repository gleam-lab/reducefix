#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long M;
    cin >> N >> M;

    set<pair<int, int>> pieces;
    vector<pair<int, int>> attacks;
    vector<vector<int>> grid(N + 1, vector<int>(N + 1, 0));

    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        pieces.insert({x, y});
        grid[x + 1][y + 1] = 1; // Mark the position of the piece

        // Calculate all positions that can be attacked by the piece
        vector<pair<int, int>> temp Attacks;
        temp.emplace_back(x + 2, y + 1);
        temp.emplace_back(x + 1, y + 2);
        temp.emplace_back(x - 1, y + 2);
        temp.emplace_back(x - 2, y + 1);
        temp.emplace_back(x - 2, y - 1);
        temp.emplace_back(x - 1, y - 2);
        temp.emplace_back(x + 1, y - 2);
        temp.emplace_back(x + 2, y - 1);

        for (auto& attack : temp) {
            if (attack.first <= 0 || attack.first > N || attack.second <= 0 || attack.second > N) continue; // Skip out-of-bounds attacks
            attacks.emplace_back(attack.first, attack.second);
        }
    }

    set<pair<int, int>> under_attack;
    for (auto& attack : attacks) {
        if (grid[attack.first][attack.second] == 0) { // Check if the square is empty
            under_attack.insert(attack);
        }
    }

    // Calculate the number of safe positions
    long long ans = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (grid[i][j] == 0 && under_attack.find({i, j}) == under_attack.end()) { // Check if the square is empty and not under attack
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}