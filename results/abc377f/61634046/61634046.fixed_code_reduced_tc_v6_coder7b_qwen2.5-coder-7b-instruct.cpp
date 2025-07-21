#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAXN = 1000005;

ll n, m;
vector<int> row, col, up[2], down[2];

bool exists(vector<int>& vec, int val) {
    return binary_search(vec.begin(), vec.end(), val);
}

int countInRange(vector<int>& vec, int l, int r) {
    auto lb = lower_bound(vec.begin(), vec.end(), l);
    auto ub = upper_bound(vec.begin(), vec.end(), r);
    return ub - lb;
}

void update(vector<int>& vec, int idx) {
    vec.push_back(idx);
    sort(vec.begin(), vec.end());
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x, y; cin >> x >> y;
        row.push_back(x);
        col.push_back(y);
        up[(x + y) & 1].push_back(y - x);
        down[(x + y) & 1].push_back(x + y);
    }

    sort(row.begin(), row.end());
    row.erase(unique(row.begin(), row.end()), row.end());

    sort(col.begin(), col.end());
    col.erase(unique(col.begin(), col.end()), col.end());

    sort(up[0].begin(), up[0].end());
    up[0].erase(unique(up[0].begin(), up[0].end()), up[0].end());

    sort(up[1].begin(), up[1].end());
    up[1].erase(unique(up[1].begin(), up[1].end()), up[1].end());

    sort(down[0].begin(), down[0].end());
    down[0].erase(unique(down[0].begin(), down[0].end()), down[0].end());

    sort(down[1].begin(), down[1].end());
    down[1].erase(unique(down[1].begin(), down[1].end()), down[1].end());

    ll total = n * n;
    ll invalid = 0;

    for (int x : row) {
        invalid += countInRange(up[0], -x, x) + countInRange(up[1], x, 2 * n - x);
    }

    for (int y : col) {
        invalid += countInRange(down[0], -y, y) + countInRange(down[1], y, 2 * n - y);
    }

    for (int x : row) {
        for (int y : col) {
            if (!exists(up[0], y - x) && !exists(up[1], x + y) &&
                !exists(down[0], y - x) && !exists(down[1], x + y)) {
                invalid++;
            }
        }
    }

    cout << total - invalid << endl;
    return 0;
}