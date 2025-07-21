#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using namespace std;

const int directions[9][2] = {
    {0, 0}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
    {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
};

int N, M;
vector<pair<int, int>> pieces;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    rep(m, M) {
        int a, b;
        cin >> a >> b;
        pieces.emplace_back(a - 1, b - 1);
    }

    // For each cell in the grid, check if it can be placed without being captured by existing pieces
    int free_cells = 0;
    rep(i, N) rep(j, N) {
        bool is_free = true;

        // Check if any existing piece can capture this cell
        for (const auto& p : pieces) {
            int dx = i - p.first;
            int dy = j - p.second;

            bool capture = false;
            for (const auto& dir : directions) {
                int nx = dx + dir[0];
                int ny = dy + dir[1];

                if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                    capture = true;
                    break;
                }
            }

            if (capture) {
                is_free = false;
                break;
            }
        }

        if (is_free) {
            free_cells++;
        }
    }

    cout << free_cells << '\n';

    return 0;
}