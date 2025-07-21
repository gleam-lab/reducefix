#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN = 1e9;
int N, M;
vector<pair<int, int>> pieces;

// æ£æ¥ä¸ä¸ªä½ç½®æ¯å¦å¨ç½æ ¼
bool in_bounds(int x, int y) {
    return 0 <= x && x < N && 0 <= y && y < N;
}

// æ£æ¥ä¸ä¸ªä½ç½®æ¯å¦è¢«æä¸ªæ£å­æè·
bool is_captured(int x, int y) {
    for (auto& p : pieces) {
        int a, b;
        tie(a, b) = p;
        if (in_bounds(x + 2, y + 1)) {
            if (in_bounds(a + 2, b + 1) && (x + 2 == a + 2 && y + 1 == b + 1)) return true;
        }
        if (in_bounds(x + 1, y + 2)) {
            if (in_bounds(a + 1, b + 2) && (x + 1 == a + 1 && y + 2 == b + 2)) return true;
        }
        if (in_bounds(x - 1, y + 2)) {
            if (in_bounds(a - 1, b + 2) && (x - 1 == a - 1 && y + 2 == b + 2)) return true;
        }
        if (in_bounds(x - 2, y + 1)) {
            if (in_bounds(a - 2, b + 1) && (x - 2 == a - 2 && y + 1 == b + 1)) return true;
        }
        if (in_bounds(x - 2, y - 1)) {
            if (in_bounds(a - 2, b - 1) && (x - 2 == a - 2 && y - 1 == b - 1)) return true;
        }
        if (in_bounds(x - 1, y - 2)) {
            if (in_bounds(a - 1, b - 2) && (x - 1 == a - 1 && y - 2 == b - 2)) return true;
        }
        if (in_bounds(x + 1, y - 2)) {
            if (in_bounds(a + 1, b - 2) && (x + 1 == a + 1 && y - 2 == b - 2)) return true;
        }
        if (in_bounds(x + 2, y - 1)) {
            if (in_bounds(a + 2, b - 1) && (x + 2 == a + 2 && y - 1 == b - 1)) return true;
        }
    }
    return false;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        pieces.push_back({a - 1, b - 1});
    }

    int available_spaces = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (!is_captured(i, j)) {
                available_spaces++;
            }
        }
    }

    cout << available_spaces << endl;

    return 0;
}