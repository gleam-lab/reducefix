#include <iostream>
#include <vector>
#include <set>
#include <cstring>
using namespace std;

const int MAX_N = 1e9;
const int MAX_M = 2e5;

int main() {
    int N, M;
    cin >> N >> M;

    set<pair<int, int>> pieces;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        pieces.insert({a, b});

        // Check all 8 possible directions
        for (int dx = -2; dx <= 2; ++dx) {
            for (int dy = -2; dy <= 2; ++dy) {
                if (dx == 0 && dy == 0) continue;
                int nx = a + dx;
                int ny = b + dy;
                if (1 <= nx && nx <= N && 1 <= ny && ny <= N) {
                    pieces.insert({nx, ny});
                }
            }
        }
    }

    int count = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            bool is_safe = true;
            for (const auto& p : pieces) {
                if (p.first == i || p.first == i + 2 || p.first == i - 2) {
                    if (abs(p.second - j) <= 2) {
                        is_safe = false;
                        break;
                    }
                }
                if (p.second == j || p.second == j + 2 || p.second == j - 2) {
                    if (abs(p.first - i) <= 2) {
                        is_safe = false;
                        break;
                    }
                }
            }
            if (is_safe) count++;
        }
    }

    cout << count << endl;
    return 0;
}