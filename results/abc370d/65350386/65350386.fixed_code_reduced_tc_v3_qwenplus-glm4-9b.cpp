#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 500010;
const int MAXW = 500010;
const int INF = 1e9;

int H, W, Q;
vector<vector<int>> tree_row(MAXN, vector<int>(20, INF));
vector<vector<int>> tree_col(MAXN, vector<int>(20, INF));

void update_row(int r, int c, int val) {
    for (int i = 19; i >= 0; i--) {
        if (tree_row[r][i] > val) {
            tree_row[r][i] = val;
            break;
        }
        r += (1 << i);
    }
}

void update_col(int c, int r, int val) {
    for (int i = 19; i >= 0; i--) {
        if (tree_col[c][i] > val) {
            tree_col[c][i] = val;
            break;
        }
        c += (1 << i);
    }
}

int query_row(int r) {
    int sum = 0;
    for (int i = 19; i >= 0; i--) {
        if (r & (1 << i)) {
            if (tree_row[r][i] < INF) {
                sum += tree_row[r][i];
            }
            r -= (1 << i);
        }
    }
    return sum;
}

int query_col(int c) {
    int sum = 0;
    for (int i = 19; i >= 0; i--) {
        if (c & (1 << i)) {
            if (tree_col[c][i] < INF) {
                sum += tree_col[c][i];
            }
            c -= (1 << i);
        }
    }
    return sum;
}

int main() {
    cin >> H >> W >> Q;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            update_row(i, j, 1);
            update_col(j, i, 1);
        }
    }
    for (int q = 0; q < Q; q++) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        if (query_row(r) > 0 || query_col(c) > 0) {
            // A wall is present, destroy it
            update_row(r, c, 0);
            update_col(c, r, 0);
        } else {
            // No wall initially, find nearest walls in all directions
            // This part would require additional logic to find the nearest walls
            // and update the Segment Trees accordingly
        }
    }
    // Calculate the total number of remaining walls
    long long ans = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            ans += min(query_row(i), query_col(j));
        }
    }
    cout << ans << endl;
    return 0;
}