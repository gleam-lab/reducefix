#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_SIZE 1000000
#define INF 0x3f3f3f3f

vector<vector<int>> grid;

void markCapture(int x, int y) {
    int directions[8][2] = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };
    
    for (auto dir : directions) {
        int nx = x + dir[0];
        int ny = y + dir[1];
        if (nx >= 1 && nx <= MAX_SIZE && ny >= 1 && ny <= MAX_SIZE) {
            grid[nx][ny] = 1; // Mark as captured
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    
    grid.resize(MAX_SIZE + 1, vector<int>(MAX_SIZE + 1, 0)); // +1 to handle 1-based indexing
    
    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        markCapture(x, y);
    }
    
    int safeCount = 0;
    for (int i = 1; i <= MAX_SIZE; ++i) {
        for (int j = 1; j <= MAX_SIZE; ++j) {
            if (grid[i][j] == 0) { // If the square is not captured
                safeCount++;
            }
        }
    }
    
    cout << safeCount << endl;
    
    return 0;
}