#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main(void) {
    int h, w, q;
    cin >> h >> w >> q;
    vector<vector<bool>> grid(h, vector<bool>(w, true));
    vector<queue<int>> colQueues(w);
    vector<queue<int>> rowQueues(h);

    rep(i, h) rep(j, w) {
        if (grid[i][j]) {
            colQueues[j].push(i);
            rowQueues[i].push(j);
        }
    }

    rep(qi, q) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        if (!grid[r][c]) continue;

        grid[r][c] = false;
        colQueues[c].pop();
        rowQueues[r].pop();

        while (!colQueues[c].empty() && !grid[colQueues[c].front()][c]) {
            colQueues[c].pop();
        }

        while (!rowQueues[r].empty() && !grid[r][rowQueues[r].front()]) {
            rowQueues[r].pop();
        }

        if (!colQueues[c].empty()) {
            rowQueues[colQueues[c].front()].push(r);
        }

        if (!rowQueues[r].empty()) {
            colQueues[rowQueues[r].front()].push(c);
        }
    }

    int ans = 0;
    rep(i, w) {
        ans += colQueues[i].size();
    }
    cout << ans << "\n";
    return 0;
}