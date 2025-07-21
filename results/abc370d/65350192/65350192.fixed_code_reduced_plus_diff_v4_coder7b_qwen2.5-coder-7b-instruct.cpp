#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val, id;
};

bool operator<(const Node &a, const Node &b) {
    return a.val > b.val || (a.val == b.val && a.id < b.id);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int h, w, q;
    cin >> h >> w >> q;

    vector<set<Node>> rows(h), cols(w);

    for (int i = 0; i < h; ++i)
        for (int j = 0; j < w; ++j)
            rows[i].insert({1, i * w + j});

    for (int i = 0; i < w; ++i)
        for (int j = 0; j < h; ++j)
            cols[i].insert({1, i * h + j});

    while (q--) {
        int x, y;
        cin >> x >> y;
        --x, --y;

        int idx = *rows[x].rbegin().id / w, jdx = *cols[y].rbegin().id % w;

        if (idx == x && jdx == y) {
            rows[x].erase(rows[x].rbegin());
            cols[y].erase(cols[y].rbegin());
        } else if (idx == x) {
            cols[y].erase(cols[y].rbegin());
        } else if (jdx == y) {
            rows[x].erase(rows[x].rbegin());
        }

        if (idx != x) {
            int prevIdx = idx;
            while (!rows[idx].empty() && rows[idx].rbegin()->val == 1) {
                cols[rows[idx].rbegin()->id % w].erase(rows[idx].rbegin());
                rows[idx].erase(rows[idx].rbegin());
            }
            if (!rows[idx].empty())
                rows[idx].rbegin()->val = 0;
            if (!rows[prevIdx].empty())
                rows[prevIdx].rbegin()->val = 1;
        }

        if (jdx != y) {
            int prevJdx = jdx;
            while (!cols[jdx].empty() && cols[jdx].rbegin()->val == 1) {
                rows[cols[jdx].rbegin()->id / w].erase(cols[jdx].rbegin());
                cols[jdx].erase(cols[jdx].rbegin());
            }
            if (!cols[jdx].empty())
                cols[jdx].rbegin()->val = 0;
            if (!cols[prevJdx].empty())
                cols[prevJdx].rbegin()->val = 1;
        }
    }

    int res = 0;
    for (auto &row : rows)
        res += row.size();

    for (auto &col : cols)
        res += col.size();

    cout << res << '\n';

    return 0;
}