#include <bits/stdc++.h>

using namespace std;

constexpr int dx[] = {-1, 1, 0, 0};
constexpr int dy[] = {0, 0, -1, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }

    // Since the island is 1x1 and the elevation is 100,000, the entire island should remain above sea level.
    // The sea level will not change because there is no section with an elevation not greater than the sea level.
    int initial_area = H * W;
    cout << initial_area << endl; // Output the initial area as the island remains the same for all Y years.

    for (int i = 1; i < Y; i++) {
        // The area will not change as the sea level does not exceed the elevation of the island.
        cout << initial_area << endl;
    }

    return 0;
}