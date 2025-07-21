#include <iostream>
#include <vector>
using namespace std;

const int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
const int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<vector<bool>> grid(N, vector<bool>(N, false));
    
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        int count = 0;
        
        for (int j = 0; j < 8; j++) {
            int nx = x + dx[j];
            int ny = y + dy[j];
            
            if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                grid[nx][ny] = true;
                count++;
            }
        }
        
        // If count is zero, it means the piece can capture all around, so all cells within the grid are captured.
        if (count == 0) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    grid[i][j] = true;
                }
            }
            break;
        }
    }
    
    int emptyCount = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!grid[i][j]) {
                emptyCount++;
            }
        }
    }
    
    cout << emptyCount << endl;
    
    return 0;
}