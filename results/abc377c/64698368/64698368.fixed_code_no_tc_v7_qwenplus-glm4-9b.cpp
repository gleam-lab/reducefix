#include <iostream>
#include <vector>
#include <set>

using namespace std;

// Define the capture directions
const vector<pair<int, int>> directions = {
    {0, 0},
    {2, 1},
    {1, 2},
    {-1, 2},
    {-2, 1},
    {-2, -1},
    {-1, -2},
    {1, -2},
    {2, -1}
};

int N, M;

bool canBeCaptured(int a, int b, const set<pair<int, int>>& captured) {
    for (auto dir : directions) {
        int x = a + dir.first * 2;
        int y = b + dir.second * 2;
        if (x >= 0 && x < N && y >= 0 && y < N) {
            if (captured.find({x, y}) != captured.end()) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    cin >> N >> M;
    set<pair<int, int>> captured;

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        captured.insert({a - 1, b - 1});
    }

    int count = 0;
    for (int a = 0; a < N; ++a) {
        for (int b = 0; b < N; ++b) {
            if (captured.find({a, b}) == captured.end() && !canBeCaptured(a, b, captured)) {
                count++;
            }
        }
    }

    cout << count << endl;
    return 0;
}