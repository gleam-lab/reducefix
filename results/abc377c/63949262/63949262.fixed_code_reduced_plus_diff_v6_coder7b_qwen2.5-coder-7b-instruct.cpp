#include <iostream>
#include <vector>
#include <bitset>
#include <cassert>

using namespace std;

const int MAX_N = 1e9;
const int D[] = {2, 1, -1, -2, -2, -1, 1, 2};

bool isValid(int n, int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= n;
}

void markAttackedSquares(int n, vector<bool>& attacked, int x, int y) {
    for (int d = 0; d < 8; ++d) {
        int nx = x + D[d];
        int ny = y + D[(d + 1) % 8];
        if (isValid(n, nx, ny)) {
            attacked[nx * n + ny] = true;
        }
    }
}

int countEmptySquares(int n, int m, vector<int>& a, vector<int>& b) {
    vector<bool> attacked(n * n, false);
    
    for (int i = 0; i < m; ++i) {
        markAttackedSquares(n, attacked, a[i], b[i]);
    }
    
    int emptyCount = 0;
    for (int i = 0; i < n * n; ++i) {
        if (!attacked[i]) {
            emptyCount++;
        }
    }
    
    return emptyCount;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    vector<int> a(m), b(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i] >> b[i];
    }
    
    int result = countEmptySquares(n, m, a, b);
    cout << result << endl;
    
    return 0;
}