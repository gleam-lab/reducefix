#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void simulateFlood(int H, int W, vector<vector<int>>& A, vector<vector<bool>>& F, vector<queue<pair<int, int>>>& Q) {
    // Perform the flood simulation
    for (int y = 1; y <= A[0][0]; y++) {
        while (!Q[y].empty()) {
            auto [i, j] = Q[y].front();
            Q[y].pop();
            if (F[i][j]) {
                F[i][j] = false;
                for (int k = 0; k < 4; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if (ni >= 0 && ni < H && nj >= 0 && nj < W && A[ni][nj] > y && F[ni][nj]) {
                        F[ni][nj] = false;
                        Q[max(A[ni][nj], y)].push({ni, nj});
                    }
                }
            }
        }
    }
}

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    vector<vector<bool>> F(H, vector<bool>(W, true));
    vector<queue<pair<int, int>>> Q(202020);
    int dx[] = {-1, 0, 1, 0, -1, -1, 1, 1};
    int dy[] = {0, -1, 0, 1, -1, 1, -1, 1};

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
            if (A[i][j] <= 0) {
                F[i][j] = false; // Water cells are initially flooded
                Q[A[i][j]].push({i, j}); // Push to appropriate queue
            }
        }
    }

    simulateFlood(H, W, A, F, Q);
    ll remainingArea = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (F[i][j]) remainingArea++;
        }
    }

    for (int year = 1; year <= Y; year++) {
        simulateFlood(H, W, A, F, Q);
        cout << remainingArea << endl;
    }

    return 0;
}