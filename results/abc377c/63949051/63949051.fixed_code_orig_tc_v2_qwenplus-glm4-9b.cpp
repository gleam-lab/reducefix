#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> A(N + 1, vector<int>(N + 1, 0));

    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        // Mark the squares that are blocked by the piece at (x, y)
        A[x][y] = 1;
        if (x + 2 <= N && y + 1 <= N) A[x + 2][y + 1] = 1;
        if (x + 1 <= N && y + 2 <= N) A[x + 1][y + 2] = 1;
        if (x - 1 >= 1 && y + 2 <= N) A[x - 1][y + 2] = 1;
        if (x - 2 >= 1 && y + 1 <= N) A[x - 2][y + 1] = 1;
        if (x - 2 >= 1 && y - 1 >= 1) A[x - 2][y - 1] = 1;
        if (x - 1 >= 1 && y - 2 >= 1) A[x - 1][y - 2] = 1;
        if (x + 1 <= N && y - 2 >= 1) A[x + 1][y - 2] = 1;
        if (x + 2 <= N && y - 1 >= 1) A[x + 2][y - 1] = 1;
    }

    // Calculate the number of available squares
    int count = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (A[i][j] == 0) count++;
        }
    }

    cout << count << endl;
    return 0;
}