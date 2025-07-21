#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;
using i64 = long long;

bool isSafe(int x, int y, const vector<pair<int, int>>& pieces) {
    for (auto& p : pieces) {
        int a, b;
        tie(a, b) = p;
        if (x == a || y == b || abs(x - y) == abs(a - b)) {
            return false;
        }
    }
    return true;
}

int main() {
    i64 N, M;
    cin >> N >> M;
    vector<pair<int, int>> pieces(M);
    for (i64 i = 0; i < M; ++i) {
        i64 x, y;
        cin >> x >> y;
        --x, --y; // Convert to 0-based index
        pieces[i] = {x, y};
    }

    i64 safeCount = 0;
    for (i64 i = 0; i < N; ++i) {
        for (i64 j = 0; j < N; ++j) {
            if (isSafe(i, j, pieces)) {
                ++safeCount;
            }
        }
    }

    cout << safeCount << endl;

    return 0;
}