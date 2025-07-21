#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e9 + 10;
vector<vector<bool>> unsafe(MAXN, vector<bool>(MAXN));

bool isValid(int x, int y, int n) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

void markUnsafeSquares(int n) {
    vector<pair<int, int>> directions = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (auto& dir : directions) {
                int nx = i + dir.first;
                int ny = j + dir.second;
                
                if (!isValid(nx, ny, n)) continue;
                
                int nnx = nx + dir.first;
                int nny = ny + dir.second;
                
                if (!isValid(nnx, nny, n)) continue;
                
                unsafe[nx][ny] = true;
                unsafe[nnx][nny] = true;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long n, m;
    cin >> n >> m;
    
    // Precompute unsafe squares
    markUnsafeSquares(n);
    
    long long ans = 0;
    
    // Count empty squares that are not unsafe
    for (long long i = 0; i < n; ++i) {
        for (long long j = 0; j < n; ++j) {
            if (!unsafe[i][j]) ++ans;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}