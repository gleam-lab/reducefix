#include <bits/stdc++.h>
using namespace std;

const int MAXN = 4e5 + 5;

struct Node {
    set<int> xs, ys;
    Node(int x, int y) : xs({x}), ys({y}) {}
};

vector<Node> nodes(MAXN);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int H, W, Q;
    cin >> H >> W >> Q;
    
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            nodes[i * W + j] = Node(i, j);
        }
    }

    auto destroy = [&](int r, int c) {
        if (!nodes[r * W + c].xs.empty()) {
            nodes[*nodes[r * W + c].xs.rbegin()].ys.erase(r);
            nodes[*nodes[r * W + c].ys.rbegin()].xs.erase(c);
            nodes[r * W + c].xs.clear();
            nodes[r * W + c].ys.clear();
        } else {
            auto x_it = nodes[r * W + c].ys.lower_bound(r);
            if (x_it != nodes[r * W + c].ys.begin()) {
                --x_it;
                int prev_x = *x_it;
                nodes[prev_x * W + c].ys.erase(prev_x);
                nodes[r * W + c].ys.erase(r);
                nodes[prev_x * W + c].xs.erase(c);
                nodes[r * W + c].xs.erase(c);
            }
            if (x_it != nodes[r * W + c].ys.end()) {
                int next_x = *x_it;
                nodes[next_x * W + c].ys.erase(next_x);
                nodes[r * W + c].ys.erase(r);
                nodes[next_x * W + c].xs.erase(c);
                nodes[r * W + c].xs.erase(c);
            }

            auto y_it = nodes[r * W + c].xs.lower_bound(c);
            if (y_it != nodes[r * W + c].xs.begin()) {
                --y_it;
                int prev_y = *y_it;
                nodes[r * W + prev_y].ys.erase(r);
                nodes[r * W + c].xs.erase(c);
                nodes[r * W + prev_y].xs.erase(prev_y);
                nodes[r * W + c].ys.erase(r);
            }
            if (y_it != nodes[r * W + c].xs.end()) {
                int next_y = *y_it;
                nodes[r * W + next_y].ys.erase(r);
                nodes[r * W + c].xs.erase(c);
                nodes[r * W + next_y].xs.erase(next_y);
                nodes[r * W + c].ys.erase(r);
            }
        }
    };

    while (Q--) {
        int r, c;
        cin >> r >> c;
        --r, --c;
        destroy(r, c);
    }

    int ans = 0;
    for (int i = 0; i < H; ++i) {
        ans += nodes[i * W + c].xs.size() + nodes[i * W + c].ys.size();
    }
    cout << ans << '\n';

    return 0;
}