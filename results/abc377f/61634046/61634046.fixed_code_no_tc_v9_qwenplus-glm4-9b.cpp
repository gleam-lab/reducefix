#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1000 // Maximum number of pieces

int n, m;
int pieces[MAX_N][2]; // Pieces are stored in the form [(row, col)]

bool canPlace(int x, int y, int captureRow, int captureCol, int captureDiag1, int captureDiag2) {
    return x != captureRow && y != captureCol &&
           x + y != captureDiag1 && x - y != captureDiag2;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &pieces[i][0], &pieces[i][1]);
    }

    long long totalEmptySquares = n * n; // Total squares are n*n
    long long validPositionCount = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int rowSum = i, colSum = j, diagSum1 = i + j, diagSum2 = i - j;
            bool isSafe = true;

            for (int k = 0; k < m; k++) {
                int captureRow = pieces[k][0];
                int captureCol = pieces[k][1];

                if (!canPlace(i, j, captureRow, captureCol, diagSum1, diagSum2)) {
                    isSafe = false;
                    break;
                }
            }

            if (isSafe) {
                validPositionCount++;
            }
        }
    }

    cout << validPositionCount << endl;

    return 0;
}