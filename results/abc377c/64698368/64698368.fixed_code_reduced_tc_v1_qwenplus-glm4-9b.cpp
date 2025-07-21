#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

const int maxN = 1000000000;

int main() {
    int N, M;
   cin >> N >> M;

    vector<vector<int>> forbidden(maxN + 1, vector<int>(maxN + 1, 0));

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;

        vector<pair<int, int>> moves = {
            {0, 0}, {2, 1}, {1, 2}, {-1, 2},
            {-2, 1}, {-2, -1}, {-1, -2}, {1, -2},
            {2, -1}
        };

        for (auto& move : moves) {
            int x = a + move.first;
            int y = b + move.second;
            if (x >= 0 && x < N && y >= 0 && y < N) {
                forbidden[x][y] = 1;
            }
        }
    }

    long long ans = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (forbidden[i][j] == 0) {
                ans++;
            }
        }
    }

    cout << ans;
    return 0;
}