#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 4 * 100100;
vector<int> edges[MAX_N];
bool is_wall[MAX_N];
int n, m, q;

void add_edge(int u, int v) {
    edges[u].push_back(v);
    edges[v].push_back(u);
}

void destroy_walls(int r, int c) {
    is_wall[r] = false;
    for (int e : edges[r]) {
        if (is_wall[e]) {
            destroy_walls(e, c);
        }
    }
}

int main() {
    cin >> n >> m >> q;

    for (int i = 1; i <= n; ++i) {
        is_wall[i] = true;
    }

    for (int i = 0; i < q; ++i) {
        int r, c;
        cin >> r >> c;
        if (is_wall[r]) {
            destroy_walls(r, c);
        }
    }

    int remaining_walls = 0;
    for (int i = 1; i <= n; ++i) {
        if (is_wall[i]) {
            remaining_walls += m;
        } else {
            remaining_walls += min(m, is_wall[0]);
        }
    }

    cout << remaining_walls << endl;

    return 0;
}