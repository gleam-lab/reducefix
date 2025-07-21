#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

const int MOD = 1e9 + 7;

bool isValid(int x, int y, int N) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

int main() {
    long long N, M;
    cin >> N >> M;
    
    unordered_set<long long> unsafeSquares;
    vector<vector<bool>> grid(N, vector<bool>(N, false));
    
    vector<int> dx = {1, 1, -1, -1, 2, 2, -2, -2};
    vector<int> dy = {2, -2, 2, -2, 1, -1, 1, -1};

    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        --a, --b; // Convert to zero-based index
        
        for (int d = 0; d < 8; ++d) {
            int nx = a + dx[d], ny = b + dy[d];
            while (isValid(nx, ny, N)) {
                if (grid[nx][ny]) break;
                unsafeSquares.insert((nx * N + ny) % MOD);
                nx += dx[d];
                ny += dy[d];
            }
        }
        
        grid[a][b] = true;
    }

    long long totalEmpty = N * N - M;
    for (auto& pos : unsafeSquares) {
        totalEmpty -= (pos / N + 1);
    }
    
    cout << (totalEmpty + MOD) % MOD << endl;
    return 0;
}