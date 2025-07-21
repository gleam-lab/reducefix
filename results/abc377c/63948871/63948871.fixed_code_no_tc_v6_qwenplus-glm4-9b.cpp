#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

#define INF 1000000000

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<pair<int, int>> pieces(M);
    for (int i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }
    
    unordered_set<pair<int, int>> captured;
    
    // Check all possible positions within capture range for each piece
    for (int i = 0; i < M; ++i) {
        auto [x, y] = pieces[i];
        for (int di = -2; di <= 2; ++di) {
            for (int dj = -2; dj <= 2; ++dj) {
                if (di == 0 && dj == 0) continue; // Skip the piece itself
                if (x + di >= 1 && x + di <= N && y + dj >= 1 && y + dj <= N) {
                    captured.insert({x + di, y + dj});
                }
            }
        }
    }
    
    // Calculate the number of empty cells not captured by any piece
    int empty_cells = N * N - captured.size();
    cout << empty_cells;
    
    return 0;
}