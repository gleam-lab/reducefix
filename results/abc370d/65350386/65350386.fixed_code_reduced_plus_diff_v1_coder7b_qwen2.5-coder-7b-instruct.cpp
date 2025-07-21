#include <bits/stdc++.h>
using namespace std;

struct Node {
    int value;
    int index;
    Node(int v, int i) : value(v), index(i) {}
};

struct CompareNode {
    bool operator()(const Node& a, const Node& b) const {
        if (a.value == b.value) return a.index > b.index;
        return a.value < b.value;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w, q;
    cin >> h >> w >> q;

    vector<vector<bool>> grid(h, vector<bool>(w, true));
    priority_queue<Node, vector<Node>, CompareNode> pq;

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            pq.push({1, i * w + j});
        }
    }

    while (!pq.empty() && q--) {
        int idx = pq.top().index;
        int x = idx / w;
        int y = idx % w;
        pq.pop();

        if (!grid[x][y]) continue;

        grid[x][y] = false;
        --q;

        if (x > 0 && grid[x-1][y]) pq.push({1, (x-1)*w + y});
        if (x < h-1 && grid[x+1][y]) pq.push({1, (x+1)*w + y});
        if (y > 0 && grid[x][y-1]) pq.push({1, x*w + (y-1)});
        if (y < w-1 && grid[x][y+1]) pq.push({1, x*w + (y+1)});
    }

    int count = 0;
    for (auto &row : grid) {
        for (bool val : row) {
            if (val) ++count;
        }
    }

    cout << count << '\n';

    return 0;
}