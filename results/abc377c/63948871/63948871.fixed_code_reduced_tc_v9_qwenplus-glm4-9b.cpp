#include <iostream>
#include <vector>
#include <set>

using namespace std;

set<pair<int, int>> occupied;

bool canPlace(int x, int y) {
    for (auto& p : occupied) {
        int dx = p.first - x;
        int dy = p.second - y;
        if (abs(dx) == 2 && abs(dy) == 1) {
            return false;
        }
        if (abs(dx) == 1 && abs(dy) == 2) {
            return false;
        }
    }
    return true;
}

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        occupied.insert({x, y});
        // Check for all possible captures
        occupied.insert({x + 2, y + 1});
        occupied.insert({x + 1, y + 2});
        occupied.insert({x - 1, y + 2});
        occupied.insert({x - 2, y + 1});
        occupied.insert({x - 2, y - 1});
        occupied.insert({x - 1, y - 2});
        occupied.insert({x + 1, y - 2});
        occupied.insert({x + 2, y - 1});
    }

    int count = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (!occupied.count({i, j}) && canPlace(i, j)) {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}