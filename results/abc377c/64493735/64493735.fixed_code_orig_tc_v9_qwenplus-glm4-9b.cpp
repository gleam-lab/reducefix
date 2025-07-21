#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<pair<int, int>> pieces(M);
    for (int i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }
    
    set<pair<int, int>> captured_cells;
    
    // Define the capture patterns for each piece
    vector<vector<pair<int, int>>> capture_patterns = {
        {{1, 0}, {2, 1}},    // Down-Right
        {{1, 1}, {2, 2}},    // Down-Down-Right
        // ... (Other patterns)
    };
    
    // Apply capture patterns to each piece
    for (pair<int, int> piece : pieces) {
        for (auto pattern : capture_patterns) {
            int x1 = piece.first + pattern[0].first;
            int y1 = piece.second + pattern[0].second;
            if (x1 >= 1 && x1 <= N && y1 >= 1 && y1 <= N) {
                captured_cells.insert({x1, y1});
            }
            // Apply the remaining patterns
            // ...
        }
    }
    
    // Calculate the number of empty cells not captured by any piece
    int empty_cells = N * N - captured_cells.size();
    
    cout << empty_cells << endl;
    
    return 0;
}