#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int dx[8] = {2, 2, 1, 1, -1, -1, -2, -2};
const int dy[8] = {1, -1, 2, -2, 2, -2, -1, 1};

bool isWithinBounds(int x, int y, int N) {
    return x >= 1 && x <= N && y >= 1 && y <= N;
}

int main() {
    int N, M;
    cin >> N >> M;
    
    set<pair<int, int>> attacked;
    
    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        for (int j = 0; j < 8; ++j) {
            int nx = x + dx[j], ny = y + dy[j];
            if (isWithinBounds(nx, ny, N)) {
                attacked.insert({nx, ny});
            }
        }
    }
    
    long long totalCells = N * N;
    long long unsafeCells = attacked.size();
    long long safeCells = totalCells - unsafeCells;
    cout << safeCells << endl;
    
    return 0;
}