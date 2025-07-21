#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int maxN = 1000000;

int N, M;
set<pair<int, int>> occupied;
vector<vector<int>> captureRange(maxN + 1, vector<int>(maxN + 1, 0));

// Helper function to mark the capture range of a piece
void setCaptureRange(int x, int y) {
    captureRange[x + 2][y + 1] = captureRange[x + 1][y + 2] = captureRange[x - 1][y + 2] =
    captureRange[x - 2][y + 1] = captureRange[x - 2][y - 1] = captureRange[x - 1][y - 2] =
    captureRange[x + 1][y - 2] = captureRange[x + 2][y - 1] = 1;
}

int main() {
    cin >> N >> M;
    
    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        occupied.insert({x, y});
        setCaptureRange(x, y);
    }
    
    long long countUnoccupied = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (!occupied.count({i + 1, j + 1}) && captureRange[i + 1][j + 1] == 0) {
                countUnoccupied++;
            }
        }
    }
    
    cout << countUnoccupied << endl;
    
    return 0;
}