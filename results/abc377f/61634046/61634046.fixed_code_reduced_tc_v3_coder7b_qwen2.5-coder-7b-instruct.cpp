#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll n, m;

vector<int> rowPos, colPos, upPos[2], downPos[2];

void insert(vector<int>& pos, int val) {
    auto it = lower_bound(pos.begin(), pos.end(), val);
    pos.insert(it, val);
}

bool exists(const vector<int>& pos, int val) {
    return binary_search(pos.begin(), pos.end(), val);
}

ll countInRange(const vector<int>& pos, int l, int r) {
    return upper_bound(pos.begin(), pos.end(), r) - lower_bound(pos.begin(), pos.end(), l);
}

ll solve() {
    // Initialize positions
    rowPos.clear();
    colPos.clear();
    for (int i = 0; i < 2; ++i) {
        upPos[i].clear();
        downPos[i].clear();
    }

    // Insert positions of existing pieces
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        insert(rowPos, y);
        insert(colPos, x);
        int d = (x + y) & 1;
        insert(upPos[d], y - x);
        insert(downPos[d], x + y);
    }

    // Sort positions
    sort(rowPos.begin(), rowPos.end());
    sort(colPos.begin(), colPos.end());
    for (int i = 0; i < 2; ++i) {
        sort(upPos[i].begin(), upPos[i].end());
        sort(downPos[i].begin(), downPos[i].end());
    }

    // Calculate the total number of positions
    ll totalPositions = n * n;

    // Subtract positions occupied by pieces
    totalPositions -= m * (rowPos.size() + colPos.size());

    // Subtract positions that can be captured by rows
    for (int y : rowPos) {
        totalPositions -= m - countInRange(rowPos, y - m, y - 1);
        totalPositions -= m - countInRange(rowPos, y + 1, y + m);
    }

    // Subtract positions that can be captured by columns
    for (int x : colPos) {
        totalPositions -= m - countInRange(colPos, x - m, x - 1);
        totalPositions -= m - countInRange(colPos, x + 1, x + m);
    }

    // Subtract positions that can be captured by diagonals
    for (int i = 0; i < 2; ++i) {
        for (int y : upPos[i]) {
            totalPositions -= m - countInRange(upPos[i], y - m, y - 1);
            totalPositions -= m - countInRange(upPos[i], y + 1, y + m);
        }
        for (int y : downPos[i]) {
            totalPositions -= m - countInRange(downPos[i], y - m, y - 1);
            totalPositions -= m - countInRange(downPos[i], y + 1, y + m);
        }
    }

    return totalPositions;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    cout << solve() << endl;

    return 0;
}