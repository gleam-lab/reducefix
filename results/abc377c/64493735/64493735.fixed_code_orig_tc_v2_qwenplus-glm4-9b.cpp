#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<pair<int, int>> capture[1001]; // Assuming max N is 1000 for simplicity
    vector<pair<int, int>> positions;
    
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        positions.emplace_back(a, b);
        
        // Define the capture pattern
        vector<pair<int, int>> patterns = {
            {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
        };
        
        for (auto &pattern : patterns) {
            int x = a + pattern.first, y = b + pattern.second;
            if (1 <= x && x <= N && 1 <= y && y <= N) {
                capture[x].emplace_back(y);
            }
        }
    }
    
    int capturedCount = 0;
    for (auto &pos : positions) {
        // Increment captured count for each square in the capture area
        for (auto &cap : capture[pos.first]) {
            capturedCount++;
        }
    }
    
    int totalSquares = N * N;
    cout << totalSquares - capturedCount << endl;
    
    return 0;
}