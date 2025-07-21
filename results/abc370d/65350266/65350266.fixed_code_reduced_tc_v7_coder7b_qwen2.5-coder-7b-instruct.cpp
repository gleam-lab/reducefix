#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main(void) {
    int h, w, q;
    cin >> h >> w >> q;
    vector<vector<bool>> grid(h, vector<bool>(w, true));
    vector<queue<int>> row_queues(h), col_queues(w);

    rep(i, h) rep(j, w) {
        row_queues[i].push(j);
        col_queues[j].push(i);
    }

    rep(qi, q) {
        int r, c;
        cin >> r >> c;
        r--, c--;

        if (!grid[r][c]) continue;

        grid[r][c] = false;
        
        while (!row_queues[r].empty() && !grid[r][row_queues[r].front()]) {
            row_queues[r].pop();
        }
        if (!row_queues[r].empty()) {
            int next_col = row_queues[r].front();
            col_queues[next_col].push(r);
        }

        while (!col_queues[c].empty() && !grid[col_queues[c].front()][c]) {
            col_queues[c].pop();
        }
        if (!col_queues[c].empty()) {
            int next_row = col_queues[c].front();
            row_queues[next_row].push(c);
        }
    }

    int ans = 0;
    rep(i, h) rep(j, w) {
        if (grid[i][j]) ans++;
    }
    cout << ans << "\n";
    return 0;
}