#include <iostream>
#include <vector>
#include <set>
using namespace std;

int N, M;
set<pair<int, int>> marked;

void mark(int a, int b) {
    // Mark all the positions that can be captured by the piece at (a, b)
    vector<pair<int, int>> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };
    for (auto& dir : directions) {
        int x = a + dir.first, y = b + dir.second;
        if (x >= 1 && x <= N && y >= 1 && y <= N) {
            marked.insert({x, y});
        }
    }
}

int main() {
    cin >> N >> M;
    vector<pair<int, int>> pieces(M);

    for (int i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
        mark(pieces[i].first, pieces[i].second);
    }

    // Total number of squares minus the number of marked squares
    cout << N * N - marked.size();
    return 0;
}