#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXN 1000000000 + 1

vector<bool> grid(MAXN, true);

int main() {
    int N, M;
    cin >> N >> M;
    
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        int x = a, y = b;
        
        // Mark all squares that can be captured by the piece at (a, b)
        grid[x] = false;
        grid[y] = false;
        grid[x + 2] = false;
        grid[y + 1] = false;
        grid[x + 1] = false;
        grid[y + 2] = false;
        grid[x - 1] = false;
        grid[x - 2] = false;
        grid[y - 1] = false;
        grid[x - 2] = false;
        grid[y - 2] = false;
        grid[x + 2] = false;
        grid[y - 1] = false;
    }
    
    // Count the number of empty squares
    long long emptySquares = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (grid[i * N + j]) {
                ++emptySquares;
            }
        }
    }
    
    cout << emptySquares << endl;
    
    return 0;
}