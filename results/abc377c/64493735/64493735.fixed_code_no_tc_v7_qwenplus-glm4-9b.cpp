#include <iostream>
using namespace std;

int n, m;
int a[200001], b[200001]; // Large enough to store all pieces

bool canPlace(int x, int y) {
    // If any existing piece can capture (x, y), return false
    for (int i = 0; i <= m; ++i) {
        int dx = abs(a[i] - x);
        int dy = abs(b[i] - y);
        // Check if (x, y) is directly in the reach of the piece at (a[i], b[i])
        if (dx == 1 && dy == 2 || dx == 2 && dy == 1) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> a[i] >> b[i];
    }
    
    long long freeSpaces = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (canPlace(i, j)) {
                freeSpaces++;
            }
        }
    }

    cout << freeSpaces << endl;

    return 0;
}