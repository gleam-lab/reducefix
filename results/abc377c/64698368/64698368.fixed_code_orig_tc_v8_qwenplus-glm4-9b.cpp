#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int N, M;
set<pair<int, int>> safe_squares;

void mark_unsafe(int a, int b, const vector<pair<int, int>>& capture_range) {
    for (auto& p : capture_range) {
        int x = a + p.first;
        int y = b + p.second;
        if (x >= 0 && x < N && y >= 0 && y < N) {
            safe_squares.insert({x, y});
        }
    }
}

int main() {
    cin >> N >> M;
    
    vector<pair<int, int>> capture_range = {
        {0, 0}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--; // Convert to 0-based index
        mark_unsafe(a, b, capture_range);
    }

    // Calculate the number of safe squares
    int safe_count = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (safe_squares.find({i, j}) == safe_squares.end()) {
                safe_count++;
            }
        }
    }

    cout << safe_count << endl;
    return 0;
}