#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep2(i, j, n) for(int i = (j); i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define endl '\n'

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    rep(i, H) rep(j, W) cin >> A[i][j];

    // Find the initial number of cells above the sea level
    int aboveSeaLevel = H * W;
    rep(i, H) rep(j, W) {
        if (A[i][j] < H + W - 2) {
            aboveSeaLevel--;
        }
    }

    // Output the initial number of cells above the sea level
    cout << aboveSeaLevel << endl;

    // For each year from the second year to Y
    rep(y, Y - 1) {
        int newDrowned = 0;
        rep(i, H) rep(j, W) {
            // Count how many adjacent cells are below the sea level
            int countBelowSea = 0;
            if (i - 1 >= 0 && A[i - 1][j] < H + W - 2) countBelowSea++;
            if (i + 1 < H && A[i + 1][j] < H + W - 2) countBelowSea++;
            if (j - 1 >= 0 && A[i][j - 1] < H + W - 2) countBelowSea++;
            if (j + 1 < W && A[i][j + 1] < H + W - 2) countBelowSea++;

            // If the cell is below the sea level, it will drown
            if (A[i][j] < H + W - 2) {
                newDrowned++;
                A[i][j] = H + W - 2;
            }

            // If more than one adjacent cells are below the sea level, this cell will also drown
            if (countBelowSea > 1) {
                newDrowned++;
                A[i][j] = H + W - 2;
            }
        }
        aboveSeaLevel -= newDrowned;
        cout << aboveSeaLevel << endl;
    }
}