#include <iostream>
#include <vector>
#include <set>
using namespace std;

#define MAXN 1000001

int n;
int m;
vector<pair<int, int>> pieces;
set<pair<int, int>> can_attack;
set<pair<int, int>> attackable;

// Directions a piece can attack from its position
const vector<pair<int, int>> attack_directions = {
    {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
    {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
};

int main() {
    cin >> n >> m;
    pieces.resize(m);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        pieces[i] = {x, y};
        can_attack.insert({x, y});

        // Check if this piece can attack any previously placed pieces
        for (const auto& dir : attack_directions) {
            int nx = x + dir.first;
            int ny = y + dir.second;
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= n) {
                attackable.insert({nx, ny});
            }
        }
    }

    // Calculate the number of empty squares
    long long total_squares = n * n;
    long long attacked_count = 0;

    for (const auto& p : can_attack) {
        for (const auto& dir : attack_directions) {
            int nx = p.first + dir.first;
            int ny = p.second + dir.second;
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= n) {
                attacked_count++;
            }
        }
    }

    long long safe_squares = total_squares - attacked_count;
    cout << safe_squares << endl;

    return 0;
}