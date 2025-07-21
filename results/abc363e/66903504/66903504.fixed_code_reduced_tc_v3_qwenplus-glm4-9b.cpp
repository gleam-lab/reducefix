#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct BIT {
    vector<int> bit;
    int n;
    BIT(int n) : n(n), bit(n + 1, 0) {}

    void add(int idx, int val) {
        for (int i = idx; i <= n; i += i & -i) {
            bit[i] += val;
        }
    }

    int sum(int idx) {
        int s = 0;
        for (int i = idx; i > 0; i -= i & -i) {
            s += bit[i];
        }
        return s;
    }
};

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    vector<vector<bool>> F(H, vector<bool>(W, true));
    BIT bit((H - 2) * (W - 2) + 1);
    int remaining_area = H * W;

    // Read the elevation data
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    // Initialize the BIT and propagation conditions
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                F[i][j] = false;
                if (i > 0 && A[i][j] <= A[i-1][j]) F[i-1][j] = false;
                if (j > 0 && A[i][j] <= A[i][j-1]) F[i][j-1] = false;
                if (i > 0 && j > 0 && A[i][j] <= A[i-1][j-1]) F[i-1][j-1] = false;
            }
        }
    }

    // Propagate the sinking effect
    for (int year = 1; year <= Y; ++year) {
        queue<pair<int, int>> q;
        for (int i = 1; i < H - 1; ++i) {
            for (int j = 1; j < W - 1; ++j) {
                if (!F[i][j]) {
                    q.push({i * (W - 2) + j, 1});
                }
            }
        }

        while (!q.empty()) {
            auto [idx, val] = q.front();
            q.pop();
            remaining_area -= bit.sum(idx + val);
            bit.add(idx, val);
            if (i > 0 && A[i][j] <= A[i-1][j]) q.push({(i-1) * (W - 2) + j, val + 1});
            if (j > 0 && A[i][j] <= A[i][j-1]) q.push({i * (W - 2) + j-1, val + 1});
            if (i > 0 && j > 0 && A[i][j] <= A[i-1][j-1]) q.push({(i-1) * (W - 2) + j-1, val + 1});
        }

        cout << remaining_area << endl;
    }

    return 0;
}