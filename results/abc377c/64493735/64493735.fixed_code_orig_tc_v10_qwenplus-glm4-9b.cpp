#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> pieces(M);
    for (int i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    unordered_set<int> occupied;
    for (auto& p : pieces) {
        occupied.insert(p.first * N + p.second);
    }

    int answer = N * N;
    for (auto& p : pieces) {
        int x = p.first;
        int y = p.second;

        // Directions in hexagonal grid (8 possible moves)
        vector<pair<int, int>> directions = {
            {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
            {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
        };

        for (auto& dir : directions) {
            int nx = x + dir.first;
            int ny = y + dir.second;
            if (1 <= nx && nx <= N && 1 <= ny && ny <= N) {
                answer--;
            }
        }
    }

    cout << answer << endl;
}