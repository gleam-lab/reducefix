#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

const int dirX[8] = {2, 2, 1, -1, -2, -2, -1, 1};
const int dirY[8] = {1, -1, 2, 2, 1, -1, -2, -2};

set<pair<int, int>> occupied;
vector<pair<int, int>> attackable;

int main() {
    int n, m;
    cin >> n >> m;
    n++; // To handle 1-based indexing
    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        occupied.emplace(a, b);
        for (int j = 0; j < 8; ++j) {
            int nx = a + dirX[j];
            int ny = b + dirY[j];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= n) {
                attackable.emplace_back(nx, ny);
            }
        }
    }

    // Sort attackable grid points (not occupied or already attacked) in descending order
    sort(attackable.begin(), attackable.end(), [&](const pair<int, int>& a, const pair<int, int>& b) {
        return (a.first * a.first + a.second * a.second) > (b.first * b.first + b.second * b.second);
    });

    long long empty = n * n;
    long long valid = 0;
    set<pair<int, int>> toRemove;

    for (const auto& point : attackable) {
        if (occupied.find(point) != occupied.end()) {
            valid++;
        } else {
            for (const auto& dir : toRemove) {
                int x = point.first + dir.first - 1;
                int y = point.second + dir.second - 1;
                if (x >= 1 && x <= n && y >= 1 && y <= n) {
                    occupied.emplace(x, y);
                }
                x = point.first + dir.first + 1;
                y = point.second + dir.second + 1;
                if (x >= 1 && x <= n && y >= 1 && y <= n) {
                    occupied.emplace(x, y);
                }
                x = point.first + dir.first + 2;
                y = point.second + dir.second + 2;
                if (x >= 1 && x <= n && y >= 1 && y <= n) {
                    occupied.emplace(x, y);
                }
                x = point.first + dir.first - 2;
                y = point.second + dir.second - 2;
                if (x >= 1 && x <= n && y >= 1 && y <= n) {
                    occupied.emplace(x, y);
                }
            }
            toRemove.clear();
            for (int i = 0; i < 8; ++i) {
                toRemove.emplace(point.first + dirX[i], point.second + dirY[i]);
            }
        }
    }

    cout << empty - valid << endl;
    return 0;
}