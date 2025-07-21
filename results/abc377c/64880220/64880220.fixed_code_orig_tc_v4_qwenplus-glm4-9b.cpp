#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1e9 + 5;
vector<vector<bool>> captured(MAXN, vector<bool>(MAXN, false));

void markCaptured(int a, int b) {
    // Define possible capturing positions
    int dx[] = {-2, -2, -2, -1, -1,  1,  1,  1};
    int dy[] = {-1,  1,  2, -2,  2, -2,  2, -1};

    for (int i = 0; i < 8; ++i) {
        int x = a + dx[i];
        int y = b + dy[i];
        if (x >= 1 && x <= MAXN && y >= 1 && y <= MAXN && captured[x][y]) {
            captured[a][b] = true;
        }
    }
}

int main() {
    long long n, m;
    cin >> n >> m;

    for (long long i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        captured[a][b] = true;
        markCaptured(a, b);
    }

    long long count = 0;
    for (long long i = 1; i <= n; ++i) {
        for (long long j = 1; j <= n; ++j) {
            if (!captured[i][j]) {
                count++;
            }
        }
    }

    cout << count << endl;
    return 0;
}