#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAX_N = 1000000000;

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> canCapture(MAX_N + 1, vector<int>(MAX_N + 1, 0));

    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        int r = 1;
        // Check all possible capture positions
        while (x + 2 * r <= N && y + 1 * r <= N && canCapture[x + 2 * r][y + 1 * r] == 0) {
            canCapture[x + 2 * r][y + 1 * r] = 1;
            r++;
        }
        r = 1;
        while (x + 1 * r <= N && y + 2 * r <= N && canCapture[x + 1 * r][y + 2 * r] == 0) {
            canCapture[x + 1 * r][y + 2 * r] = 1;
            r++;
        }
        r = 1;
        while (x - 1 * r >= 1 && y + 2 * r <= N && canCapture[x - 1 * r][y + 2 * r] == 0) {
            canCapture[x - 1 * r][y + 2 * r] = 1;
            r++;
        }
        r = 1;
        while (x - 2 * r >= 1 && y + 1 * r <= N && canCapture[x - 2 * r][y + 1 * r] == 0) {
            canCapture[x - 2 * r][y + 1 * r] = 1;
            r++;
        }
        r = 1;
        while (x - 2 * r >= 1 && y - 1 * r >= 1 && canCapture[x - 2 * r][y - 1 * r] == 0) {
            canCapture[x - 2 * r][y - 1 * r] = 1;
            r++;
        }
        r = 1;
        while (x - 1 * r >= 1 && y - 2 * r >= 1 && canCapture[x - 1 * r][y - 2 * r] == 0) {
            canCapture[x - 1 * r][y - 2 * r] = 1;
            r++;
        }
        r = 1;
        while (x + 1 * r <= N && y - 2 * r >= 1 && canCapture[x + 1 * r][y - 2 * r] == 0) {
            canCapture[x + 1 * r][y - 2 * r] = 1;
            r++;
        }
        r = 1;
        while (x + 2 * r <= N && y - 1 * r >= 1 && canCapture[x + 2 * r][y - 1 * r] == 0) {
            canCapture[x + 2 * r][y - 1 * r] = 1;
            r++;
        }
    }

    // Calculate the number of non-capturable squares
    long long nonCapturable = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (canCapture[i][j] == 0) nonCapturable++;
        }
    }

    cout << nonCapturable << endl;
    return 0;
}