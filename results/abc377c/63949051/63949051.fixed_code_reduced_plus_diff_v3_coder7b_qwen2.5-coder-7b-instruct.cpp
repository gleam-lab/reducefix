#include <iostream>
#include <vector>
#include <array>
#include <unordered_set>

using namespace std;

const array<array<int, 2>, 8> knight_moves = {{
    {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
    {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
}};

bool isValid(int x, int y, int n) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    unordered_set<long long> occupied;

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        --x, --y; // Convert to zero-based index
        occupied.insert(((long long)x * n) + y);
    }

    long long count = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            bool safe = true;
            for (const auto& move : knight_moves) {
                int nx = i + move[0];
                int ny = j + move[1];
                if (isValid(nx, ny, n)) {
                    if (occupied.count(((long long)nx * n) + ny)) {
                        safe = false;
                        break;
                    }
                }
            }
            if (safe) {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}