#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Pair {
    int x, y;
    Pair(int x, int y) : x(x), y(y) {}
};

const int MAXN = 1000;

int H, W, Y;
vector<vector<int>> A;
vector<vector<bool>> visited;
vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void processYear(int year) {
    priority_queue<pair<int, Pair>, vector<pair<int, Pair>>, greater<pair<int, Pair>>> minHeap;
    int remainingLand = 0;
    
    // Initialize the heap with boundary cells
    for (int i = 0; i < H; ++i) {
        minHeap.push(make_pair(A[i][0], Pair(i, 0)));
        minHeap.push(make_pair(A[i][W - 1], Pair(i, W - 1)));
        visited[i][0] = visited[i][W - 1] = true;
    }
    
    for (int i = 0; i < W; ++i) {
        minHeap.push(make_pair(A[0][i], Pair(0, i)));
        minHeap.push(make_pair(A[H - 1][i], Pair(H - 1, i)));
        visited[0][i] = visited[H - 1][i] = true;
    }
    
    while (!minHeap.empty()) {
        auto p = minHeap.top();
        minHeap.pop();
        int elevation = p.first;
        
        if (elevation <= year) {
            continue;
        }
        
        for (int i = 0; i < 4; ++i) {
            int nx = p.second.x + directions[i][0];
            int ny = p.second.y + directions[i][1];
            
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny] && A[nx][ny] > year) {
                visited[nx][ny] = true;
                minHeap.push(make_pair(A[nx][ny], Pair(nx, ny)));
            }
        }
    }
    
    // Count the remaining land
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (!visited[i][j]) {
                remainingLand++;
            }
        }
    }
    
    cout << remainingLand << endl;
}

int main() {
    cin >> H >> W >> Y;
    A.assign(H, vector<int>(W));
    visited.assign(H, vector<bool>(W, false));
    
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }
    
    for (int year = 1; year <= Y; ++year) {
        processYear(year);
    }
    
    return 0;
}