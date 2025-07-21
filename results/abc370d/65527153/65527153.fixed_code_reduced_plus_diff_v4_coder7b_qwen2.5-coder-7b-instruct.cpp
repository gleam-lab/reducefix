#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

struct Node {
    set<int> above, below, left, right;
};

vector<Node> nodes;

void addWall(int x, int y) {
    nodes[x].above.insert(y);
    nodes[y].left.insert(x);
}

void removeWall(int x, int y) {
    nodes[x].above.erase(y);
    nodes[y].left.erase(x);
}

int dfsAbove(int x, int y) {
    if (nodes[x].above.empty())
        return x;
    else
        return dfsAbove(*nodes[x].above.begin(), y);
}

int dfsBelow(int x, int y) {
    if (nodes[x].below.empty())
        return x;
    else
        return dfsBelow(*nodes[x].below.rbegin(), y);
}

int dfsLeft(int x, int y) {
    if (nodes[x].left.empty())
        return x;
    else
        return dfsLeft(*nodes[x].left.begin(), y);
}

int dfsRight(int x, int y) {
    if (nodes[x].right.empty())
        return x;
    else
        return dfsRight(*nodes[x].right.rbegin(), y);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int h, w, q;
    cin >> h >> w >> q;

    nodes.resize(h + 1);
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            addWall(i, j);
        }
    }

    for (int i = 0; i < q; ++i) {
        int x, y;
        cin >> x >> y;

        if (!nodes[x].above.count(y)) {
            int u = dfsAbove(x, y);
            int v = dfsBelow(x, y);
            removeWall(u, y);
            removeWall(v, y);
            addWall(u, v);
        } else {
            removeWall(x, y);
        }
    }

    int count = 0;
    for (int i = 1; i <= h; ++i) {
        count += nodes[i].above.size();
    }

    cout << count << endl;

    return 0;
}