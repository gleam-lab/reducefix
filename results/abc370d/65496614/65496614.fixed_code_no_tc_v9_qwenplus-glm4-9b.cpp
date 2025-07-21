#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep1(i, n) for (int i = 1; i < (int)(n); ++i)
#define rrep(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define rrep1(i, n) for (int i = (int)(n) - 1; i >= 1; --i)

using ll = long long;

using vi = vector<int>;
using vvi = vector<vector<int>>;
using vb = vector<bool>;

string filename = __FILE__;

//===============================================
// ãããã°ç¨åºåé¢æ°===============================
//===============================================

template<typename T>
void dbg(const T &v, bool linebreak = true) {
    if (filename == "Main.cpp") return;

    for (const T &i : v) {
        cout << i << (linebreak ? "\n" : " ");
    }
    if (linebreak) cout << "\n";
    return;
}

template<typename T>
void dbg(const vector<vector<T>> &a, bool linebreak = true) {
    if (filename == "Main.cpp") return;

    for (const auto &vec : a) {
        for (const T &i : vec) {
            cout << i << (linebreak ? " " : "");
        }
        cout << (linebreak ? "\n" : "");
    }
    return;
}

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;

    vector<vector<bool>> grid(H + 2, vector<bool>(W + 2, true));
    vector<pair<int, int>> queries(Q);

    rep(i, Q) {
        int R, C;
        cin >> R >> C;
        R--;
        C--;
        queries[i] = {R, C};
    }

    // Sort queries to handle rows and columns sequentially
    sort(queries.begin(), queries.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
        return a.first < b.first || (a.first == b.first && a.second < b.second);
    });

    // Directions for bomb explosion
    const vector<pair<int, int>> directions = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

    for (auto &p : queries) {
        int r = p.first;
        int c = p.second;
        if (grid[r][c]) {
            // Wall exists at (r, c)
            grid[r][c] = false;  // Remove the wall
            for (const auto &dir : directions) {
                int nr = r + dir.first;
                int nc = c + dir.second;
                if (grid[nr][nc]) {
                    grid[nr][nc] = false;  // Remove the wall in the direction of explosion
                }
            }
        }
    }

    // Count the number of remaining walls
    int remainingWalls = 0;
    rep(i, H + 1) rep(j, W + 1) {
        if (grid[i][j]) {
            remainingWalls++;
        }
    }

    cout << remainingWalls << endl;
    return 0;
}