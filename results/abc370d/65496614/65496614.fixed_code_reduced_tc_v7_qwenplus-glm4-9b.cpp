#include <iostream>
#include <set>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using vs = vector<string>;
using pair = pair<int, int>;

const int MAXN = 400005;
vb grid(MAXN, true); // grid[i] means there is a wall at row i

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w, q;
    cin >> h >> w >> q;

    for (int i = 0; i < q; ++i) {
        int r, c;
        cin >> r >> c;
        // Convert 1-based to 0-based
        if (!grid[r - 1]) continue; // If there's no wall at r-1, skip the query

        grid[r - 1] = false; // Remove wall at r-1
        // Remove walls vertically
        for (int j = 0; j < w && grid[r - 1 + j]; ++j) {
            grid[r - 1 + j] = false;
        }
        // Remove walls horizontally
        for (int j = 0; j < h && grid[j + c - 1]; ++j) {
            grid[j + c - 1] = false;
        }
    }

    int remaining_walls = 0;
    for (bool wall : grid) {
        if (wall) remaining_walls++;
    }

    cout << remaining_walls << endl;

    return 0;
}